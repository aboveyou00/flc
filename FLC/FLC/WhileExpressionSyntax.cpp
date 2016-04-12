#include "stdafx.h"
#include "WhileExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        WhileExpressionSyntax::WhileExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr, bool positiveCondition)
            : _cond(cond), _expr(expr), _isWhile(positiveCondition)
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

        bool WhileExpressionSyntax::isWhileExpression()
        {
            return _isWhile;
        }
        bool WhileExpressionSyntax::isUntilExpression()
        {
            return !_isWhile;
        }

        types::RuntimeType* WhileExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }



        void WhileExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << (_isWhile ? "while (" : "until (");
            _cond->stringify(stream, 0);
            *stream << ") ";
            _expr->stringify(stream, 0);
        }
    }
}
