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

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            char16_t val;
        };
    }
}
