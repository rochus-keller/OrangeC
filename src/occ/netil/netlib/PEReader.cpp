/*
    Software License Agreement (BSD License)

    Copyright (c) 2016, David Lindauer, (LADSoft).
    All rights reserved.

    Redistribution and use of this software in source and binary forms,
    with or without modification, are permitted provided that the following
    conditions are met: 

    * Redistributions of source code must retain the above
      copyright notice, this list of conditions and the

    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the
      following disclaimer in the documentation and/or other
      materials provided with the distribution.

    * Neither the name of LADSoft nor the names of its
      contributors may be used to endorse or promote products
      derived from this software without specific prior
      written permission of LADSoft.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
    OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
    OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    contact information:
        email: TouchStone222@runbox.com <David Lindauer>
*/
#ifdef _WIN32
#include "Windows.h"
#endif
#include "DotNetPELib.h"
#include "PEFile.h"
#include "MZHeader.h"
#include "PEHeader.h"
#include "dllexportreader.h"
#include <time.h>
#include <stdio.h>
namespace DotNetPELib
{

    std::string DIR_SEP = "\\";
    TableEntryBase *TableEntryFactory::GetEntry(size_t index)
    {
        switch(index)
        {
            case tModule:
                return new ModuleTableEntry;
            case tTypeRef:
                return new TypeRefTableEntry;
            case tTypeDef:
                return new TypeDefTableEntry;
            case tField:
                return new FieldTableEntry;
            case tMethodDef:
                return new MethodDefTableEntry;
            case tParam:
                return new ParamTableEntry;
            case tInterfaceImpl:
                return new InterfaceImplTableEntry;
            case tMemberRef:
                return new MemberRefTableEntry;
            case tConstant:
                return new ConstantTableEntry;
            case tCustomAttribute:
                return new CustomAttributeTableEntry;
            case tFieldMarshal:
                return new FieldMarshalTableEntry;
            case tDeclSecurity:
                return new DeclSecurityTableEntry;
            case tClassLayout:
                return new ClassLayoutTableEntry;
            case tFieldLayout:
                return new FieldLayoutTableEntry;
            case tStandaloneSig:
                return new StandaloneSigTableEntry;
            case tEventMap :
                return new EventMapTableEntry;
            case tEvent :
                return new EventTableEntry;
            case tPropertyMap:
                return new PropertyMapTableEntry;
            case tProperty:
                return new PropertyTableEntry;
            case tMethodSemantics:
                return new MethodSemanticsTableEntry;
            case tMethodImpl:
                return new MethodImplTableEntry;
            case tModuleRef:
                return new ModuleRefTableEntry;
            case tTypeSpec:
                return new TypeSpecTableEntry;
            case tImplMap:
                return new ImplMapTableEntry;
            case tFieldRVA:
                return new FieldRVATableEntry;
            case tAssemblyDef:
                return new AssemblyDefTableEntry;
            case tAssemblyRef:
                return new AssemblyRefTableEntry;
            case tFile:
                return new FileTableEntry;
            case tExportedType:
                return new ExportedTypeTableEntry;
            case tManifestResource:
                return new ManifestResourceTableEntry;
            case tNestedClass:
                return new NestedClassTableEntry;
            case tGenericParam:
                return new GenericParamTableEntry;
            case tMethodSpec:
                return new MethodSpecTableEntry;
            case tGenericParamConstraint:
                return new GenericParamConstraintsTableEntry;
            default:
                return nullptr;
        }
    }
    PEReader::~PEReader()
    {
        delete [] inputFile_;
        delete [] objects_;
        delete[] stringData_;
        delete[] blobData_;
        for (int i=0; i < MaxTables; i++)
        {
            for (int j=0; j < tables_[i].size(); j++)
            {
                TableEntryBase *p = tables_[i][j];
                delete p;
            }
        }
    }
    std::string PEReader::SearchOnPath(std::string fileName)
    {
        // if it exists in the current directory accept it
        std::fstream find(fileName.c_str(), std::ios::in);
        if (find.is_open())
        {
            return fileName;
        }
        // else look on the path
        std::string path = libPath_;
        std::string rv;
        std::vector<std::string> split;
        size_t npos = path.find(";");
        while (npos != std::string::npos)
        {
            split.push_back(path.substr(0, npos));
            if (npos > path.size() - 1)
            {
                path = path.substr(npos);
            }
            else
            {
                path = "";
            }
            npos = path.find(";");
        }
        if (path.size())
            split.push_back(path);
        for (auto s : split)
        {
            std::string name = s + DIR_SEP + fileName;
            std::fstream find(name.c_str(), std::ios::in);
            if (find.is_open())
            {
                rv = name;
                break;
            }
        }
        return rv;
    }
    std::string PEReader::SearchInGAC(std::string path, std::string fileName)
    {
        std::string rv;
        std::string current = path + DIR_SEP + "*";
#ifdef _WIN32
        WIN32_FIND_DATA data;
        HANDLE h = FindFirstFile(current.c_str(), &data);
        if (h != INVALID_HANDLE_VALUE)
        {
            do {
                if (std::string(data.cFileName) != "." && std::string(data.cFileName) != "..")
                if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
                {
                     rv = SearchInGAC(path + DIR_SEP + data.cFileName, fileName);
                }
                else
                {
                    if (fileName == data.cFileName)
                        rv = path + DIR_SEP + data.cFileName;
                }

            } while (!rv.size() && FindNextFile(h, &data));
            FindClose(h);
        }
#endif        
        return rv;
    }
    std::string PEReader::SearchForManagedFile(std::string fileName)
    {
        std::string rv;
        char *windir = getenv("windir");
        if (windir)
        {
            // search for pure msil solution (.net v4)
            rv = SearchInGAC(std::string(windir) + DIR_SEP + "Microsoft.Net" + DIR_SEP + "Assembly" + DIR_SEP + "GAC_MSIL", fileName);
            // if not search for 32 bit solution (.net v4)
            if (!rv.size())
                rv = SearchInGAC(std::string(windir) + DIR_SEP + "Microsoft.Net" + DIR_SEP + "Assembly" + DIR_SEP + "GAC_32", fileName);
            // if not search the pre-v4 gac and just take anything we find...
            if (!rv.size())
                rv = SearchInGAC(std::string(windir) + DIR_SEP + "Assembly", fileName);
        }
        if (!rv.size())
        {
            rv = SearchOnPath(fileName);
        }
        return rv;
    }
    int PEReader::ManagedLoad(std::string fileName)

    {
        fileName = SearchForManagedFile(fileName);
        inputFile_ = new std::fstream(fileName.c_str(), std::ios::in | std::ios::binary);
        if (!inputFile_->fail())
        {
            size_t peLoc = PELocation();
            if (!peLoc)
                return ERR_NOT_PE;
            corRVA_ = Cor20Location(peLoc);
            if (!corRVA_)
                return ERR_NOT_ASSEMBLY;
            int rv = ReadTables(corRVA_);
            return rv;
        }
        else
        {
            return ERR_FILE_NOT_FOUND;
        }
    }
        
    void PEReader::get(void *buffer, size_t offset, size_t len)
    {
        inputFile_->seekg(offset);
        inputFile_->read((char *)buffer, len);
    }
    size_t PEReader::RVAToFileLocation(size_t rva)
    {
        for (int i=0; i < num_objects_; i++)
        {
            if (rva >= objects_[i].virtual_addr && rva < objects_[i].virtual_addr + objects_[i].virtual_size)
            {
                return rva - objects_[i].virtual_addr + objects_[i].raw_ptr;
            }
        }
        return 0;
    }
    size_t PEReader::PELocation()
    {
        Byte mz[0x40];
        get(mz, 0, sizeof(mz));
        if (*(short *)mz == MZ_SIGNATURE)
        {
            Byte pe[248];
            get(pe, *(DWord *)(mz + 0x3c), 248);
            if (*(short *)pe == PESIG)
            {
                PEHeader *peHeader = (PEHeader *)pe;
                if (peHeader->magic == PE_MAGICNUM && peHeader->nt_hdr_size == 0xe0)
                {
                    // good enough, it sorta looks like a valid PE file
                    //load the objects table
                    num_objects_ = peHeader->num_objects;
                    objects_ = new PEObject[num_objects_];
                    get(objects_, *(DWord *)(mz + 0x3c) + sizeof(PEHeader), num_objects_ * sizeof(PEObject));
                    // return the pe header offset
                    return *(DWord *)(mz + 0x3c);
                }
            }
        }
        return 0;
    }
    size_t PEReader::Cor20Location(size_t headerOffs)
    {
        PEHeader pe;
        get(&pe, headerOffs, sizeof(PEHeader));
        size_t offs = pe.com_rva;
        size_t size = pe.com_size;
        DotNetCOR20Header cor20;
        get(&cor20, RVAToFileLocation(offs), sizeof(cor20));
        if (size == cor20.cb)
        {
            if (cor20.MajorRuntimeVersion == 2 && cor20.MinorRuntimeVersion == 5)
            {
                size_t offs1 = cor20.MetaData[0];
                DotNetMetaHeader metaHeader;
                get(&metaHeader, RVAToFileLocation(offs1), sizeof(metaHeader));
                if (metaHeader.Signature == META_SIG)
                {
                    if (metaHeader.Major == 1 && metaHeader.Minor == 1)
                    {
                        // good enough, this sorta looks like a dot net assembly
                        return offs;
                    }
                }
            }
        }
        return 0;
    }
    void PEReader::GetStream(size_t Cor20, char *streamName, DWord pos[2])
    {
        DotNetCOR20Header cor20;
        memset(pos, 0, sizeof(DWord)*2);
        get(&cor20, RVAToFileLocation(Cor20), sizeof(cor20));
        size_t offs1 = cor20.MetaData[0];
        Byte streamHeaders[512];
        get(streamHeaders, RVAToFileLocation(offs1), sizeof(streamHeaders));
        Byte *p = streamHeaders+12;         
        p += *(DWord *)p + 4;
        if (*(Word *)p == 0 && *(Word *)(p + 2) == 5)
        {
            p += 4;
            for (int i=0; i < 5; i++)
            {
                char *q = (char *)p + sizeof(DWord) * 2;
                if (!strcmp(q, streamName))
                {
                    memcpy(pos, p, sizeof(DWord) * 2);
                    pos[0] += offs1;
                    return;
                }
                int l = 8 + strlen(q) + 1;
                if (l %4)
                    l+=4-(l%4);
                p += l;
            }
        }
    }
    int PEReader::ReadFromString(Byte *buf, size_t len, size_t offset)
    {
        if (!stringPos_)
        {
            DWord pos[2];
            GetStream(corRVA_, "#Strings", pos);
            if (!pos[0])
                return 0;
            stringPos_ = RVAToFileLocation(pos[0]);
            stringData_ = new Byte[pos[1]];
            get(stringData_, stringPos_, pos[1]);
        }
        int i;
        for (i = offset; stringData_[i] && i < offset + len-1; i++)
            buf[i - offset] = stringData_[i];
        buf[i-offset] = 0;
        return strlen((char *)buf);
    }
    int PEReader::ReadFromBlob(Byte *buf, size_t len, size_t offset)
    {
        if (!blobPos_)
        {
            DWord pos[2];
            GetStream(corRVA_, "#Blob", pos);
            if (!pos[0])
                return 0;
            blobPos_ = RVAToFileLocation(pos[0]);
            blobData_ = new Byte[pos[1]];
            get(blobData_, blobPos_, pos[1]);
        }
        Byte sizearr[4];
        memcpy(sizearr, blobData_ + offset, 4);
        get(sizearr, blobPos_+offset, 4);
        int offs, size;
        if (sizearr[0] < 128)
        {
            size = sizearr[0];
            offs = 1;
        }
        else if ((sizearr[0] & 0xc0) == 128)
        {
            size = ((sizearr[0] & 0x7f) << 8) +(sizearr[1] << 0);
            offs = 2;
        }
        else
        {
            size = ((sizearr[0] & 0x3f) << 24) +(sizearr[1] << 16) + (sizearr[2] << 8) + sizearr[3];
            offs = 4;
        }
        if (len >= size)
            memcpy(buf, blobData_ + offset + offs, size);
        return size > len ? len : size;
    }
    int PEReader::ReadFromGUID(Byte *buf, size_t len, size_t offset)
    {
        if (!GUIDPos_)
        {
            DWord pos[2];
            GetStream(corRVA_, "#GUID", pos);
            if (!pos[0])
                return 0;
            GUIDPos_ = RVAToFileLocation(pos[0]);
        }
        get(buf, GUIDPos_ + offset-1, len);
        return 16;
    }
    int PEReader::ReadTables(size_t Cor20)
    {
        DWord pos[2];
        GetStream(Cor20, "#~", pos);
        if (!pos[0])
            return ERR_INVALID_ASSEMBLY;
        Byte *tableMem = new Byte[pos[1]];
        get(tableMem, RVAToFileLocation(pos[0]), pos[1]);
        DotNetMetaTablesHeader *mth = (DotNetMetaTablesHeader *)tableMem;
        ulonglong tableFlags = mth->MaskValid;
        if (tableFlags & ~tKnownTablesMask)
        {
            return ERR_UNKNOWN_TABLE;
        }
        GetStream(Cor20, "#Strings", pos);
        sizes_[tString] = pos[1];
        GetStream(Cor20, "#US", pos);
        sizes_[tUS] = pos[1];
        GetStream(Cor20, "#GUID", pos);
        sizes_[tGUID] = pos[1];
        GetStream(Cor20, "#Blob", pos);
        sizes_[tBlob] = pos[1];
        Byte *p = tableMem + sizeof(*mth);
        for (int i=0; i < 64; i++)
        {
            sizes_[i] = 0;
            if (tableFlags & (1ULL << i))
            {
                sizes_[i] = *(DWord *)p;
                p += 4;
            }
        }
        for (int i=0; i < 64; i++)
        {
            for (int j=0; j < sizes_[i]; j++)
            {
                TableEntryBase *newItem = TableEntryFactory::GetEntry(i);
                if (!newItem)
                {
                    delete [] tableMem;
                    return ERR_UNKNOWN_TABLE;
                }
                size_t n = newItem->Get(sizes_, p);
                p += n;
                tables_[i].push_back(newItem);
            }
        }
        delete [] tableMem;
        return 0;
    }
}