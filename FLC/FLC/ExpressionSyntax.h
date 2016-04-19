#pragma once
#include "Syntax.h"
#include "RuntimeType.h"
#include "NameResolutionContextStack.h"
#include "MethodBody.h"

namespace flc
{
    namespace syntax
    {
        class ExpressionSyntax : public Syntax
        {
        public:
            ExpressionSyntax();
            ~ExpressionSyntax();

            virtual int getPrecedence() = 0;

            virtual bool isQualifiedName();
            virtual bool isLeftHandSide();

            virtual void registerNames(types::NameResolutionContextStack *ctx);
            virtual void resolveNames(types::NameResolutionContextStack *ctx);
            virtual void resolveTypes(types::NameResolutionContextStack *ctx);
            virtual void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) = 0;

            virtual void suggestExpressionType(types::RuntimeType* type);
            virtual types::RuntimeType* getExpressionType() = 0;

        protected:
            types::RuntimeType* suggestedType = nullptr;
        };
    }
}

/*

Operator precedence:

literals: 0
unary: 100
multiplicative: 200
additive: 300
shift: 400
relational: 500
equality: 600
and: 700
xor: 800
or: 900
conditional and: 1000
conditional or: 1100
ternary: 1200
assignment: 1500

if: 2000
while: 2000
compound: 3000

*/
