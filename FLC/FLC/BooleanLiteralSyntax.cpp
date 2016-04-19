#include "stdafx.h"
#include "BooleanLiteralSyntax.h"
#include <sstream>
#include "LdcI4Instr.h"

namespace flc
{
    namespace syntax
    {
        BooleanLiteralSyntax::BooleanLiteralSyntax(bool value)
            : LiteralSyntax<bool>(value)
        {
        }
        BooleanLiteralSyntax::~BooleanLiteralSyntax()
        {
        }

        types::RuntimeType* BooleanLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::bool8();
        }

        void BooleanLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdcI4Instr(getValue() ? 1 : 0));
        }

        void BooleanLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << (getValue() ? "true" : "false");
        }
        string BooleanLiteralSyntax::toString()
        {
            return (getValue() ? "true" : "false");
        }
    }
}
