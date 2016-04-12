#pragma once
#include <vector>
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class CompoundExpressionSyntax : public ExpressionSyntax
        {
        public:
            CompoundExpressionSyntax(vector<ExpressionSyntax*>* expressions);
            ~CompoundExpressionSyntax();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            vector<ExpressionSyntax*> exprs;
        };
    }
}
