#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class CharacterLiteralSyntax : public ExpressionSyntax
        {
        public:
            CharacterLiteralSyntax(char16_t value);
            ~CharacterLiteralSyntax();

            char16_t getValue();

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            char16_t val;
        };
    }
}
