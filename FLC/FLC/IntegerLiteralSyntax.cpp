#include "stdafx.h"
#include "IntegerLiteralSyntax.h"
#include <sstream>

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



        void IntegerLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << val;
        }
    }
}
