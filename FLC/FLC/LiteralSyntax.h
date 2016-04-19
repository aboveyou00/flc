#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        template <typename T>
        class LiteralSyntax : public ExpressionSyntax
        {
        public:
            LiteralSyntax(T value)
                : _value(value)
            {
            }
            ~LiteralSyntax()
            {
            }
            
            T getValue()
            {
                return _value;
            }

            int getPrecedence() override
            {
                return 0;
            }

        private:
            T _value;
        };
    }
}
