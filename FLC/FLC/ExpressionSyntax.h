#pragma once
#include "Syntax.h"
#include "RuntimeType.h"
#include "NameResolutionContextStack.h"

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

            virtual void registerNames(types::NameResolutionContextStack *ctx);
            virtual void resolveNames(types::NameResolutionContextStack *ctx);
            virtual void resolveTypes(types::NameResolutionContextStack *ctx);

            virtual void suggestExpressionType(types::RuntimeType* type);
            virtual types::RuntimeType* getExpressionType() = 0;

        protected:
            types::RuntimeType* suggestedType = nullptr;
        };
    }
}
