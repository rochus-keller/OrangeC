#include <stdio.h>
#include <stdlib.h>
#include <map>
#include "CmdSwitch.h"
#include "ToolChain.h"
#include "SharedMemory.h"
#include "ilunstream.h"
#include "ioptimizer.h"
#include "ildata.h"
#include "iout.h"
#include "allout.h"
#include <fstream>
namespace Optimizer {
void OutputEigenFile();
}

using namespace Optimizer;


static const int MAX_SHARED_REGION = 500 * 1024 * 1024;

CmdSwitchParser SwitchParser;
CmdSwitchBool WriteIcdFile(SwitchParser, 'Y', false);
CmdSwitchBool WriteDumpFile(SwitchParser, 'D', false);
CmdSwitchBool WriteEigenFile(SwitchParser, 'E', false);

const char* helpText =
    "[options] inputfile\n"
    "\n"
    "-Y output icd file\n"
    "-E output cod file\n"
    "-D output dump file\n";

const char* usageText = "[options] inputfile";

namespace Parser
{
int anonymousNotAlloc;
bool IsCompiler() { return true; }
}  // namespace Parser

Optimizer::SimpleSymbol* currentFunction;
int usingEsp;
void regInit(void) {}

bool LoadFile(SharedMemory* parserMem)
{
    bool rv = InputIntermediate(parserMem);
    return rv;
}

int main(int argc, char *argv[])
{
    auto files = ToolChain::StandardToolStartup(SwitchParser, argc, argv, usageText, helpText);
    if (files.size() != 2)
    {
        ToolChain::Usage(usageText);
    }

    SharedMemory* parserMem = nullptr;
    std::string outputFile;
    char buf[260];

    strcpy(buf, files[1].c_str());
    Utils::StripExt(buf);
    strcat(buf, "_1");
    Utils::AddExt(buf, ".icf");
    outputFile = buf;

    FILE* fil = fopen(files[1].c_str(), "rb");
    if (fil)
    {
        parserMem = new SharedMemory(MAX_SHARED_REGION);
        parserMem->Create();
        Optimizer::ReadMappingFile(parserMem, fil);
        fclose(fil);
    }
    else
    {
        Utils::Fatal("cannot open input file");
    }
    if (!LoadFile(parserMem))
    {
        Utils::Fatal("internal error: could not load intermediate file");
        return -1;
    }
    char realOutFile[260];
    if (WriteIcdFile.GetValue())
    {
        strcpy(realOutFile, files[1].c_str());
        Utils::StripExt(realOutFile);
        Utils::AddExt(realOutFile, "_.icd");
        Optimizer::icdFile = fopen(realOutFile, "w");
        if (!Optimizer::icdFile)
        {
            Utils::Fatal("Cannot open '%s' for write", realOutFile);
            return -1;
        }
        setvbuf(Optimizer::icdFile, 0, _IOFBF, 32768);
        Optimizer::OutputIcdFile();
    }
    if (WriteEigenFile.GetValue())
    {
        strcpy(realOutFile, files[1].c_str());
        Utils::StripExt(realOutFile);
        Utils::AddExt(realOutFile, ".cod");
        Optimizer::icdFile = fopen(realOutFile, "w");
        if (!Optimizer::icdFile)
        {
            Utils::Fatal("Cannot open '%s' for write", realOutFile);
            return -1;
        }
        setvbuf(Optimizer::icdFile, 0, _IOFBF, 32768);
        Optimizer::OutputEigenFile();
    }
    if (WriteDumpFile.GetValue())
    {
        strcpy(realOutFile, files[1].c_str());
        Utils::StripExt(realOutFile);
        Utils::AddExt(realOutFile, ".txt");
        std::ofstream out(realOutFile, std::ios_base::out);
        if (!out)
        {
            Utils::Fatal("Cannot open '%s' for write", realOutFile);
            return -1;
        }else
        {
            DumpIntermediate(out);
        }

    }

    return 0;
}
