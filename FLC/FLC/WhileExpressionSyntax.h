#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class WhileExpressionSyntax : public ExpressionSyntax
        {
        public:
            WhileExpressionSyntax(ExpressionSyntax* cond, ExpressionSyntax* expr, bool positiveCondition = true);
            ~WhileExpressionSyntax();

            ExpressionSyntax* getCondition();
            ExpressionSyntax* getExpression();

            bool isWhileExpression();
            bool isUntilExpression();

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_cond = nullptr,
                             *_expr = nullptr;
            bool _isWhile;
        };
    }
}
