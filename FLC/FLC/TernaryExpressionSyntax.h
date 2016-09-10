#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace types
    {
        class MethodOverload;
        class NameResolutionContextStack;
        class RuntimeType;
    }

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

            int getPrecedence() override;

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_cond = nullptr,
                             *_iftrue = nullptr,
                             *_iffalse = nullptr;
            types::RuntimeType *_exprType = nullptr;
            types::MethodOverload *_castCondition = nullptr,
                                  *_castTrue = nullptr,
                                  *_castFalse = nullptr;
        };
    }
}
