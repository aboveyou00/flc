#include "stdafx.h"
#include "WhileExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        WhileExpressionSyntax::WhileExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr)
            : _cond(cond), _expr(expr)
        {
        }
        WhileExpressionSyntax::~WhileExpressionSyntax()
        {
        }

        ExpressionSyntax* WhileExpressionSyntax::getCondition()
        {
            return _cond;
        }
        ExpressionSyntax* WhileExpressionSyntax::getExpression()
        {
            return _expr;
        }



        void WhileExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "while (";
            _cond->stringify(stream, 0);
            *stream << ") ";
            _expr->stringify(stream, 0);
        }
    }
}
