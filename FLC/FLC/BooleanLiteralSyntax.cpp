#include "stdafx.h"
#include "BooleanLiteralSyntax.h"
#include <sstream>
#include "LdcInstr.h"

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

        void BooleanLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdcInstr(val ? 1 : 0));
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
