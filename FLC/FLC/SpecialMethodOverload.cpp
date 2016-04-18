#include "stdafx.h"
#include "SpecialMethodOverload.h"

namespace flc
{
    namespace types
    {
        SpecialMethodOverload::SpecialMethodOverload(RuntimeType* returnType, vector<ParameterInfo*>* params)
            : MethodOverload(returnType, params)
        {
        }
        SpecialMethodOverload::SpecialMethodOverload(RuntimeType* returnType, ParameterInfo** params, int paramCount)
            : MethodOverload(returnType, params, paramCount)
        {
        }
        SpecialMethodOverload::~SpecialMethodOverload()
        {
        }

        void SpecialMethodOverload::emitCall(emit::MethodBody *method)
        {
            if (_impl != nullptr) _impl(method);
            else reportNotImplemented("SpecialMethodOverload.emitCall has no impl!");
        }
        void SpecialMethodOverload::setEmitCallImplementation(void(*impl)(emit::MethodBody*))
        {
            _impl = impl;
        }
    }
}
