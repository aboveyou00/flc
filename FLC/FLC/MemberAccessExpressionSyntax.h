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

            virtual string toString();

        private:
            ExpressionSyntax* lhs;
            string ident;
        };
    }
}
