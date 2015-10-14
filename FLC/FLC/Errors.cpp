#include "stdafx.h"
#include "Errors.h"

namespace flc
{
    //void reportError(string message, string file = "", int lineNumber = -1, int characterPos = -1)
    void reportError(string message, string file, int lineNumber, int characterPos)
    {
        if (!file.empty())
        {
            cerr << file;
            if (lineNumber != -1) cerr << " @line: " << lineNumber;
            if (characterPos != -1) cerr << " @pos: " << characterPos;
            cerr << ": ";
        }
        cerr << message << endl;
    }
}
