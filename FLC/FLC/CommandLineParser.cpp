#include "stdafx.h"
#include "CommandLineParser.h"
#include "Compiler.h"

namespace flc
{
    int parseCommandLineArguments(int argn, string args[])
    {
        bool showHelp = false;
        int returnValue = 0;

        if (argn <= 1) showHelp = true;
        else if (argn == 2 && args[1] == "help") showHelp = true;
        else if (argn > 2)
        {
            cout << "We currently only support one source file." << endl;
            showHelp = true;
        }
        else
        {
            //We only have one command line argument
            auto *comp = new Compiler();
            if (!comp->tryAddSourceFile(args[1])) return 20;
            if (!comp->tryCompile()) return 21;
        }

        if (showHelp) showHelpMessage();
        return returnValue;
    }

    void showHelpMessage()
    {
        cout << "Usage: flc <filename>" << endl;

        std::getchar();
    }
}