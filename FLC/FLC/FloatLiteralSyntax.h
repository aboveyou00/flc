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

            virtual void stringify(stringstream* stream, int tabulation = 0);

        private:
            float val;
        };
    }
}
