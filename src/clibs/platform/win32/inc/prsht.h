#ifndef _PRSHT_H
#define _PRSHT_H

#ifdef __ORANGEC__ 
#pragma once
#endif

/* Windows Property Sheet definitions */

#ifndef _WINRESRC_H
#ifndef _WIN32_IE
#define _WIN32_IE 0x0501
#else
#if (_WIN32_IE < 0x0400) && defined(_WIN32_WINNT) && (_WIN32_WINNT >= 0x0500)
#error _WIN32_IE setting conflicts with _WIN32_WINNT setting
#endif
#endif /* _WIN32_IE */
#endif /* _WINRESRC_H */

#ifndef WINCOMMCTRLAPI
#define WINCOMMCTRLAPI DECLSPEC_IMPORT
#endif

#ifndef DUMMYUNIONNAME
#ifdef NONAMELESSUNION
#define DUMMYUNIONNAME   u
#define DUMMYUNIONNAME2  u2
#define DUMMYUNIONNAME3  u3
#define DUMMYUNIONNAME4  u4
#define DUMMYUNIONNAME5  u5
#else
#define DUMMYUNIONNAME
#define DUMMYUNIONNAME2
#define DUMMYUNIONNAME3
#define DUMMYUNIONNAME4
#define DUMMYUNIONNAME5
#endif
#endif /* DUMMYUNIONNAME */

#ifdef _WIN64
#include <pshpack8.h>
#else
#include <pshpack4.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif


#ifndef SNDMSG
#ifdef __cplusplus
#define SNDMSG ::SendMessage
#else
#define SNDMSG SendMessage
#endif
#endif /* SNDMSG */

#ifndef PSTMSG
#ifdef __cplusplus
#define PSTMSG ::PostMessage
#else
#define PSTMSG PostMessage
#endif
#endif /* PSTMSG */

#define MAXPROPPAGES  100

#define PSP_DEFAULT  0x00000000
#define PSP_DLGINDIRECT  0x00000001
#define PSP_USEHICON  0x00000002
#define PSP_USEICONID  0x00000004
#define PSP_USETITLE  0x00000008
#define PSP_RTLREADING  0x00000010
#define PSP_HASHELP  0x00000020
#define PSP_USEREFPARENT  0x00000040
#define PSP_USECALLBACK  0x00000080
#define PSP_PREMATURE  0x00000400
#if (_WIN32_IE >= 0x0400)
#define PSP_HIDEHEADER  0x00000800
#define PSP_USEHEADERTITLE  0x00001000
#define PSP_USEHEADERSUBTITLE  0x00002000
#endif
#if (_WIN32_WINNT >= 0x0501) || ISOLATION_AWARE_ENABLED
#define PSP_USEFUSIONCONTEXT  0x00004000
#endif

#define PSH_DEFAULT  0x00000000
#define PSH_PROPTITLE  0x00000001
#define PSH_USEHICON  0x00000002
#define PSH_USEICONID  0x00000004
#define PSH_PROPSHEETPAGE  0x00000008
#define PSH_WIZARDHASFINISH  0x00000010
#define PSH_WIZARD  0x00000020
#define PSH_USEPSTARTPAGE  0x00000040
#define PSH_NOAPPLYNOW  0x00000080
#define PSH_USECALLBACK  0x00000100
#define PSH_HASHELP  0x00000200
#define PSH_MODELESS  0x00000400
#define PSH_RTLREADING  0x00000800
#define PSH_WIZARDCONTEXTHELP  0x00001000

#if (_WIN32_IE >= 0x0400)
#if (_WIN32_IE < 0x0500)
#define PSH_WIZARD97  0x00002000
#else
#define PSH_WIZARD97  0x01000000
#endif
#define PSH_WATERMARK  0x00008000
#define PSH_USEHBMWATERMARK  0x00010000
#define PSH_USEHPLWATERMARK  0x00020000
#define PSH_STRETCHWATERMARK  0x00040000
#define PSH_HEADER  0x00080000
#define PSH_USEHBMHEADER  0x00100000
#define PSH_USEPAGELANG  0x00200000
#endif

#if (_WIN32_IE >= 0x0500)
#define PSH_WIZARD_LITE  0x00400000
#define PSH_NOCONTEXTHELP  0x02000000
#endif

#if (_WIN32_WINNT >= 0x0600)
#define PSH_AEROWIZARD  0x00004000
#define PSH_RESIZABLE  0x04000000
#define PSH_HEADERBITMAP  0x08000000
#define PSH_NOMARGIN  0x10000000
#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_IE >= 0x0500)
#define PSPCB_ADDREF  0
#endif
#define PSPCB_RELEASE  1
#define PSPCB_CREATE  2

#define PSCB_INITIALIZED  1
#define PSCB_PRECREATE  2

#if (_WIN32_IE >= 0x560)
#define PSCB_BUTTONPRESSED  3
#endif

#define PSN_FIRST  (0U-200U)
#define PSN_LAST  (0U-299U)

#define PSN_SETACTIVE  (PSN_FIRST-0)
#define PSN_KILLACTIVE  (PSN_FIRST-1)
#define PSN_APPLY  (PSN_FIRST-2)
#define PSN_RESET  (PSN_FIRST-3)
#define PSN_HELP  (PSN_FIRST-5)
#define PSN_WIZBACK  (PSN_FIRST-6)
#define PSN_WIZNEXT  (PSN_FIRST-7)
#define PSN_WIZFINISH  (PSN_FIRST-8)
#define PSN_QUERYCANCEL  (PSN_FIRST-9)
#if (_WIN32_IE >= 0x0400)
#define PSN_GETOBJECT  (PSN_FIRST-10)
#endif
#if (_WIN32_IE >= 0x0500)
#define PSN_TRANSLATEACCELERATOR  (PSN_FIRST-12)
#define PSN_QUERYINITIALFOCUS  (PSN_FIRST-13)
#endif

#define PSNRET_NOERROR  0
#define PSNRET_INVALID  1
#define PSNRET_INVALID_NOCHANGEPAGE  2
#define PSNRET_MESSAGEHANDLED  3

#define PSM_SETCURSEL  (WM_USER+101)
#define PSM_REMOVEPAGE  (WM_USER+102)
#define PSM_ADDPAGE  (WM_USER+103)
#define PSM_CHANGED  (WM_USER+104)
#define PSM_RESTARTWINDOWS  (WM_USER+105)
#define PSM_REBOOTSYSTEM  (WM_USER+106)
#define PSM_CANCELTOCLOSE  (WM_USER+107)
#define PSM_QUERYSIBLINGS  (WM_USER+108)
#define PSM_UNCHANGED  (WM_USER+109)
#define PSM_APPLY  (WM_USER+110)
#define PSM_SETTITLEA  (WM_USER+111)
#define PSM_SETTITLEW  (WM_USER+120)
#define PSM_SETWIZBUTTONS  (WM_USER+112)
#define PSM_PRESSBUTTON  (WM_USER+113)
#define PSM_SETCURSELID  (WM_USER+114)
#define PSM_SETFINISHTEXTA  (WM_USER+115)
#define PSM_SETFINISHTEXTW  (WM_USER+121)
#define PSM_GETTABCONTROL  (WM_USER+116)
#define PSM_ISDIALOGMESSAGE  (WM_USER+117)
#define PSM_GETCURRENTPAGEHWND  (WM_USER+118)
#define PSM_INSERTPAGE  (WM_USER+119)
#if (_WIN32_IE >= 0x0500)
#define PSM_SETHEADERTITLEA  (WM_USER+125)
#define PSM_SETHEADERTITLEW  (WM_USER+126)
#define PSM_SETHEADERSUBTITLEA  (WM_USER+127)
#define PSM_SETHEADERSUBTITLEW  (WM_USER+128)
#define PSM_HWNDTOINDEX  (WM_USER+129)
#define PSM_INDEXTOHWND  (WM_USER+130)
#define PSM_PAGETOINDEX  (WM_USER+131)
#define PSM_INDEXTOPAGE  (WM_USER+132)
#define PSM_IDTOINDEX  (WM_USER+133)
#define PSM_INDEXTOID  (WM_USER+134)
#define PSM_GETRESULT  (WM_USER+135)
#define PSM_RECALCPAGESIZES  (WM_USER+136)
#endif /* _WIN32_IE >= 0x0500 */

#if (_WIN32_WINNT >= 0x0600)
#define PSM_SETNEXTTEXTW  (WM_USER+137)
#define PSM_SETNEXTTEXT  PSM_SETNEXTTEXTW
#define PSM_SHOWWIZBUTTONS  (WM_USER+138)
#define PSM_ENABLEWIZBUTTONS  (WM_USER+139)
#define PSM_SETBUTTONTEXTW  (WM_USER+140)
#define PSM_SETBUTTONTEXT  PSM_SETBUTTONTEXTW
#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0600)
#define PSWIZB_SHOW  0
#define PSWIZB_RESTORE  1
#endif /* _WIN32_WINNT >= 0x0600 */

#define PSWIZB_BACK  0x00000001
#define PSWIZB_NEXT  0x00000002
#define PSWIZB_FINISH  0x00000004
#define PSWIZB_DISABLEDFINISH  0x00000008
#if (_WIN32_WINNT >= 0x0600)
#define PSWIZB_CANCEL  0x00000010
#endif /* _WIN32_WINNT >= 0x0600 */

#define PSWIZBF_ELEVATIONREQUIRED  0x00000001

#if (_WIN32_WINNT >= 0x0600)
#define PSWIZF_SETCOLOR  ((UINT)(-1))
#endif /* _WIN32_WINNT >= 0x0600 */

#define PSBTN_BACK  0
#define PSBTN_NEXT  1
#define PSBTN_FINISH  2
#define PSBTN_OK  3
#define PSBTN_APPLYNOW  4
#define PSBTN_CANCEL  5
#define PSBTN_HELP  6
#define PSBTN_MAX  6

#define ID_PSRESTARTWINDOWS  0x2
#define ID_PSREBOOTSYSTEM  (ID_PSRESTARTWINDOWS|0x1)

#define WIZ_CXDLG  276
#define WIZ_CYDLG  140

#define WIZ_CXBMP  80

#define WIZ_BODYX  92
#define WIZ_BODYCX  184

#define PROP_SM_CXDLG  212
#define PROP_SM_CYDLG  188

#define PROP_MED_CXDLG  227
#define PROP_MED_CYDLG  215

#define PROP_LG_CXDLG  252
#define PROP_LG_CYDLG  218

struct _PSP;
typedef struct _PSP *HPROPSHEETPAGE;

struct _PROPSHEETPAGEA;
struct _PROPSHEETPAGEW;

typedef UINT (CALLBACK *LPFNPSPCALLBACKA)(HWND,UINT,struct _PROPSHEETPAGEA*);
typedef UINT (CALLBACK *LPFNPSPCALLBACKW)(HWND,UINT,struct _PROPSHEETPAGEW*);

#define PROPSHEETPAGEA_V1_SIZE sizeof(PROPSHEETPAGEA_V1)
#define PROPSHEETPAGEW_V1_SIZE sizeof(PROPSHEETPAGEW_V1)

#define PROPSHEETPAGEA_V2_SIZE sizeof(PROPSHEETPAGEA_V2)
#define PROPSHEETPAGEW_V2_SIZE sizeof(PROPSHEETPAGEW_V2)

#define PROPSHEETPAGEA_V3_SIZE sizeof(PROPSHEETPAGEA_V3)
#define PROPSHEETPAGEW_V3_SIZE sizeof(PROPSHEETPAGEW_V3)

#if (_WIN32_WINNT >= 0x0600)
#define PROPSHEETPAGEA_V4_SIZE sizeof(PROPSHEETPAGEA_V4)
#define PROPSHEETPAGEW_V4_SIZE sizeof(PROPSHEETPAGEW_V4)
#endif /* _WIN32_WINNT >= 0x0600 */

#define PROPSHEETPAGEA_V1_FIELDS \
    DWORD dwSize; \
    DWORD dwFlags; \
    HINSTANCE hInstance; \
    union { \
        LPCSTR pszTemplate; \
        PROPSHEETPAGE_RESOURCE pResource; \
    } DUMMYUNIONNAME; \
    union { \
        HICON hIcon; \
        LPCSTR pszIcon; \
    } DUMMYUNIONNAME2; \
    LPCSTR pszTitle; \
    DLGPROC pfnDlgProc; \
    LPARAM lParam; \
    LPFNPSPCALLBACKA pfnCallback; \
    UINT *pcRefParent; \

#define PROPSHEETPAGEW_V1_FIELDS \
    DWORD dwSize; \
    DWORD dwFlags; \
    HINSTANCE hInstance; \
    union { \
        LPCWSTR pszTemplate; \
        PROPSHEETPAGE_RESOURCE pResource; \
    } DUMMYUNIONNAME; \
    union { \
        HICON hIcon; \
        LPCWSTR pszIcon; \
    } DUMMYUNIONNAME2; \
    LPCWSTR pszTitle; \
    DLGPROC pfnDlgProc; \
    LPARAM lParam; \
    LPFNPSPCALLBACKW pfnCallback; \
    UINT *pcRefParent; \

#if (_WIN32_WINNT >= 0x0600)
#define _PROPSHEETPAGEA_V4 _PROPSHEETPAGEA
#define _PROPSHEETPAGEW_V4 _PROPSHEETPAGEW
#elif (_WIN32_WINNT >= 0x0501) || ISOLATION_AWARE_ENABLED
#define _PROPSHEETPAGEA_V3 _PROPSHEETPAGEA
#define _PROPSHEETPAGEW_V3 _PROPSHEETPAGEW
#elif (_WIN32_IE >= 0x0400)
#define _PROPSHEETPAGEA_V2 _PROPSHEETPAGEA
#define _PROPSHEETPAGEW_V2 _PROPSHEETPAGEW
#else
#define _PROPSHEETPAGEA_V1 _PROPSHEETPAGEA
#define _PROPSHEETPAGEW_V1 _PROPSHEETPAGEW
#endif

typedef LPCDLGTEMPLATE PROPSHEETPAGE_RESOURCE;

typedef struct _PROPSHEETPAGEA_V1 {
    PROPSHEETPAGEA_V1_FIELDS
} PROPSHEETPAGEA_V1, *LPPROPSHEETPAGEA_V1;
typedef const PROPSHEETPAGEA_V1 *LPCPROPSHEETPAGEA_V1;

typedef struct _PROPSHEETPAGEA_V2 {
    PROPSHEETPAGEA_V1_FIELDS
    LPCSTR pszHeaderTitle;
    LPCSTR pszHeaderSubTitle;
} PROPSHEETPAGEA_V2, *LPPROPSHEETPAGEA_V2;
typedef const PROPSHEETPAGEA_V2 *LPCPROPSHEETPAGEA_V2;

typedef struct _PROPSHEETPAGEA_V3 {
    PROPSHEETPAGEA_V1_FIELDS
    LPCSTR pszHeaderTitle;
    LPCSTR pszHeaderSubTitle;
    HANDLE hActCtx;
} PROPSHEETPAGEA_V3, *LPPROPSHEETPAGEA_V3;
typedef const PROPSHEETPAGEA_V3 *LPCPROPSHEETPAGEA_V3;

#if (_WIN32_WINNT >= 0x0600)
typedef struct _PROPSHEETPAGEA_V4 {
    PROPSHEETPAGEA_V1_FIELDS
    LPCSTR pszHeaderTitle;
    LPCSTR pszHeaderSubTitle;
    HANDLE hActCtx;
    union {
        HBITMAP hbmHeader;
        LPCSTR pszbmHeader;
    } DUMMYUNIONNAME3;
} PROPSHEETPAGEA_V4, *LPPROPSHEETPAGEA_V4;
typedef const PROPSHEETPAGEA_V4 *LPCPROPSHEETPAGEA_V4;
#endif /* _WIN32_WINNT >= 0x0600 */

typedef struct _PROPSHEETPAGEW_V1 {
    PROPSHEETPAGEW_V1_FIELDS
} PROPSHEETPAGEW_V1, *LPPROPSHEETPAGEW_V1;
typedef const PROPSHEETPAGEW_V1 *LPCPROPSHEETPAGEW_V1;

typedef struct _PROPSHEETPAGEW_V2 {
    PROPSHEETPAGEW_V1_FIELDS
    LPCWSTR pszHeaderTitle;
    LPCWSTR pszHeaderSubTitle;
} PROPSHEETPAGEW_V2, *LPPROPSHEETPAGEW_V2;
typedef const PROPSHEETPAGEW_V2 *LPCPROPSHEETPAGEW_V2;

typedef struct _PROPSHEETPAGEW_V3 {
    PROPSHEETPAGEW_V1_FIELDS
    LPCWSTR pszHeaderTitle;
    LPCWSTR pszHeaderSubTitle;
    HANDLE hActCtx;
} PROPSHEETPAGEW_V3, *LPPROPSHEETPAGEW_V3;
typedef const PROPSHEETPAGEW_V3 *LPCPROPSHEETPAGEW_V3;

#if (_WIN32_WINNT >= 0x0600)
typedef struct _PROPSHEETPAGEW_V4 {
    PROPSHEETPAGEW_V1_FIELDS
    LPCWSTR pszHeaderTitle;
    LPCWSTR pszHeaderSubTitle;
    HANDLE hActCtx;
    union {
        HBITMAP hbmHeader;
        LPCWSTR pszbmHeader;
    } DUMMYUNIONNAME3;
} PROPSHEETPAGEW_V4, *LPPROPSHEETPAGEW_V4;
typedef const PROPSHEETPAGEW_V4 *LPCPROPSHEETPAGEW_V4;
#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0600)
typedef PROPSHEETPAGEA_V4    PROPSHEETPAGEA_LATEST;
typedef PROPSHEETPAGEW_V4    PROPSHEETPAGEW_LATEST;
typedef LPPROPSHEETPAGEA_V4  LPPROPSHEETPAGEA_LATEST;
typedef LPPROPSHEETPAGEW_V4  LPPROPSHEETPAGEW_LATEST;
typedef LPCPROPSHEETPAGEA_V4 LPCPROPSHEETPAGEA_LATEST;
typedef LPCPROPSHEETPAGEW_V4 LPCPROPSHEETPAGEW_LATEST;
#else
typedef PROPSHEETPAGEA_V3 PROPSHEETPAGEA_LATEST;
typedef PROPSHEETPAGEW_V3 PROPSHEETPAGEW_LATEST;
typedef LPPROPSHEETPAGEA_V3 LPPROPSHEETPAGEA_LATEST;
typedef LPPROPSHEETPAGEW_V3 LPPROPSHEETPAGEW_LATEST;
typedef LPCPROPSHEETPAGEA_V3 LPCPROPSHEETPAGEA_LATEST;
typedef LPCPROPSHEETPAGEW_V3 LPCPROPSHEETPAGEW_LATEST;
#endif /* _WIN32_WINNT >= 0x0600 */

#if (_WIN32_WINNT >= 0x0600)
typedef PROPSHEETPAGEA_V4 PROPSHEETPAGEA;
typedef PROPSHEETPAGEW_V4 PROPSHEETPAGEW;
typedef LPPROPSHEETPAGEA_V4 LPPROPSHEETPAGEA;
typedef LPPROPSHEETPAGEW_V4 LPPROPSHEETPAGEW;
typedef LPCPROPSHEETPAGEA_V4 LPCPROPSHEETPAGEA;
typedef LPCPROPSHEETPAGEW_V4 LPCPROPSHEETPAGEW;
#elif (_WIN32_WINNT >= 0x0501) || ISOLATION_AWARE_ENABLED
typedef PROPSHEETPAGEA_V3 PROPSHEETPAGEA;
typedef PROPSHEETPAGEW_V3 PROPSHEETPAGEW;
typedef LPPROPSHEETPAGEA_V3 LPPROPSHEETPAGEA;
typedef LPPROPSHEETPAGEW_V3 LPPROPSHEETPAGEW;
typedef LPCPROPSHEETPAGEA_V3 LPCPROPSHEETPAGEA;
typedef LPCPROPSHEETPAGEW_V3 LPCPROPSHEETPAGEW;
#elif (_WIN32_IE >= 0x0400)
typedef PROPSHEETPAGEA_V2 PROPSHEETPAGEA;
typedef PROPSHEETPAGEW_V2 PROPSHEETPAGEW;
typedef LPPROPSHEETPAGEA_V2 LPPROPSHEETPAGEA;
typedef LPPROPSHEETPAGEW_V2 LPPROPSHEETPAGEW;
typedef LPCPROPSHEETPAGEA_V2 LPCPROPSHEETPAGEA;
typedef LPCPROPSHEETPAGEW_V2 LPCPROPSHEETPAGEW;
#else
typedef PROPSHEETPAGEA_V1 PROPSHEETPAGEA;
typedef PROPSHEETPAGEW_V1 PROPSHEETPAGEW;
typedef LPPROPSHEETPAGEA_V1 LPPROPSHEETPAGEA;
typedef LPPROPSHEETPAGEW_V1 LPPROPSHEETPAGEW;
typedef LPCPROPSHEETPAGEA_V1 LPCPROPSHEETPAGEA;
typedef LPCPROPSHEETPAGEW_V1 LPCPROPSHEETPAGEW;
#endif

typedef int (CALLBACK *PFNPROPSHEETCALLBACK)(HWND, UINT, LPARAM);

#define PROPSHEETHEADERA_V1_SIZE sizeof(PROPSHEETHEADERA_V1)
#define PROPSHEETHEADERW_V1_SIZE sizeof(PROPSHEETHEADERW_V1)

#if (_WIN32_IE >= 0x400)
#define PROPSHEETHEADERA_V2_SIZE sizeof(PROPSHEETHEADERA_V2)
#define PROPSHEETHEADERW_V2_SIZE sizeof(PROPSHEETHEADERW_V2)
#endif /* _WIN32_IE >= 0x400 */

#define _PROPSHEETHEADERA_FIELDS \
    DWORD dwSize; \
    DWORD dwFlags; \
    HWND hwndParent; \
    HINSTANCE hInstance; \
    union { \
        HICON hIcon; \
        LPCSTR pszIcon; \
    } DUMMYUNIONNAME; \
    LPCSTR pszCaption; \
    UINT nPages; \
    union { \
        UINT nStartPage; \
        LPCSTR pStartPage; \
    } DUMMYUNIONNAME2; \
    union { \
        LPCPROPSHEETPAGEA ppsp; \
        HPROPSHEETPAGE *phpage; \
    } DUMMYUNIONNAME3; \
    PFNPROPSHEETCALLBACK pfnCallback;

typedef struct _PROPSHEETHEADERA_V1 {
    _PROPSHEETHEADERA_FIELDS
} PROPSHEETHEADERA_V1, *LPPROPSHEETHEADERA_V1;
typedef struct _PROPSHEETHEADERA_V2 {
    _PROPSHEETHEADERA_FIELDS
    union {
        HBITMAP hbmWatermark;
        LPCSTR pszbmWatermark;
    } DUMMYUNIONNAME4;
    HPALETTE hplWatermark;
    union {
        HBITMAP hbmHeader;
        LPCSTR pszbmHeader;
    } DUMMYUNIONNAME5;
} PROPSHEETHEADERA_V2, *LPPROPSHEETHEADERA_V2;

#if (_WIN32_IE >= 0x0400)
#define PROPSHEETHEADERA PROPSHEETHEADERA_V2
#define LPPROPSHEETHEADERA LPPROPSHEETHEADERA_V2
#else
#define PROPSHEETHEADERA PROPSHEETHEADERA_V1
#define LPPROPSHEETHEADERA LPPROPSHEETHEADERA_V1
#endif /* _WIN32_IE >= 0x0400 */

typedef const PROPSHEETHEADERA *LPCPROPSHEETHEADERA;

#define _PROPSHEETHEADERW_FIELDS \
    DWORD dwSize; \
    DWORD dwFlags; \
    HWND hwndParent; \
    HINSTANCE hInstance; \
    union { \
        HICON hIcon; \
        LPCWSTR pszIcon; \
    } DUMMYUNIONNAME; \
    LPCWSTR pszCaption; \
    UINT nPages; \
    union { \
        UINT nStartPage; \
        LPCWSTR pStartPage; \
    } DUMMYUNIONNAME2; \
    union { \
        LPCPROPSHEETPAGEW ppsp; \
        HPROPSHEETPAGE *phpage; \
    } DUMMYUNIONNAME3; \
    PFNPROPSHEETCALLBACK pfnCallback;

typedef struct _PROPSHEETHEADERW_V1 {
    _PROPSHEETHEADERW_FIELDS
} PROPSHEETHEADERW_V1, *LPPROPSHEETHEADERW_V1;
typedef struct _PROPSHEETHEADERW_V2 {
    _PROPSHEETHEADERW_FIELDS
    union {
        HBITMAP hbmWatermark;
        LPCWSTR pszbmWatermark;
    } DUMMYUNIONNAME4;
    HPALETTE hplWatermark;
    union {
        HBITMAP hbmHeader;
        LPCWSTR pszbmHeader;
    } DUMMYUNIONNAME5;
} PROPSHEETHEADERW_V2, *LPPROPSHEETHEADERW_V2;

#if (_WIN32_IE >= 0x0400)
#define PROPSHEETHEADERW PROPSHEETHEADERW_V2
#define LPPROPSHEETHEADERW LPPROPSHEETHEADERW_V2
#else
#define PROPSHEETHEADERW PROPSHEETHEADERW_V1
#define LPPROPSHEETHEADERW LPPROPSHEETHEADERW_V1
#endif /* _WIN32_IE >= 0x0400 */

typedef const PROPSHEETHEADERW *LPCPROPSHEETHEADERW;

typedef BOOL (CALLBACK *LPFNADDPROPSHEETPAGE)(HPROPSHEETPAGE, LPARAM);
typedef BOOL (CALLBACK *LPFNADDPROPSHEETPAGES)(LPVOID, LPFNADDPROPSHEETPAGE, LPARAM);

typedef struct _PSHNOTIFY {
    NMHDR hdr;
    LPARAM lParam;
} PSHNOTIFY, *LPPSHNOTIFY;

WINCOMMCTRLAPI HPROPSHEETPAGE WINAPI CreatePropertySheetPageA(LPCPROPSHEETPAGEA);
WINCOMMCTRLAPI HPROPSHEETPAGE WINAPI CreatePropertySheetPageW(LPCPROPSHEETPAGEW);
WINCOMMCTRLAPI BOOL WINAPI DestroyPropertySheetPage(HPROPSHEETPAGE);
WINCOMMCTRLAPI INT_PTR WINAPI PropertySheetA(LPCPROPSHEETHEADERA);
WINCOMMCTRLAPI INT_PTR WINAPI PropertySheetW(LPCPROPSHEETHEADERW);

#define PropSheet_SetCurSel(hDlg,hpage,index)  SNDMSG((hDlg),PSM_SETCURSEL,(WPARAM)(index),(LPARAM)(hpage))
#define PropSheet_RemovePage(hDlg,index,hpage)  SNDMSG((hDlg),PSM_REMOVEPAGE,(index),(LPARAM)(hpage))
#define PropSheet_AddPage(hDlg,hpage)  SNDMSG((hDlg),PSM_ADDPAGE,0,(LPARAM)(hpage))
#define PropSheet_Changed(hDlg,hwnd)  SNDMSG((hDlg),PSM_CHANGED,(WPARAM)(hwnd),0L)
#define PropSheet_RestartWindows(hDlg)  SNDMSG((hDlg),PSM_RESTARTWINDOWS,0,0L)
#define PropSheet_RebootSystem(hDlg)  SNDMSG((hDlg),PSM_REBOOTSYSTEM,0,0L)
#define PropSheet_CancelToClose(hDlg)  PostMessage((hDlg),PSM_CANCELTOCLOSE,0,0L)
#define PropSheet_QuerySiblings(hDlg,wParam,lParam)  SNDMSG((hDlg),PSM_QUERYSIBLINGS,(wParam),(lParam))
#define PropSheet_UnChanged(hDlg,hwnd)  SNDMSG((hDlg),PSM_UNCHANGED,(WPARAM)(hwnd),0L)
#define PropSheet_Apply(hDlg)  SNDMSG((hDlg),PSM_APPLY,0,0L)
#define PropSheet_SetTitle(hDlg,wStyle,lpszText)  SNDMSG((hDlg),PSM_SETTITLE,(wStyle),(LPARAM)(LPCTSTR)(lpszText))
#define PropSheet_SetWizButtons(hDlg,dwFlags)  PostMessage((hDlg),PSM_SETWIZBUTTONS,0,(LPARAM)(dwFlags))
#define PropSheet_PressButton(hDlg,iButton)  PostMessage((hDlg),PSM_PRESSBUTTON,(WPARAM)(iButton),0)
#define PropSheet_SetCurSelByID(hDlg,id)  SNDMSG((hDlg),PSM_SETCURSELID,0,(LPARAM)(id))
#define PropSheet_SetFinishText(hDlg,lpszText)  SNDMSG((hDlg),PSM_SETFINISHTEXT,0,(LPARAM)(lpszText))
#define PropSheet_GetTabControl(hDlg)  (HWND)SNDMSG((hDlg),PSM_GETTABCONTROL,0,0L)
#define PropSheet_IsDialogMessage(hDlg,pMsg)  (BOOL)SNDMSG((hDlg),PSM_ISDIALOGMESSAGE,0,(LPARAM)(pMsg))
#define PropSheet_GetCurrentPageHwnd(hDlg)  (HWND)SNDMSG((hDlg),PSM_GETCURRENTPAGEHWND,0,0L)
#define PropSheet_InsertPage(hDlg,index,hpage)  SNDMSG((hDlg),PSM_INSERTPAGE,(WPARAM)(index),(LPARAM)(hpage))
#if (_WIN32_IE >= 0x0500)
#define PropSheet_SetHeaderTitle(hDlg,index,lpszText)  SNDMSG((hDlg),PSM_SETHEADERTITLE,(WPARAM)(index),(LPARAM)(lpszText))
#define PropSheet_SetHeaderSubTitle(hDlg,index,lpszText)  SNDMSG((hDlg),PSM_SETHEADERSUBTITLE,(WPARAM)(index),(LPARAM)(lpszText))
#define PropSheet_HwndToIndex(hDlg,hwnd)  (int)SNDMSG((hDlg),PSM_HWNDTOINDEX,(WPARAM)(hwnd),0L)
#define PropSheet_IndexToHwnd(hDlg,i)  (HWND)SNDMSG((hDlg),PSM_INDEXTOHWND,(WPARAM)(i),0L)
#define PropSheet_PageToIndex(hDlg,hpage)  (int)SNDMSG((hDlg),PSM_PAGETOINDEX,0,(LPARAM)(hpage))
#define PropSheet_IndexToPage(hDlg,i)  (HPROPSHEETPAGE)SNDMSG((hDlg),PSM_INDEXTOPAGE,(WPARAM)(i),0L)
#define PropSheet_IdToIndex(hDlg,id)  (int)SNDMSG((hDlg),PSM_IDTOINDEX,0,(LPARAM)(id))
#define PropSheet_IndexToId(hDlg,i)  SNDMSG((hDlg),PSM_INDEXTOID,(WPARAM)(i),0L)
#define PropSheet_GetResult(hDlg)  SNDMSG((hDlg),PSM_GETRESULT,0,0L)
#define PropSheet_RecalcPageSizes(hDlg)  SNDMSG((hDlg),PSM_RECALCPAGESIZES,0,0L)
#endif /* _WIN32_IE >= 0x0500 */
#if (_WIN32_WINNT >= 0x0600)
#define PropSheet_SetNextText(hDlg,lpszText)  SNDMSG(hDlg,PSM_SETNEXTTEXT,0,(LPARAM)(lpszText))
#define PropSheet_ShowWizButtons(hDlg,dwFlag,dwButton)  PSTMSG(hDlg,PSM_SHOWWIZBUTTONS,(WPARAM)(dwFlag),(LPARAM)(dwButton))
#define PropSheet_EnableWizButtons(hDlg,dwState,dwMask)  PSTMSG(hDlg,PSM_ENABLEWIZBUTTONS,(WPARAM)(dwState),(LPARAM)(dwMask))
#define PropSheet_SetButtonText(hDlg,dwButton,lpszText)  SNDMSG(hDlg,PSM_SETBUTTONTEXT,(WPARAM)(dwButton),(LPARAM)(lpszText))
#endif /* _WIN32_WINNT >= 0x0600 */

#ifdef UNICODE
#define LPFNPSPCALLBACK  LPFNPSPCALLBACKW
#define PROPSHEETHEADER  PROPSHEETHEADERW
#define LPPROPSHEETHEADER  LPPROPSHEETHEADERW
#define LPCPROPSHEETHEADER  LPCPROPSHEETHEADERW
#define PROPSHEETHEADER_V1_SIZE  PROPSHEETHEADERW_V1_SIZE
#define PROPSHEETHEADER_V2_SIZE  PROPSHEETHEADERW_V2_SIZE
#define PROPSHEETPAGE  PROPSHEETPAGEW
#define LPPROPSHEETPAGE  LPPROPSHEETPAGEW
#define LPCPROPSHEETPAGE  LPCPROPSHEETPAGEW
#define PROPSHEETPAGE_V1_SIZE  PROPSHEETPAGEW_V1_SIZE
#define PROPSHEETPAGE_V2_SIZE  PROPSHEETPAGEW_V2_SIZE
#define PROPSHEETPAGE_V1  PROPSHEETPAGEW_V1
#define LPPROPSHEETPAGE_V1  LPPROPSHEETPAGEW_V1
#define LPCPROPSHEETPAGE_V1  LPCPROPSHEETPAGEW_V1
#define PROPSHEETPAGE_V2  PROPSHEETPAGEW_V2
#define LPPROPSHEETPAGE_V2  LPPROPSHEETPAGEW_V2
#define LPCPROPSHEETPAGE_V2  LPCPROPSHEETPAGEW_V2
#define PROPSHEETPAGE_V3  PROPSHEETPAGEW_V3
#define LPPROPSHEETPAGE_V3  LPPROPSHEETPAGEW_V3
#define LPCPROPSHEETPAGE_V3  LPCPROPSHEETPAGEW_V3
#if (_WIN32_WINNT >= 0x0600)
#define PROPSHEETPAGE_V4  PROPSHEETPAGEW_V4
#define LPPROPSHEETPAGE_V4  LPPROPSHEETPAGEW_V4
#define LPCPROPSHEETPAGE_V4  LPCPROPSHEETPAGEW_V4
#endif /* _WIN32_WINNT >= 0x0600 */
#define PROPSHEETPAGE_LATEST  PROPSHEETPAGEW_LATEST
#define LPPROPSHEETPAGE_LATEST  LPPROPSHEETPAGEW_LATEST
#define LPCPROPSHEETPAGE_LATEST  LPCPROPSHEETPAGEW_LATEST
#define CreatePropertySheetPage  CreatePropertySheetPageW
#define PropertySheet  PropertySheetW
#define PSM_SETTITLE  PSM_SETTITLEW
#define PSM_SETFINISHTEXT  PSM_SETFINISHTEXTW
#define PSM_SETHEADERTITLE  PSM_SETHEADERTITLEW
#define PSM_SETHEADERSUBTITLE  PSM_SETHEADERSUBTITLEW
#else /* UNICODE */
#define LPFNPSPCALLBACK  LPFNPSPCALLBACKA
#define PROPSHEETHEADER  PROPSHEETHEADERA
#define LPPROPSHEETHEADER  LPPROPSHEETHEADERA
#define LPCPROPSHEETHEADER  LPCPROPSHEETHEADERA
#define PROPSHEETHEADER_V1_SIZE  PROPSHEETHEADERA_V1_SIZE
#define PROPSHEETHEADER_V2_SIZE  PROPSHEETHEADERA_V2_SIZE
#define PROPSHEETPAGE  PROPSHEETPAGEA
#define LPPROPSHEETPAGE  LPPROPSHEETPAGEA
#define LPCPROPSHEETPAGE  LPCPROPSHEETPAGEA
#define PROPSHEETPAGE_V1_SIZE  PROPSHEETPAGEA_V1_SIZE
#define PROPSHEETPAGE_V2_SIZE  PROPSHEETPAGEA_V2_SIZE
#define PROPSHEETPAGE_V1  PROPSHEETPAGEA_V1
#define LPPROPSHEETPAGE_V1  LPPROPSHEETPAGEA_V1
#define LPCPROPSHEETPAGE_V1  LPCPROPSHEETPAGEA_V1
#define PROPSHEETPAGE_V2  PROPSHEETPAGEA_V2
#define LPPROPSHEETPAGE_V2  LPPROPSHEETPAGEA_V2
#define LPCPROPSHEETPAGE_V2  LPCPROPSHEETPAGEA_V2
#define PROPSHEETPAGE_V3  PROPSHEETPAGEA_V3
#define LPPROPSHEETPAGE_V3  LPPROPSHEETPAGEA_V3
#define LPCPROPSHEETPAGE_V3  LPCPROPSHEETPAGEA_V3
#if (_WIN32_WINNT >= 0x0600)
#define PROPSHEETPAGE_V4  PROPSHEETPAGEA_V4
#define LPPROPSHEETPAGE_V4  LPPROPSHEETPAGEA_V4
#define LPCPROPSHEETPAGE_V4  LPCPROPSHEETPAGEA_V4
#endif /* _WIN32_WINNT >= 0x0600 */
#define PROPSHEETPAGE_LATEST  PROPSHEETPAGEA_LATEST
#define LPPROPSHEETPAGE_LATEST  LPPROPSHEETPAGEA_LATEST
#define LPCPROPSHEETPAGE_LATEST  LPCPROPSHEETPAGEA_LATEST
#define CreatePropertySheetPage  CreatePropertySheetPageA
#define PropertySheet  PropertySheetA
#define PSM_SETTITLE  PSM_SETTITLEA
#define PSM_SETFINISHTEXT  PSM_SETFINISHTEXTA
#define PSM_SETHEADERTITLE  PSM_SETHEADERTITLEA
#define PSM_SETHEADERSUBTITLE  PSM_SETHEADERSUBTITLEA
#endif /* UNICODE */

#if defined(ISOLATION_AWARE_ENABLED) && (ISOLATION_AWARE_ENABLED != 0)
#error Isolation aware inline functions not supported
/* #include "prsht.inl" */
#endif /* ISOLATION_AWARE_ENABLED */


#ifdef __cplusplus
}
#endif

#include <poppack.h>

#endif /* _PRSHT_H */
