#pragma once
#include "Syntax.h"
#include "RuntimeType.h"

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

            virtual void suggestExpressionType(types::RuntimeType* type);
            virtual types::RuntimeType* getExpressionType() = 0;

        protected:
            types::RuntimeType* suggestedType = nullptr;
        };
    }
}
