#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class StringLiteralSyntax : public ExpressionSyntax
        {
        public:
            StringLiteralSyntax(string strval);
            ~StringLiteralSyntax();

            string getValue();

            types::RuntimeType* getExpressionType() override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            string str;
        };
    }
}
