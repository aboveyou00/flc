#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class MemberAccessExpressionSyntax : public ExpressionSyntax
        {
        public:
            MemberAccessExpressionSyntax(ExpressionSyntax* term, string identifier);
            ~MemberAccessExpressionSyntax();

            virtual bool isQualifiedName();

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            ExpressionSyntax* lhs;
            string ident;
        };
    }
}
