#include "stdafx.h"
#include "CompoundExpressionSyntax.h"
#include <sstream>
#include "PopInstr.h"

namespace flc
{
    namespace syntax
    {
        CompoundExpressionSyntax::CompoundExpressionSyntax(vector<ExpressionSyntax*>* expressions)
        {
            exprs.reserve(expressions->size());
            for (auto expr : *expressions)
            {
                exprs.push_back(expr);
            }
        }
        CompoundExpressionSyntax::~CompoundExpressionSyntax()
        {
            for (size_t q = 0; q < exprs.size(); q++)
            {
                auto expr = exprs[q];
                delete expr;
            }
            exprs.clear();
        }

        int CompoundExpressionSyntax::getPrecedence()
        {
            return 3000;
        }

        void CompoundExpressionSyntax::resolveTypes(types::NameResolutionContextStack *)
        {
            //TODO: Implement
        }
        types::RuntimeType* CompoundExpressionSyntax::getExpressionType()
        {
            auto numExprs = exprs.size();
            if (numExprs == 0) return types::RuntimeType::void0();
            if (numExprs == 1) return exprs[0]->getExpressionType();
            return exprs[exprs.size() - 1]->getExpressionType();
            //TODO: Implement early returns
        }

        void CompoundExpressionSyntax::emit(types::NameResolutionContextStack *ctx, emit::MethodBody *method)
        {
            for (size_t q = 0; q < exprs.size(); q++)
            {
                auto expr = exprs[q];
                expr->emit(ctx, method);
                if (q != exprs.size() - 1)
                {
                    auto exprType = expr->getExpressionType();
                    if (!exprType->isVoid()) method->emit(new emit::PopInstr());
                }
            }
        }

        void CompoundExpressionSyntax::stringify(stringstream* stream, int tabulation)
        {
            tabulate(stream, tabulation);
            *stream << "{\r\n";
            for (auto expr : exprs)
            {
                expr->stringify(stream, tabulation + 1);
                *stream << "\r\n";
            }
            tabulate(stream, tabulation);
            *stream << "}";
        }
    }
}
