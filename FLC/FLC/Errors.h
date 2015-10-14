#pragma once
#include <string>

namespace flc
{
    void reportError(string message, string file, int lineNumber, int characterPos);
    //void reportError(string message, string file = "", int lineNumber = -1, int characterPos = -1);
}
