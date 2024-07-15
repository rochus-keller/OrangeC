/* Software License Agreement
 *
 *     Copyright(C) 1994-2023 David Lindauer, (LADSoft)
 *
 *     This file is part of the Orange C Compiler package.
 *
 *     The Orange C Compiler package is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     The Orange C Compiler package is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with Orange C.  If not, see <http://www.gnu.org/licenses/>.
 *
 *     contact information:
 *         email: TouchStone222@runbox.com <David Lindauer>
 *
 */

#include <cstdio>
#include <malloc.h>
#include <cstring>
#include <climits>
#include "ioptimizer.h"
#include "beinterfdefs.h"
#include "ildata.h"
#include "../occ/winmode.h"
#include "../occ/be.h"
#include "Utils.h"
#include "SharedMemory.h"
#include <deque>
#include <unordered_map>
#include <map>
#include <set>
#include <iostream>
#include <assert.h>
#include "ildata.h"

namespace Optimizer
{
FunctionData* myfd;
static std::list<std::string> textRegion;
static std::unordered_map<std::string, int> cachedText;
static size_t textOffset;
static std::map<IMODE*, int> cachedImodes;
static std::set<SimpleSymbol*> cachedAutos;
static std::set<SimpleSymbol*> cachedTemps;

static std::ostream* stream = 0;
static inline std::ostream& out() { return *stream; }
static int level = 0;
static inline void ws() {
    for( int i = 0; i < level; i++ )
        out() << ' ';
}

static const char* datatype[] = {
    "NONE",
    "SEG",
    "SEGEXIT",
    "DEFINITION",
    "LABELDEFINITION",
    "RESERVE",
    "SYM",
    "SRREF",
    "PCREF",
    "FUNCREF",
    "LABEL",
    "LABDIFFREF",
    "FUNC",
    "STRING",
    "BIT",
    "BOOL",
    "BYTE",
    "USHORT",
    "UINT",
    "ULONG",
    "ULONGLONG",
    "16",
    "32",
    "ENUM",
    "FLOAT",
    "DOUBLE",
    "LDOUBLE",
    "CFLOAT",
    "CDOUBLE",
    "CLONGDOUBLE",
    "ADDRESS",
    "VIRTUAL",
    "ENDVIRTUAL",
    "ALIGN",
    "VTT",
    "IMPORTTHUNK",
    "VC1",
    "AUTOREF"
};

// the next are intended not to be reset on each read, as there will be another file streamed next
static int outputPos;
static int outputSize;
static unsigned char* streamPointer;

void resize(int) {}

inline static void StreamBlockType(int blockType, bool end)
{
    // TODO
}
inline static void StreamIndex(int value)
{
    out() << "IDX " << value;
}
inline static void StreamTextIndex(const char* name)
{
    out() << "\"" << name << "\"";
}
inline static void StreamString(const std::string& value)
{
    out() << "STR \"" << value << "\"";
}
static void StreamStringList(const std::list<std::string>& list)
{
    for (auto&& s : list)
        StreamString(s);
}

template <class T>
inline static void StreamIntValue(T i, int s)
{
    out() << "INT " << i;
}
static void StreamFloatValue(FPF& fv)
{
    out() << "FLOAT " << (std::string)fv;
}
static void StreamSymbol(SimpleSymbol* sym);
static void StreamSymbolTable(LIST* syms)
{
    // TODO
}
static void StreamBases(BaseList* bases)
{
    BaseList* baseClasses;
    int i = 0;
    for (auto l = bases; l; l = l->next, i++)
        ;
    for (auto l = bases; l; l = l->next)
    {
        out() << "BASE " << l->sym->name;
    }
}
static void StreamType(SimpleType* type)
{
    out() << "TYPE ";
    if (!type)
    {
        out() << "none";
    }
    else
    {
        switch(type->type)
        {
        case st_none:
            out() << "none"; break;
        case st_i:
            out() << "i"; break;
        case st_ui:
            out() << "ui"; break;
        case st_f:
            out() << "f"; break;
        case st_fi:
            out() << "fi"; break;
        case st_fc:
            out() << "fc"; break;
        case st_pointer:
            out() << "pointer"; break;
        case st_void:
            out() << "void"; break;
        case st___string:
            out() << "_string"; break;
        case st___object:
            out() << "_object"; break;
        case st_func:
            out() << "func"; break;
        case st_lref:
            out() << "lref"; break;
        case st_rref:
            out() << "rref"; break;
        case st_struct:
            out() << "struct"; break;
        case st_union:
            out() << "union"; break;
        case st_class:
            out() << "class"; break;
        case st_enum:
            out() << "enum"; break;
        case st_memberptr:
            out() << "memberptr"; break;
        case st_aggregate:
            out() << "aggregate"; break;
        case st_ellipse:
            out() << "ellipse"; break;
        case st_any:
            out() << "any"; break;
        default:
            assert(false);
        }

        out() << " size: " << type->size;
#if 0
        if (type->sp && type->type != st_any)
        {

            if (type->sp->storage_class == scc_auto || type->sp->storage_class == scc_register)
            {
                StreamIndex(type->sp->fileIndex | 0x20000000);
            }
            else if (type->sp->typeIndex)
                StreamIndex(0x40000000 | type->sp->typeIndex);
            else
                StreamIndex(type->sp->fileIndex);
        }
        StreamIndex(type->flags);
        StreamType(type->btp);
        StreamType(type->structuredAlias);
#endif
    }
}
static void StreamSymbol(SimpleSymbol* sym)
{
    out() << "SYM ";
    if (!sym)
    {
        StreamIndex(scc_none);
    }
    else
    {
        switch(sym->storage_class)
        {
        case scc_none:
            out() << "none";
            break;
        case scc_static:
            out() << "static";
            break;
        case scc_localstatic:
            out() << "localstatic";
            break;
        case scc_auto:
            out() << "auto";
            break;
        case scc_register:
            out() << "auto";
            break;
        case scc_global:
            out() << "global";
            break;
        case scc_external:
            out() << "global";
            break;
        case scc_templateparam:
            out() << "templateparam";
            break;
        case scc_parameter:
            out() << "parameter";
            break;
        case scc_catchvar:
            out() << "catchvar";
            break;
        case scc_type:
            out() << "type";
            break;
        case scc_typedef:
            out() << "typedef";
            break;
        case scc_member:
            out() << "member";
            break;
        case scc_mutable:
            out() << "mutable";
            break;
        case scc_cast:
            out() << "cast";
            break;
        case scc_defunc:
            out() << "defunc";
            break;
        case scc_label:
            out() << "label";
            break;
        case scc_ulabel:
            out() << "ulabel";
            break;
        case scc_overloads:
            out() << "overloads";
            break;
        case scc_constant:
            out() << "constant";
            break;
        case scc_enumconstant:
            out() << "enumconstant";
            break;
        case scc_absolute:
            out() << "absolute";
            break;
        case scc_friendlist:
            out() << "friendlist";
            break;
        case scc_const:
            out() << "const";
            break;
        case scc_tconst:
            out() << "tconst";
            break;
        case scc_classmember:
            out() << "classmember";
            break;
        case scc_constexpr:
            out() << "constexpr";
            break;
        case scc_memberreg:
            out() << "memberreg";
            break;
        case scc_namespace:
            out() << "namespace";
            break;
        case scc_namespacealias:
            out() << "namespacealias";
            break;
        case scc_temp:
            out() << "temp";
            break;
        case scc_virtual:
            out() << "virtual";
            break;
        default:
            assert(false);
        }

        out() << " ID \""<< sym->name << "\" ";
#if 0
        StreamTextIndex(sym->outputName);
        StreamTextIndex(sym->importfile);
        StreamTextIndex(sym->namespaceName);
        StreamTextIndex(sym->msil);
        StreamIndex(sym->i);
        StreamIndex(sym->regmode);
        StreamIntValue(sym->offset, 4);
        StreamIndex(sym->label);
        StreamIndex(sym->templateLevel);
        StreamIntValue(sym->flags, 8);
        StreamIntValue(sym->sizeFromType, sizeof(int));
        StreamIndex(sym->align);
        StreamIndex(sym->size);
        if (sym->parentClass)
            StreamIndex(sym->parentClass->fileIndex);
        else
            StreamIndex(0);
#endif
        if( sym->tp )
            StreamType(sym->tp);
        if( sym->syms )
            StreamSymbolTable(sym->syms);
        if( sym->baseClasses )
            StreamBases(sym->baseClasses);
    }
    StreamBlockType(STT_SYMBOL, true);
}
static void StreamExpression(SimpleExpression* exp)
{
    out() << "EXPR ";
    if (!exp)
    {
        out() << "none";
    }
    else
    {
        switch(exp->type)
        {
        case se_none:
            out() << "none";
            break;
        case se_add:
            out() << "add";
            break;
        case se_sub:
            out() << "sub";
            break;
        case se_uminus:
            out() << "uminus";
            break;
        case se_i:
            out() << "i";
            break;
        case se_ui:
            out() << "ui";
            break;
        case se_f:
            out() << "f";
            break;
        case se_fi:
            out() << "fi";
            break;
        case se_fc:
            out() << "fc";
            break;
        case se_const:
            out() << "const";
            break;
        case se_absolute:
            out() << "absolute";
            break;
        case se_auto:
            out() << "auto";
            break;
        case se_global:
            out() << "global";
            break;
        case se_threadlocal:
            out() << "threadloca";
            break;
        case se_pc:
            out() << "pc";
            break;
        case se_labcon:
            out() << "labcon";
            break;
        case se_structelem:
            out() << "structelem";
            break;
        case se_func:
            out() << "func";
            break;
        case se_tempref:
            out() << "tempref";
            break;
        case se_msil_array_init:
            out() << "msil_array_init";
            break;
        case se_msil_array_access:
            out() << "msil_array_access";
            break;
        case se_string:
            out() << "string";
            break;
        case se_typeref:
            out() << "typeref";
            break;
        }

        //StreamIndex(exp->flags);
        //StreamIntValue(exp->sizeFromType, sizeof(int));
        switch (exp->type)
        {
        case Optimizer::se_i:
        case Optimizer::se_ui:
            StreamIntValue(exp->i, 8);
            break;
        case Optimizer::se_f:
        case Optimizer::se_fi:
            StreamFloatValue(exp->f);
            break;
        case Optimizer::se_fc:
            StreamFloatValue(exp->c.r);
            StreamFloatValue(exp->c.i);
            break;
        case Optimizer::se_auto:
#if 0
            if (exp->sp->storage_class == scc_localstatic)
            {
                StreamIndex(exp->sp->fileIndex | 0x40000000);
                break;
            }
        case Optimizer::se_const:
        case Optimizer::se_absolute:
        case Optimizer::se_global:
        case Optimizer::se_threadlocal:
        case Optimizer::se_pc:
        case Optimizer::se_structelem:
            StreamIndex(exp->sp->fileIndex);
            break;
        case Optimizer::se_labcon:
            StreamIndex(exp->i);
            break;
        case Optimizer::se_tempref:
            StreamIndex(exp->sp->i);
            StreamIndex(exp->sp->tp->size);
            StreamIndex(exp->sp->tp->sizeFromType);
#endif
            break;
        case Optimizer::se_msil_array_access:
            StreamType(exp->msilArrayTP);
            break;
        case Optimizer::se_typeref:
            StreamType(exp->tp);
            break;
        case Optimizer::se_msil_array_init:
            StreamType(exp->tp);
            break;
        case Optimizer::se_string:
            out() << "\"" << std::string(exp->astring.str,exp->astring.len) << "\"";
            break;
        }
        if( exp->left )
        {
            out() << std::endl;
            level++; ws(); out() << "LHS: ";
            StreamExpression(exp->left);
            level--;
        }
#if 0
        if (exp->type == Optimizer::se_tempref)
        {
            SimpleSymbol* sp = ((SimpleSymbol*)exp->right);
            int n = 0;
            if (sp)
            {
                n = sp->fileIndex;
                if (sp->storage_class != scc_auto && sp->storage_class != scc_register && sp->storage_class != scc_parameter)
                    n |= 0x40000000;
            }
            StreamIndex(n);
        }
        else
#endif
            if( exp->right )
            {
                out() << std::endl;
                level++; ws(); out() << "RHS: ";
                StreamExpression(exp->right);
                level--;
            }
        if( exp->altData )
        {
            out() << std::endl;
            level++; ws(); out() << "ALT: ";
            StreamExpression(exp->altData);
            level--;
        }
    }
}
static void StreamBrowseFile(BROWSEFILE* bf)
{
    out() << "BROWSEFILE ";
    out() << bf->name;
    //StreamIndex(bf->filenum);
}
static void StreamBrowseInfo(BROWSEINFO* bi)
{
    out() << "BROWSEINFO ";
    out() << bi->name;
#if 0
    StreamIndex(bi->filenum);
    StreamIndex(bi->type);
    StreamIndex(bi->lineno);
    StreamIndex(bi->charpos);
    StreamIndex(bi->flags);
#endif
}

static void StreamAssemblyOperand(AMODE* im)
{
#ifndef ORANGE_NO_INASM
    if (!im)
    {
        StreamIndex(am_none);
    }
    else
    {
        StreamIndex(im->mode);
        StreamIndex(im->preg);
        StreamIndex(im->sreg);
        StreamIndex(im->tempflag);
        StreamIndex(im->scale);
        StreamIndex(im->length);
        StreamIndex(im->addrlen);
        StreamIndex(im->seg);
        StreamIntValue(im->liveRegs, 8);
        StreamIndex(im->keepesp);
        StreamExpression(im->offset);
    }
#else
    out() << "assembly operand unsupported";
#endif
}
static void StreamAssemblyInstruction(OCODE* oc)
{
#ifndef ORANGE_NO_INASM
    StreamIndex(oc->opcode);
    StreamIndex(oc->diag);
    StreamIndex(oc->noopt);
    StreamIndex(oc->size);
    StreamIndex(oc->blocknum);
    StreamAssemblyOperand(oc->oper1);
    StreamAssemblyOperand(oc->oper2);
    StreamAssemblyOperand(oc->oper3);
#else
    out() << "assembly instruction unsupported";
#endif
}
static void StreamOperand(IMODE* im)
{
    out() << "OP ";
    switch(im->mode)
    {
    case i_none:
        break;
    case i_immed:
        break;
    case i_direct:
        break;
    case i_ind:
        break;
    case i_rret:
        break;
    default:
        assert(false);
    }
#if 0
    StreamIndex(im->scale);
    StreamIndex(im->useindx);
    StreamIndex(im->size);
    StreamIndex(im->ptrsize);
    StreamIndex(im->startbit);
    StreamIndex(im->bits);
    StreamIndex(im->seg);
    StreamIndex(im->flags);
#endif
    if( im->offset )
    {
        level++; out() << std::endl;
        ws(); out() << "OFF1: ";
        StreamExpression(im->offset);
        level--;
    }
    if( im->offset2 )
    {
        level++; out() << std::endl;
        ws(); out() << "OFF2: ";
        StreamExpression(im->offset2);
        level--;
    }
    if( im->offset3 )
    {
        level++; out() << std::endl;
        ws(); out() << "OFF3: ";
        StreamExpression(im->offset3);
        level--;
    }
    if (im->mode == i_ind && im->offset && im->offset->type == Optimizer::se_tempref)
    {
        level++; out() << std::endl;
        ws();
        StreamType(im->offset->sp->tp);
        level--;
    }
    if( im->vararg )
    {
        level++; out() << std::endl;
        ws(); out() << "VARARG: ";
        StreamExpression(im->vararg);
        level--;
    }
}

static const char* opnames[] = {
    "nop", "phi", "line", "passthrough", "datapassthrough", "skipcompare",
    "label", "asmgoto", "goto", "computedgoto",
    "gosub", "fargosub", "trap", "int", "ret",
    "fret", "rett", "add", "sub", "udiv", "umod", "sdiv", "smod", "muluh", "mulsh", "mul",
    "lsl", "lsr", "asr", "neg", "not", "and", "or", "eor",
    "setne", "sete", "setc", "seta", "setnc", "setbe", "setl", "setg", "setle", "setge",
    "asmcond", "jne", "je", "jc", "ja", "jnc", "jbe", "jl", "jg", "jle", "jge",
    "assn", "genword", "coswitch", "swbranch", "assnblock", "clrblock", "cmpblock", "parmadj", "parmblock", "parm",
    "array", "arrayindex", "arraylsh", "struct", "cppini", "block", "blockend",
    "dbgblock", "dbgblockend", "varstart", "func", "livein", "icon", "fcon", "imcon", "cxcon",
    "atomic_flag_test_and_set", "atomic_flag_clear",
    "atomic_thread_fence", "atomic_signal_fence", "atomic_flag_fence", "cmpxchgweak", "cmpxchgstrong",
    "kill_dependency", "xchg",
    "prologue", "epilogue", "beginexcept", "endexcept", "pushcontext", "popcontext", "loadcontext", "unloadcontext",
    "tryblock", "substack", "parmstack", "loadstack", "savestack", "functailstart", "functailend",
    "gcsestub", "expressiontag", "tag", "seh",
    "_initblk", "_cpblk", "_initobj", "_sizeof",
    "var", "const", "ptr", "labcon",
    "endoflist"
};

static void StreamInstruction(QUAD* q)
{
    out() << opnames[q->dc.opcode] << " ";

    if (q->dc.opcode == i_passthrough)
    {
        //StreamAssemblyInstruction((OCODE*)q->dc.left);
    }
    else
    {
        int i;
        switch (q->dc.opcode)
        {
        case i_icon:
            StreamIntValue(q->dc.v.i, 8);
            break;
        case i_imcon:
        case i_fcon:
            StreamFloatValue(q->dc.v.f);
            break;
        case i_cxcon:
            StreamFloatValue(q->dc.v.c.r);
            StreamFloatValue(q->dc.v.c.i);
            break;
        case i_label:
        case i_expressiontag:
            out() << "LBL " <<  q->dc.v.label;
            break;
        case i_line:
            if (q->dc.left != nullptr)
            {
                auto v = (LINEDATA*)q->dc.left;
                // StreamIndex(v->fileindex);
                out() << v->lineno << " ";
                StreamTextIndex(v->line);
            }
            break;
        case i_block:
            out() << q->block->blocknum;
            break;
        case i_blockend:
            out() << q->block->blocknum;
            break;
        case i_dbgblock:
        case i_dbgblockend:
        case i_livein:
            break;
        case i_func:
            out() << "LBL " << q->dc.v.label;
            //if (q->dc.left)
            //    StreamIndex(cachedImodes[q->dc.left]);
            break;
        case i_jc:
        case i_jnc:
        case i_jbe:
        case i_ja:
        case i_je:
        case i_jne:
        case i_jge:
        case i_jg:
        case i_jle:
        case i_jl:
        case i_swbranch:
        case i_coswitch:
        case i_goto:
        case i_cmpblock:
            out() << "LBL " << q->dc.v.label;
            // fallthrough
        default:
#if 0
            if (q->dc.left)
                StreamIndex(cachedImodes[q->dc.left]);
            else
                StreamIndex(0);
            if (q->dc.right)
                StreamIndex(cachedImodes[q->dc.right]);
            else
                StreamIndex(0);
#endif
            break;
        }
#if 0
        if (q->ans)
            StreamIndex(cachedImodes[q->ans]);
        if (q->altsp)
        {
            if (q->altsp->storage_class == scc_auto ||
                    (q->altsp->storage_class == scc_parameter && q->altsp->fileIndex != q->altsp->typeIndex) ||
                    q->altsp->storage_class == scc_register)
                StreamIndex(q->altsp->fileIndex | 0x20000000);
            else if (q->altsp->fileIndex == q->altsp->typeIndex)
                StreamIndex(q->altsp->typeIndex | 0x40000000);
            else
                StreamIndex(q->altsp->fileIndex);
        }
        if (q->runtimeData)
        {
            StreamIndex(reinterpret_cast<SimpleSymbol*>(q->runtimeData->runtimeSym)->fileIndex);
            StreamTextIndex(q->runtimeData->fileName);
            StreamTextIndex(q->runtimeData->varName);
            StreamIndex(q->runtimeData->lineno);
            StreamIndex(q->runtimeData->asStore);
        }
        StreamType(q->alttp);
        i = 0;
        for (auto v = (ArgList*)q->altargs; v; v = v->next, i++)
            ;
        StreamIndex(i);
        for (auto v = (ArgList*)q->altargs; v; v = v->next)
        {
            StreamType(v->tp);
            if (v->exp)
            {
                StreamExpression(v->exp);
            }
        }
        StreamIndex(q->ansColor);
        StreamIndex(q->leftColor);
        StreamIndex(q->rightColor);
        StreamIndex(q->scaleColor);
        StreamIndex(q->flags);
        StreamIndex(q->definition);
        StreamIndex(q->available);
        StreamIndex(q->sourceindx);
        StreamIndex(q->copy);
        StreamIndex(q->retcount);
        StreamIndex(q->sehMode);
        StreamIndex(q->fastcall);
        StreamIndex(q->oldmode);
        StreamIndex(q->novalue);
        StreamIndex(q->temps);
        StreamIndex(q->precolored);
        StreamIndex(q->moved);
        StreamIndex(q->livein);
        StreamIndex(q->liveRegs);
#endif
    }
}
static void StreamSymbolList(const std::vector<SimpleSymbol*>& list)
{
    for (auto s : list)
    {
        ws();
        StreamSymbol(s);
        out() << std::endl;
    }
}

static void StreamHeader()
{
    out() << magic << " ";
    out() << fileVersion << " ";
    if( architecture == ARCHITECTURE_X86 )
        out() << "X86";
    else if( architecture == ARCHITECTURE_MSIL )
        out() << "MSIL";
    out() << std::endl;
}
static void StreamParams()
{
    // compiler parameters:
    // cparams
}
static void StreamXParams()
{
#if 0
    StreamBlockType(SBT_XPARAMS, false);
    StreamString(compilerName);
    StreamString(intermediateName);
    StreamString(backendName);
    StreamIndex(showBanner);
    StreamIndex(assembling);
    StreamIndex(dataAlign);
    StreamIndex(bssAlign);
    StreamIndex(constAlign);
    StreamIndex(nextLabel);
    StreamIndex(pinning);
    StreamIndex(msilstrings);
    StreamIndex(delegateforfuncptr);
    StreamIndex(initializeScalars);
    StreamIndex(registersAssigned);
    StreamIndex(syntaxOnly);
    StreamString(prm_assemblerSpecifier);
    StreamString(prm_libPath);
    StreamString(prm_include);
    StreamString(outputFileName);
    StreamString(assemblerFileExtension);
    StreamString(prm_OutputDefFile);
    StreamString(prm_OutputImportLibraryFile);
    StreamString(pinvoke_dll);
    StreamString(prm_snkKeyFile);
    StreamString(prm_assemblyVersion);
    StreamString(prm_namespace_and_class);
    StreamString(specifiedLibs);
    StreamStringList(inputFiles);
    StreamStringList(backendFiles);
    StreamStringList(libIncludes);
    StreamStringList(toolArgs);
    StreamStringList(prm_Using);
    StreamIndex(bePragma.size());
    for (auto s : bePragma)
    {
        StreamString(s.first);
        StreamString(s.second);
    }
    StreamBlockType(SBT_XPARAMS, true);
#endif
}
static void StreamGlobals()
{
    out() << "GLOBALSYMS" << std::endl;
    level++;
    StreamSymbolList(globalCache);
    level--;
}
static void StreamExternals()
{
    out() << "EXTERNALS" << std::endl;
    level++;
    StreamSymbolList(externals);
    level--;
}
static void StreamTypes()
{
    out() << "TYPES" << std::endl;
    level++;
    StreamSymbolList(typeSymbols);
    StreamSymbolList(typedefs);
    level--;
}
static void StreamMSILProperties()
{
    StreamBlockType(SBT_MSILPROPS, false);
    StreamIndex(msilProperties.size());
    for (auto&& s : msilProperties)
    {
        StreamIndex(s.prop->fileIndex);
        StreamIndex(s.getter->fileIndex);
        StreamIndex(s.setter->fileIndex);
    }
    StreamBlockType(SBT_MSILPROPS, true);
}
static void StreamTypedefs()
{
    StreamBlockType(SBT_TYPEDEFS, false);
    StreamSymbolList(typedefs);
    StreamBlockType(SBT_TYPEDEFS, true);
}
static void StreamBrowse()
{
    StreamBlockType(SBT_BROWSEFILES, false);
    StreamIndex(browseFiles.size());
    for (auto s : browseFiles)
    {
        StreamBrowseFile(s);
    }
    StreamBlockType(SBT_BROWSEFILES, true);

    StreamBlockType(SBT_BROWSEINFO, false);
    StreamIndex(browseInfo.size());
    for (auto s : browseInfo)
    {
        StreamBrowseInfo(s);
    }
    StreamBlockType(SBT_BROWSEINFO, true);
}
static void StreamInstructions(QUAD* ins)
{
    int i = 0;
    for (QUAD* q = ins; q; q = q->fwd, i++)
        ;
    // StreamIndex(i);
    for (QUAD* q = ins; q; q = q->fwd)
    {
        ws();
        StreamInstruction(q);
        out() << std::endl;
    }
}
static void CacheOffset(FunctionData* fd, SimpleExpression* offset)
{
    if (offset)
    {
        if (offset->type == Optimizer::se_auto)
        {
            if (cachedAutos.find(offset->sp) == cachedAutos.end())
            {
                cachedAutos.insert(offset->sp);
                fd->temporarySymbols.push_back(offset->sp);
            }
        }
        else if (offset->type == Optimizer::se_tempref)
        {
            cachedTemps.insert(offset->sp);
        }
        else
        {
            CacheOffset(fd, offset->left);
            CacheOffset(fd, offset->right);
        }
    }
}
static void CacheImode(FunctionData* fd, IMODE* im)
{
    if (im)
    {
        auto it = cachedImodes.find(im);
        if (it == cachedImodes.end())
        {
            fd->imodeList.push_back(im);
            cachedImodes[im] = fd->imodeList.size();
        }
        CacheOffset(fd, im->offset);
        CacheOffset(fd, im->offset2);
        CacheOffset(fd, im->offset3);
    }
}
static void StreamIModes(FunctionData* fd)
{
    StreamBlockType(SBT_IMODES, false);
    StreamIndex(fd->imodeList.size());
    for (auto v : fd->imodeList)
    {
        StreamOperand(v);
    }
    StreamBlockType(SBT_IMODES, true);
}
static void StreamTemps()
{
    for (auto t : cachedTemps)
    {
        if (t->loadTemp | t->pushedtotemp)
        {
            StreamIndex(t->i);
            out() << t->i << " ";
            if (t->loadTemp)
                out() << "TF_LOADTEMP ";
            if (t->pushedtotemp)
                out() << "TF_PUSHEDTOTEMP ";
            StreamType(t->tp);
        }
    }
}
static void StreamLoadCache(std::map<IMODE*, IMODE*> hash)
{
    StreamIndex(hash.size());
    for (auto v : hash)
    {
        StreamIndex(cachedImodes[v.first]);
        StreamIndex(cachedImodes[v.second]);  // a tempreg number
    }
}
static void StreamFunc(FunctionData* fd)
{
    myfd = fd;
    cachedAutos.clear();
    cachedTemps.clear();
    for (auto v : fd->variables)
        if (v->storage_class == scc_auto || v->storage_class == scc_parameter)
            cachedAutos.insert(v);
    for (auto v : fd->temporarySymbols)
        if (v->storage_class == scc_auto || v->storage_class == scc_parameter)
            cachedAutos.insert(v);

    cachedImodes.clear();
    fd->imodeList.clear();
    for (auto q = fd->instructionList; q; q = q->fwd)
    {
        switch (q->dc.opcode)
        {
        case i_icon:
        case i_imcon:
        case i_fcon:
        case i_cxcon:
        case i_label:
        case i_line:
        case i_passthrough:
            break;
        default:
            CacheImode(fd, q->dc.left);
            CacheImode(fd, q->dc.right);
            break;
        }
        CacheImode(fd, q->ans);
    }
    // have to do this here because inlining results in symbols being used across functions...
    int i = 1;
    for (auto s : fd->variables)
    {
        s->fileIndex = 2 * i++ + 1;
    }
    for (auto s : fd->temporarySymbols)
    {
        if (s->storage_class != scc_localstatic)
            s->fileIndex = 2 * i++ + 1;
    }
    out() << fd->name->name << " ";
#if 0
    StreamIndex((fd->setjmp_used ? FF_USES_SETJMP : 0) + (fd->hasAssembly ? FF_HAS_ASSEMBLY : 0));
    StreamIndex(fd->blockCount);
    StreamIndex(fd->tempCount);
    StreamIndex(fd->exitBlock);
    StreamIndex(fd->ellipsePos);
    StreamIndex(fd->fastcallAlias);
#endif
    if( !fd->variables.empty() )
    {
        out() << std::endl;
        level++;
        ws();
        out() << "VARS:" << std::endl;
        level++;
        StreamSymbolList(fd->variables);
        level -= 2;
    }
    if( !fd->temporarySymbols.empty() )
    {
        out() << std::endl;
        level++;
        ws();
        out() << "TEMPS:" << std::endl;
        level++;
        StreamSymbolList(fd->temporarySymbols);
        level -= 2;
    }
    //StreamIModes(fd);
    //StreamExpression(fd->fltexp);
    if( fd->instructionList )
    {
        out() << std::endl;
        level++;
        ws();
        out() << "BEGIN:" << std::endl;
        level++;
        StreamInstructions(fd->instructionList);
        level--;
        ws();
        out() << "END:" << std::endl;
        level--;
    }
    //StreamTemps();
    //StreamLoadCache(fd->loadHash);
    //StreamIndex(fd->computedLabels.size());
    //for (auto v : fd->computedLabels)
    //    StreamIndex(v);
}

static void StreamData()
{
    out() << "DATA" << std::endl;
    level++;
    for (BaseData* data : baseData)
    {
        ws();
        out() << datatype[data->type] << " ";

        switch (data->type)
        {
        case DT_NONE:
            break;
        case DT_SEG:
        case DT_SEGEXIT:
            StreamIndex(data->i);
            break;
        case DT_DEFINITION:
            StreamIndex(data->symbol.sym->fileIndex);
            out() << " ";
            StreamIndex(data->symbol.i);
            break;
        case DT_LABELDEFINITION:
            StreamIndex(data->i);
            break;
        case DT_RESERVE:
            StreamIndex(data->i);
            break;
        case DT_SYM:
            StreamIndex(data->symbol.sym->fileIndex);
            out() << " ";
            StreamIndex(data->symbol.i);
            break;
        case DT_SRREF:
            StreamIndex(data->symbol.sym->fileIndex);
            out() << " ";
            StreamIndex(data->symbol.i);
            break;
        case DT_PCREF:
            StreamIndex(data->symbol.sym->fileIndex);
            break;
        case DT_FUNCREF:
            StreamIndex(data->symbol.sym->fileIndex);
            out() << " ";
            StreamIndex(data->symbol.i);
            break;
        case DT_LABEL:
            StreamIndex(data->i);
            break;
        case DT_LABDIFFREF:
            StreamIndex(data->diff.l1);
            out() << " ";
            StreamIndex(data->diff.l2);
            break;
        case DT_STRING:
            out() << data->astring.str;
            break;
        case DT_BIT:
            break;
        case DT_BOOL:
            StreamIntValue(data->i, 1);
            break;
        case DT_BYTE:
            StreamIntValue(data->i, 1);
            break;
        case DT_USHORT:
            StreamIntValue(data->i, 2);
            break;
        case DT_UINT:
            StreamIntValue(data->i, 4);
            break;
        case DT_ULONG:
            StreamIntValue(data->i, 8);
            break;
        case DT_ULONGLONG:
            StreamIntValue(data->i, 8);
            break;
        case DT_16:
            StreamIntValue(data->i, 2);
            break;
        case DT_32:
            StreamIntValue(data->i, 4);
            break;
        case DT_ENUM:
            StreamIntValue(data->i, 4);
            break;
        case DT_FLOAT:
            StreamFloatValue(data->f);
            break;
        case DT_DOUBLE:
            StreamFloatValue(data->f);
            break;
        case DT_LDOUBLE:
            StreamFloatValue(data->f);
            break;
        case DT_CFLOAT:
            StreamFloatValue(data->c.r);
            out() << " ";
            StreamFloatValue(data->c.i);
            break;
        case DT_CDOUBLE:
            StreamFloatValue(data->c.r);
            out() << " ";
            StreamFloatValue(data->c.i);
            break;
        case DT_CLONGDOUBLE:
            StreamFloatValue(data->c.r);
            out() << " ";
            StreamFloatValue(data->c.i);
            break;
        case DT_ADDRESS:
            StreamIntValue(data->i, 8);
            break;
        case DT_VIRTUAL:
            StreamIndex(data->symbol.sym->fileIndex);
            out() << " ";
            StreamIndex(data->symbol.i);
            break;
        case DT_ENDVIRTUAL:
            StreamIndex(data->symbol.sym->fileIndex);
            break;
        case DT_ALIGN:
            StreamIndex(data->i);
            break;
        case DT_VTT:
            StreamIndex(data->symbol.sym->fileIndex);
            out() << " ";
            StreamIntValue(data->symbol.i, sizeof(data->symbol.i));
            break;
        case DT_IMPORTTHUNK:
            StreamIndex(data->symbol.sym->fileIndex);
            break;
        case DT_VC1:
            StreamIndex(data->symbol.sym->fileIndex);
            break;
        case DT_AUTOREF:
            StreamIndex(data->symbol.sym->fileIndex);
            out() << " ";
            StreamIndex(data->symbol.i);
            break;
        case DT_FUNC:
            StreamFunc(data->funcData);
            break;
        }
        out() << std::endl;
    }
    level--;
}


// in the following, the low bit being set signifies the data in the stream
// is an index rather than a pointer to a symbol (used in load resolution)
static void NumberGlobals()
{
    int i = 1;
    for (Optimizer::SimpleSymbol* s : globalCache)
    {
        s->fileIndex = 2 * i++ + 1;
    }
    std::vector<Optimizer::SimpleSymbol*>::iterator it;
    for (it = externals.begin(); it != externals.end(); ++it)
    {
        if (*it)
        {
            if ((*it)->fileIndex && !(*it)->dontinstantiate &&
                    (*it)->initialized)  // && ((*it)->storage_class != scc_virtual || (*it)->hasInlineFunc))
            {
                *it = 0;
            }
            else
            {
                (*it)->fileIndex = 2 * i + 1;
            }
        }
        i++;
    }
}
static void NumberTypes()
{
    int i = 1;
    for (Optimizer::SimpleSymbol* s : definedFunctions)
        if (!s->fileIndex)
            typeSymbols.push_back(s);
    for (Optimizer::SimpleSymbol* s : typeSymbols)
    {
        s->typeIndex = 2 * i++ + 1;
        // static members
        if (s->storage_class != scc_external && s->storage_class != scc_global && s->storage_class != scc_constant)
        {
            s->fileIndex = s->typeIndex;
        }
    }
    for (Optimizer::SimpleSymbol* s : typedefs)
        s->typeIndex = s->fileIndex = 2 * i++ + 1;
}
void DumpIntermediate(std::ostream &out)
{
    stream = &out;
    textRegion.clear();
    textOffset = 1;
    cachedText.clear();
    NumberGlobals();
    NumberTypes();

    StreamHeader();
    StreamParams();
    StreamXParams();
    StreamGlobals();
    StreamExternals();
    StreamTypes();
    //StreamBrowse();
    //StreamMSILProperties();
    StreamData();
}
}  // namespace Optimizer
