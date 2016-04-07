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

            virtual string toString();

        private:
            char16_t val;
        };
    }
}
