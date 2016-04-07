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

            virtual string toString();

        private:
            string name;
            bool qualified;
        };
    }
}
