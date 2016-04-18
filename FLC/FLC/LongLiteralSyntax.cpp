#include "stdafx.h"
#include "LongLiteralSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        LongLiteralSyntax::LongLiteralSyntax(uint64_t value)
        {
            val = value;
        }
        LongLiteralSyntax::~LongLiteralSyntax()
        {
        }

        uint64_t LongLiteralSyntax::getValue()
        {
            return val;
        }

        types::RuntimeType* LongLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::int64();
        }

        void LongLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *)
        {
            //TODO: emit long literal
        }

        void LongLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << val << "l";
        }
    }
}
