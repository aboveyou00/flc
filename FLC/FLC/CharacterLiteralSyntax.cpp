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

        string CharacterLiteralSyntax::toString()
        {
            stringstream stream;
            stream << "'" << (char)val << "'";
            return stream.str();
        }
    }
}
