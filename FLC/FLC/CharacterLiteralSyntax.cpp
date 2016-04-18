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

        types::RuntimeType* CharacterLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::char16();
        }

        void CharacterLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: emit character literal
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
