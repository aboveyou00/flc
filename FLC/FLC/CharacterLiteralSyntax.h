#pragma once
#include "LiteralSyntax.h"

namespace flc
{
    namespace syntax
    {
        class CharacterLiteralSyntax : public LiteralSyntax<char16_t>
        {
        public:
            CharacterLiteralSyntax(char16_t value);
            ~CharacterLiteralSyntax();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;
        };
    }
}
