#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class TernaryExpressionSyntax : public ExpressionSyntax
        {
        public:
            TernaryExpressionSyntax(ExpressionSyntax* condition, ExpressionSyntax* iftrue, ExpressionSyntax* iffalse);
            ~TernaryExpressionSyntax();

            ExpressionSyntax* getCondition();
            ExpressionSyntax* getTrueExpression();
            ExpressionSyntax* getFalseExpression();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_cond = nullptr,
                             *_iftrue = nullptr,
                             *_iffalse = nullptr;
        };
    }
}
