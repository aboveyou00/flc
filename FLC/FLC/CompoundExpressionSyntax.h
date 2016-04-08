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

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            vector<ExpressionSyntax*> exprs;
        };
    }
}
