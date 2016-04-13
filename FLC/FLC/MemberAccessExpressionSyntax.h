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

            bool isQualifiedName() override;

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax* lhs = nullptr;
            string ident;
        };
    }
}
