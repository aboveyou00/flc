#include "stdafx.h"
#include "CharacterLiteralSyntax.h"
#include <sstream>
#include "LdcI4Instr.h"

namespace flc
{
    namespace syntax
    {
        CharacterLiteralSyntax::CharacterLiteralSyntax(char16_t value)
            : LiteralSyntax<char16_t>(value)
        {
        }
        CharacterLiteralSyntax::~CharacterLiteralSyntax()
        {
        }

        types::RuntimeType* CharacterLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::char16();
        }

        void CharacterLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdcI4Instr(getValue()));
        }

        void CharacterLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "'";
            *stream << (char)getValue();
            *stream << "'";
        }
    }
}
