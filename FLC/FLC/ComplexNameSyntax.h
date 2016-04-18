#pragma once
#include "ExpressionSyntax.h"

namespace flc
{
    namespace syntax
    {
        class ComplexNameSyntax : public ExpressionSyntax
        {
        public:
            ComplexNameSyntax(ExpressionSyntax* baseexpr, string ident);
            ~ComplexNameSyntax();

            string getName();
            ExpressionSyntax* getBaseExpression();

            bool isQualifiedName() override;

            void resolveTypes(types::NameResolutionContextStack *ctx) override;
            types::RuntimeType* getExpressionType() override;

            void emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method) override;

            void stringify(stringstream* stream, int tabulation = 0) override;

        private:
            ExpressionSyntax *_lhs = nullptr;
            string _name;
        };
    }
}
