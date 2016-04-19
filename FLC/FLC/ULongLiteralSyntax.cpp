#include "stdafx.h"
#include "ULongLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        ULongLiteralSyntax::ULongLiteralSyntax(uint64_t value)
            : LiteralSyntax<uint64_t>(value)
        {
        }
        ULongLiteralSyntax::~ULongLiteralSyntax()
        {
        }

        types::RuntimeType* ULongLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::uint64();
        }

        void ULongLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: Implement
        }

        void ULongLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getValue() << "ul";
        }
    }
}
