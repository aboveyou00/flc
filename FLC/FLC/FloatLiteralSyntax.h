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

            virtual string toString();

        private:
            float val;
        };
    }
}
