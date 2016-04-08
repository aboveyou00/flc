#include "stdafx.h"
#include "CompoundExpressionSyntax.h"
#include <sstream>

namespace flc
{
    namespace syntax
    {
        CompoundExpressionSyntax::CompoundExpressionSyntax(vector<ExpressionSyntax*>* expressions)
        {
            exprs.reserve(expressions->size());
            for (auto expr : *expressions)
            {
                exprs.push_back(expr);
            }
        }
        CompoundExpressionSyntax::~CompoundExpressionSyntax()
        {
        }

        void CompoundExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "{\r\n";
            for (auto expr : exprs)
            {
                expr->stringify(stream, tabulation + 1);
                *stream << "\r\n";
            }
            tabulate(stream, tabulation);
            *stream << "}";
        }
    }
}
