#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "SubInstr.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::subtraction()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("-", "op_Subtraction");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2(int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::SubInstr(false, true));
                });
                __addOverload2(int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::SubInstr(false, true));
                });
                __addOverload2(uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::SubInstr(false, false));
                });
                __addOverload2(uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::SubInstr(false, false));
                });

                __addOverload2(float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::SubInstr(false, true));
                });
                __addOverload2(float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::SubInstr(false, true));
                });
            }

            return op;
        }
    }
}
