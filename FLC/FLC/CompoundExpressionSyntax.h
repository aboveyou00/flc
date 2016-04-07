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

            virtual string toString();

        private:
            vector<ExpressionSyntax*> exprs;
        };
    }
}
