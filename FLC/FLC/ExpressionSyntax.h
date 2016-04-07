#pragma once
#include "Syntax.h"

namespace flc
{
    namespace syntax
    {
        class ExpressionSyntax : public Syntax
        {
        public:
            ExpressionSyntax();
            ~ExpressionSyntax();

            virtual bool isQualifiedName();
            virtual bool isLeftHandSide();
        };
    }
}
