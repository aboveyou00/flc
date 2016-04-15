#include "stdafx.h"
#include "FloatLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        FloatLiteralSyntax::FloatLiteralSyntax(float value)
        {
            val = value;
        }
        FloatLiteralSyntax::~FloatLiteralSyntax()
        {
        }

        float FloatLiteralSyntax::getValue()
        {
            return val;
        }

        types::RuntimeType* FloatLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::float32();
        }


        
        void FloatLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << val << "f";
        }
    }
}
