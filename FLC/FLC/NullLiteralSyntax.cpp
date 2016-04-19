#include "stdafx.h"
#include "NullLiteralSyntax.h"
#include <sstream>
#include "LdnullInstr.h"

namespace flc
{
    namespace syntax
    {
        NullLiteralSyntax::NullLiteralSyntax()
        {
        }
        NullLiteralSyntax::~NullLiteralSyntax()
        {
        }

        int NullLiteralSyntax::getPrecedence()
        {
            return 0;
        }

        types::RuntimeType* NullLiteralSyntax::getExpressionType()
        {
            if (suggestedType != nullptr && suggestedType->isReferenceType()) return suggestedType;
            return types::RuntimeType::nullLiteral();
        }

        void NullLiteralSyntax::emit(types::NameResolutionContextStack *, emit::MethodBody *method)
        {
            method->emit(new emit::LdnullInstr());
        }

        void NullLiteralSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "null";
        }
        string NullLiteralSyntax::toString()
        {
            return "null";
        }
    }
}
