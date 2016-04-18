#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class FloatLiteralSyntax : public ExpressionSyntax
        {
        public:
            FloatLiteralSyntax(float value);
            ~FloatLiteralSyntax();

            float getValue();

            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            float val;
        };
    }
}
