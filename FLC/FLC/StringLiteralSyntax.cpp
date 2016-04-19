#include "stdafx.h"
#include "StringLiteralSyntax.h"
#include <sstream>
#include "LdstrInstr.h"

namespace flc
{
    namespace syntax
    {
        StringLiteralSyntax::StringLiteralSyntax(string value)
            : LiteralSyntax<string>(value)
        {
        }
        StringLiteralSyntax::~StringLiteralSyntax()
        {
        }
        
        types::RuntimeType* StringLiteralSyntax::getExpressionType()
        {
            return types::RuntimeType::string();
        }

        void StringLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdstrInstr(getValue()));
        }

        void StringLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "\"";
            *stream << getValue();
            *stream << "\"";
        }
    }
}
