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

        string CompoundExpressionSyntax::toString()
        {
            stringstream stream;
            stream << "{\r\n";
            for (auto expr : exprs)
            {
                //TODO: tabulate the entire expression, not just the first line
                stream << "    " << expr->toString() << "\r\n";
            }
            stream << "}";
            return stream.str();
        }
    }
}
