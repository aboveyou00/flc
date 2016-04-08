#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class SimpleNameSyntax : public ExpressionSyntax
        {
        public:
            SimpleNameSyntax(string ident, bool fullyQualified = false);
            ~SimpleNameSyntax();

            string getName();
            bool isFullyQualified();

            virtual bool isQualifiedName();

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            string name;
            bool qualified;
        };
    }
}
