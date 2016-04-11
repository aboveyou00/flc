#include "stdafx.h"
#include "IfExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        IfExpressionSyntax::IfExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr)
            : IfExpressionSyntax(cond, expr, nullptr)
        {
        }
        IfExpressionSyntax::IfExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr, ExpressionSyntax* elseExpr)
            : _cond(cond), _expr(expr), _elseExpr(elseExpr)
        {
        }
        IfExpressionSyntax::~IfExpressionSyntax()
        {
        }

        ExpressionSyntax* IfExpressionSyntax::getCondition()
        {
            return _cond;
        }
        ExpressionSyntax* IfExpressionSyntax::getExpression()
        {
            return _expr;
        }
        ExpressionSyntax* IfExpressionSyntax::getElseExpression()
        {
            return _elseExpr;
        }



        void IfExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "if (";
            _cond->stringify(stream, 0);
            *stream << ") ";
            _expr->stringify(stream, 0);

            if (_elseExpr != nullptr)
            {
                //TODO: Fix stringify for else expression
                *stream << "\r\n";
                tabulate(stream, tabulation);
                *stream << "else ";
                _elseExpr->stringify(stream, 0);
            }
        }
    }
}
