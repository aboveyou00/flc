#include "stdafx.h"
#include "MethodOverload.h"
#include "CastOperator.h"
#include "ParameterInfo.h"
#include "RuntimeType.h"

namespace flc
{
    namespace types
    {
        MethodOverload::MethodOverload(RuntimeType* returnType, vector<ParameterInfo*>* params)
            : MethodOverload(returnType, &(*params)[0], (int)params->size())
        {
        }
        MethodOverload::MethodOverload(RuntimeType* returnType, ParameterInfo** params, int paramCount)
            : _returnType(returnType)
        {
            for (int q = 0; q < paramCount; q++)
            {
                _params.push_back(params[q]);
            }
        }
        MethodOverload::~MethodOverload()
        {
        }

        RuntimeType* MethodOverload::getReturnType()
        {
            return _returnType;
        }

        int MethodOverload::getParameterCount()
        {
            return (int)_params.size();
        }
        ParameterInfo* MethodOverload::getParameterInfo(int idx)
        {
            //Let vector handle invalid indexes
            return _params.at(idx);
        }

        bool MethodOverload::isMatchForParameters(RuntimeType** paramTypes, int paramCount)
        {
            if (paramCount != getParameterCount()) return false;
            for (int q = 0; q < paramCount; q++)
            {
                auto param = getParameterInfo(q);
                if (!param->getType()->isSameAs(paramTypes[q]))
                {
                    auto cast = op::Operator::implicitCast()->findOverload(paramTypes[q], param->getType());
                    if (cast == nullptr) return false;
                }
            }
            return true;
        }
        bool MethodOverload::isBetterMatch(RuntimeType **paramTypes, int paramCount, MethodOverload *other)
        {
            //This method assumes that this and other both have already been checked and are matches for the given parameters.

            //If all implicit casts are not worse (and at least one is better) then this overload is better
            bool one_param_better = false;
            for (int q = 0; q < paramCount; q++)
            {
                auto my_param = getParameterInfo(q);
                auto other_param = other->getParameterInfo(q);
                auto is_mine_same = my_param->getType()->isSameAs(paramTypes[q]);
                auto is_other_same = other_param->getType()->isSameAs(paramTypes[q]);
                if (is_mine_same && !is_other_same) one_param_better = true;
                if (!is_mine_same && is_other_same)
                {
                    one_param_better = false;
                    break;
                }
            }
            if (one_param_better) return true;

            //If there are no parameters for which there is an implicit cast from this[q] to other[q] but there is none from other[q] to this[q]
            //And there is at least one for which there is an implicit cast from other[q] to this[q] but there is none from this[q] to other[q]
            //Then this overload is better
            for (int q = 0; q < paramCount; q++)
            {
                auto my_param = getParameterInfo(q);
                auto other_param = other->getParameterInfo(q);
                if (my_param->isSameAs(other_param)) continue;
                auto cast_mine = op::Operator::implicitCast()->findOverload(my_param->getType(), other_param->getType());
                auto cast_other = op::Operator::implicitCast()->findOverload(other_param->getType(), my_param->getType());
                if (cast_other == nullptr && cast_mine != nullptr) one_param_better = true;
                else if (cast_mine == nullptr && cast_other != nullptr)
                {
                    one_param_better = false;
                    break;
                }
            }
            if (one_param_better) return true;

            return false;
        }
    }
}
