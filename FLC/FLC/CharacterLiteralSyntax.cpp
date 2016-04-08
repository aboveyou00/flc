#include "stdafx.h"
#include "CharacterLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        CharacterLiteralSyntax::CharacterLiteralSyntax(char16_t value)
        {
            val = value;
        }
        CharacterLiteralSyntax::~CharacterLiteralSyntax()
        {
        }

        char16_t CharacterLiteralSyntax::getValue()
        {
            return val;
        }

        void CharacterLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "'";
            *stream << (char)val;
            *stream << "'";
        }
    }
}
