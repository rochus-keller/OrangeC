#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
#include <errno.h>
#include <wchar.h>
#include <locale.h>
#include <threads.h>
#include <sys\timeb.h>
#include <threads.h>
#include <stdlib.h>
#include "libp.h"

#define TSS_SIG 0x5353545e  //"_TSS"

struct itss
{
    int sig;
    void* value;
    tss_dtor_t dtor;
    char deleted;
};
static int insert_tss(tss_t key)
{
    struct ithrd* t = (struct ithrd*)__getRtlData()->thrd_id;
    if (t)  // main thread doesn't get TSS
    {
        struct itsslst* p = calloc(1, sizeof(struct itsslst));
        if (p)
        {
            struct ithrd* t = (struct ithrd*)__getRtlData()->thrd_id;
            p->tss = (void*)key;
            __ll_enter_critical();
            p->next = t->tsslst;
            t->tsslst = p;
            __ll_exit_critical();
            return thrd_success;
        }
        return thrd_nomem;
    }
    return thrd_error;
}
void __tss_run_dtors(thrd_t thrd)
{
    struct ithrd* p = (struct ithrd*)thrd;
    struct itsslst* q = p->tsslst;
    for (int i = 0; q && i < TSS_DTOR_ITERATIONS; i++)
    {
        struct itsslst* next = q->next;
        struct itss* key = (struct itss*)q->tss;
        if (key->dtor && !key->deleted)
            (*key->dtor)(key->value);
        q = next;
        if (!q)
            q = p->tsslst;
    }
    while (q)
    {
        struct itsslst* next = q->next;
        free(q->tss);
        free(q);
        q = next;
    }
}
int _RTL_FUNC tss_create(tss_t* key, tss_dtor_t dtor)
{
    struct itss* ikey = calloc(1, sizeof(struct itss));
    if (ikey)
    {
        int rv = insert_tss((tss_t)ikey);
        if (rv == thrd_success)
        {
            ikey->sig = TSS_SIG;
            ikey->dtor = dtor;
            *key = (tss_t)ikey;
            return thrd_success;
        }
        free(ikey);
        return rv;
    }
    return thrd_nomem;
}
void _RTL_FUNC tss_delete(tss_t key)
{
    struct itss* p = (struct itss*)key;
    if (p->sig == TSS_SIG)
    {
        p->deleted = 1;
    }
}
void* _RTL_FUNC tss_get(tss_t key)
{
    struct itss* p = (struct itss*)key;
    if (p->sig == TSS_SIG && !p->deleted)
    {
        return p->value;
    }
    return NULL;
}
int _RTL_FUNC tss_set(tss_t key, void* val)
{
    struct itss* p = (struct itss*)key;
    if (p->sig == TSS_SIG && !p->deleted)
    {
        p->value = val;
        return thrd_success;
    }
    return thrd_error;
}
