#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class IfExpressionSyntax : public ExpressionSyntax
        {
        public:
            IfExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr);
            IfExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr, ExpressionSyntax* elseExpr);
            ~IfExpressionSyntax();

            ExpressionSyntax* getCondition();
            ExpressionSyntax* getExpression();
            ExpressionSyntax* getElseExpression();

            int getPrecedence() override;

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_cond = nullptr,
                             *_expr = nullptr,
                             *_elseExpr = nullptr;
        };
    }
}
