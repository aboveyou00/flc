#include "stdafx.h"
#include "UIntegerLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        UIntegerLiteralSyntax::UIntegerLiteralSyntax(uint32_t value)
        {
            val = value;
        }
        UIntegerLiteralSyntax::~UIntegerLiteralSyntax()
        {
        }

        uint32_t UIntegerLiteralSyntax::getValue()
        {
            return val;
        }

        types::RuntimeType* UIntegerLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::uint32();
        }



        void UIntegerLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << val << "u";
        }
    }
}
