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

            virtual string toString();

        private:
            ExpressionSyntax* lhs;
            string name;
        };
    }
}
