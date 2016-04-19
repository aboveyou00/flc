#include "stdafx.h"
#include "DoubleLiteralSyntax.h"
#include <sstream>
#include "LdcR8Instr.h"

namespace flc
{
    namespace syntax
    {
        DoubleLiteralSyntax::DoubleLiteralSyntax(double value)
            : LiteralSyntax<double>(value)
        {
        }
        DoubleLiteralSyntax::~DoubleLiteralSyntax()
        {
        }

        types::RuntimeType* DoubleLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::float64();
        }

        void DoubleLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdcR8Instr(getValue()));
        }

        void DoubleLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << getValue() << "d";
        }
    }
}
