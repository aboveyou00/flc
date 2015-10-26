#include "stdafx.h"
#include "Errors.h"

namespace flc
{
    int errorNumber = 0;
    void reportError(string message, string file, int lineNumber, int characterPos)
    {
        errorNumber++;
        if (!file.empty())
        {
            cerr << file;
            if (lineNumber != -1) cerr << " @line: " << lineNumber;
            if (characterPos != -1) cerr << " @pos: " << characterPos;
            cerr << ": ";
        }
        cerr << message << endl;
    }

    void clearReportedErrors()
    {
        errorNumber = 0;
    }
    bool wereErrorsReported()
    {
        return errorNumber > 0;
    }

    void reportNotImplemented(string message)
    {
        if (message.empty()) reportError("Not implemented!");
        else reportError("Not implemented! " + message);
    }
}
