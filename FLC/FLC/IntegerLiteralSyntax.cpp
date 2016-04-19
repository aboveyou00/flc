#include "stdafx.h"
#include "IntegerLiteralSyntax.h"
#include <sstream>
#include "LdcI4Instr.h"

namespace flc
{
    namespace syntax
    {
        IntegerLiteralSyntax::IntegerLiteralSyntax(uint32_t value)
            : LiteralSyntax<uint32_t>(value)
        {
        }
        IntegerLiteralSyntax::~IntegerLiteralSyntax()
        {
        }

        types::RuntimeType* IntegerLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::int32();
        }

        void IntegerLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdcI4Instr(getValue()));
        }

        void IntegerLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getValue();
        }
    }
}
