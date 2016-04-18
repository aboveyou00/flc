#include "stdafx.h"
#include "IntegerLiteralSyntax.h"
#include <sstream>
#include "LdcInstr.h"

namespace flc
{
    namespace syntax
    {
        IntegerLiteralSyntax::IntegerLiteralSyntax(uint32_t value)
        {
            val = value;
        }
        IntegerLiteralSyntax::~IntegerLiteralSyntax()
        {
        }

        uint32_t IntegerLiteralSyntax::getValue()
        {
            return val;
        }

        types::RuntimeType* IntegerLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::int32();
        }

        void IntegerLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdcInstr(val));
        }

        void IntegerLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << val;
        }
    }
}
