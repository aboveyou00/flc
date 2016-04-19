#include "stdafx.h"
#include "LongLiteralSyntax.h"
#include <sstream>
#include "LdcI8Instr.h"

namespace flc
{
    namespace syntax
    {
        LongLiteralSyntax::LongLiteralSyntax(uint64_t value)
            : LiteralSyntax<uint64_t>(value)
        {
        }
        LongLiteralSyntax::~LongLiteralSyntax()
        {
        }

        types::RuntimeType* LongLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::int64();
        }

        void LongLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdcI8Instr(getValue()));
        }

        void LongLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getValue() << "l";
        }
    }
}
