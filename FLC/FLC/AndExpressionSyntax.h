#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class AndExpressionSyntax : public ExpressionSyntax
        {
        public:
            AndExpressionSyntax(ExpressionSyntax* left, ExpressionSyntax* right);
            ~AndExpressionSyntax();

            ExpressionSyntax* getLeftOperand();
            ExpressionSyntax* getRightOperand();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_left, *_right;
        };
    }
}
