#include "stdafx.h"
#include "TernaryExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        TernaryExpressionSyntax::TernaryExpressionSyntax(ExpressionSyntax* condition, ExpressionSyntax* iftrue, ExpressionSyntax* iffalse)
            : _cond(condition), _iftrue(iftrue), _iffalse(iffalse)
        {
        }
        TernaryExpressionSyntax::~TernaryExpressionSyntax()
        {
        }

        ExpressionSyntax* TernaryExpressionSyntax::getCondition()
        {
            return _cond;
        }
        ExpressionSyntax* TernaryExpressionSyntax::getTrueExpression()
        {
            return _iftrue;
        }
        ExpressionSyntax* TernaryExpressionSyntax::getFalseExpression()
        {
            return _iffalse;
        }



        string TernaryExpressionSyntax::toString()
        {
            return _cond->toString() + " ? " + _iftrue->toString() + " : " + _iffalse->toString();
        }
    }
}
