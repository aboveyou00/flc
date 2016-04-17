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

        void TernaryExpressionSyntax::resolveTypes(types::NameResolutionContextStack *ctx)
        {
            _cond->suggestExpressionType(types::RuntimeType::bool8());
            _cond->resolveTypes(ctx);

            _iftrue->resolveTypes(ctx);
            _iffalse->resolveTypes(ctx);

            //TODO: Implement
        }
        types::RuntimeType* TernaryExpressionSyntax::getExpressionType()
        {
            //TODO: Implement
            return nullptr;
        }



        void TernaryExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            _cond->stringify(stream, tabulation);
            *stream << " ? ";
            _iftrue->stringify(stream, 0);
            *stream << " : ";
            _iffalse->stringify(stream, 0);
        }
    }
}
