#include "stdafx.h"
#include "BooleanLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        BooleanLiteralSyntax::BooleanLiteralSyntax(bool value)
        {
            val = value;
        }
        BooleanLiteralSyntax::~BooleanLiteralSyntax()
        {
        }

        bool BooleanLiteralSyntax::getValue()
        {
            return val;
        }

        types::RuntimeType* BooleanLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::bool8();
        }



        void BooleanLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << (val ? "true" : "false");
        }
        string BooleanLiteralSyntax::toString()
        {
            return (val ? "true" : "false");
        }
    }
}
