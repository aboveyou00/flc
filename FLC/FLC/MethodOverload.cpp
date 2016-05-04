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
                    //return false;
                }
            }
            return true;
        }
    }
}
