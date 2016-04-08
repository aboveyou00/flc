#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class ComplexNameSyntax : public ExpressionSyntax
        {
        public:
            ComplexNameSyntax(ExpressionSyntax* baseexpr, string ident);
            ~ComplexNameSyntax();

            string getName();
            ExpressionSyntax* getBaseExpression();

            virtual bool isQualifiedName();

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            ExpressionSyntax* lhs;
            string name;
        };
    }
}
