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

            bool isQualifiedName() override;

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            string name;
            bool qualified;
        };
    }
}
