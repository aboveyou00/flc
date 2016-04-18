#include "stdafx.h"
#include "CommandLineParser.h"
#include "Compiler.h"

namespace flc
{
    int __parseImpl(int argn, string args[], bool& showHelp);

    int parseCommandLineArguments(int argn, string args[])
    {
        bool showHelp = false;
        int returnValue = __parseImpl(argn, args, showHelp);
        if (showHelp) showHelpMessage();
        else if (wereErrorsReported()) getchar();
        return returnValue;
    }
    int __parseImpl(int argn, string args[], bool& showHelp)
    {
        if (argn <= 1) showHelp = true;
        else if (argn == 2 && args[1] == "help") showHelp = true;
        else if (argn > 2)
        {
            reportNotImplemented("We currently only support one source file.");
            showHelp = true;
            return 20;
        }
        else
        {
            //We only have one command line argument
            Compiler comp;
            if (!comp.tryAddSourceFile(args[1]))
            {
                reportError("Could not find source file: " + args[1]);
                return 19;
            }
            if (!comp.tryCompile())
            {
                reportError("Compilation aborted");
                return 21;
            }
        }
        return 0;
    }

    void showHelpMessage()
    {
        cout << "Usage: flc <filename>" << endl;

        getchar();
    }
}
