#pragma once
#include <string>

namespace flc
{
    using namespace std;

    void reportError(string message, string file = "", int lineNumber = -1, int characterPos = -1);

    void clearReportedErrors();
    bool wereErrorsReported();

    void reportNotImplemented(string message = "");
}
