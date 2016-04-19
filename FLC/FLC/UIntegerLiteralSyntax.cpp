#include "stdafx.h"
#include "UIntegerLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        UIntegerLiteralSyntax::UIntegerLiteralSyntax(uint32_t value)
            : LiteralSyntax<uint32_t>(value)
        {
        }
        UIntegerLiteralSyntax::~UIntegerLiteralSyntax()
        {
        }

        types::RuntimeType* UIntegerLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::uint32();
        }

        void UIntegerLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: emit uint literal
        }

        void UIntegerLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getValue() << "u";
        }
    }
}
