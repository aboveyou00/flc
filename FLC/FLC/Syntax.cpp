#include "stdafx.h"
#include "Syntax.h"

namespace flc
{
    namespace syntax
    {
        Syntax::Syntax()
        {
        }
        Syntax::~Syntax()
        {
        }

        void Syntax::reportError(std::string errorMessage)
        {
            flc::reportError(errorMessage, "!!!");
        }

        string Syntax::toString()
        {
            stringstream stream;
            stringify(&stream, 0);
            return stream.str();
        }
        
        void Syntax::tabulate(stringstream* stream, int tabulation)
        {
            for (int q = 0; q < tabulation; q++)
            {
                *stream << "    ";
            }
        }
    }
}
