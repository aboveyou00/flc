#pragma once
#include "stdafx.h"

namespace flc
{
    //void reportError(string message, string file, int lineNumber, int characterPos);
    void reportError(string message, string file = "", int lineNumber = -1, int characterPos = -1);

    bool wereErrorsReported();

    void reportNotImplemented(string message = "");
}
