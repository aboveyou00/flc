#include "stdafx.h"
#include "FloatLiteralSyntax.h"
#include <sstream>
#include "LdcR4Instr.h"

namespace flc
{
    namespace syntax
    {
        FloatLiteralSyntax::FloatLiteralSyntax(float value)
            : LiteralSyntax<float>(value)
        {
        }
        FloatLiteralSyntax::~FloatLiteralSyntax()
        {
        }

        types::RuntimeType* FloatLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::float32();
        }

        void FloatLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdcR4Instr(getValue()));
        }

        void FloatLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getValue() << "f";
        }
    }
}
