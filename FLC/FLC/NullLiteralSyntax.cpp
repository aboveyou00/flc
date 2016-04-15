#include "stdafx.h"
#include "NullLiteralSyntax.h"
#include <sstream>

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

        types::RuntimeType* NullLiteralSyntax::getExpressionType()
        {
            if (suggestedType != nullptr && suggestedType->isReferenceType()) return suggestedType;
            return types::RuntimeType::nullLiteral();
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
