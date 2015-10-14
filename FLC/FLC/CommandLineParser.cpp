#include "stdafx.h"
#include "CommandLineParser.h"
#include "Tokenizer.h"

namespace flc
{
    int parseCommandLineArguments(int argn, string strings[])
    {
        bool showHelp = false;
        int returnValue = 0;

        if (argn <= 1) showHelp = true;
        else
        {

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