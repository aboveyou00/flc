#include "stdafx.h"
#include "IntegerLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        IntegerLiteralSyntax::IntegerLiteralSyntax(int value)
        {
            val = value;
        }
        IntegerLiteralSyntax::~IntegerLiteralSyntax()
        {
        }

        int IntegerLiteralSyntax::getValue()
        {
            return val;
        }

        types::RuntimeType* IntegerLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::int32;
        }



        void IntegerLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << val;
        }
    }
}
