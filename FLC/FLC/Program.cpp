// FLC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CommandLineParser.h"

int main(int argn, char **argv)
{
    string *args = new string[argn];
    for (int q = 0; q < argn; q++)
    {
        args[q] = string(argv[q]);
    }

    auto result = flc::parseCommandLineArguments(argn, args);

    delete[] args;
    return result;
}
