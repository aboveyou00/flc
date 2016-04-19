#include "stdafx.h"
#include "UIntegerLiteralSyntax.h"
#include <sstream>
#include "LdcI4Instr.h"

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

        void UIntegerLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdcI4Instr((int32_t)getValue()));
        }

        void UIntegerLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getValue() << "u";
        }
    }
}
