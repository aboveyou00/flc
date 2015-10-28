#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        enum class TermType
        {
            NullLiteral = 0,
            BooleanLiteral = 1,
            StringLiteral = 2,
            CharacterLiteral = 3,
            IntegerLiteral = 4,
            FloatLiteral = 5
        };

        class TermSyntax : public ExpressionSyntax
        {
        public:
            TermSyntax();
            TermSyntax(string str);
            TermSyntax(char16_t val);
            TermSyntax(uint32_t val);
            TermSyntax(bool val);
            TermSyntax(float val);
            ~TermSyntax();

            TermType getType();

            virtual string toString();

        private:
            TermType _type;
            string strval; //std::string cannot be inside of a union, so we have to deal with the memory overhead.
            union
            {
                char16_t chrval;
                uint32_t intval;
                bool boolval;
                float floatval;
            };
        };
    }
}