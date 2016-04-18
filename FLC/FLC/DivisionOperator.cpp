#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "DivInstr.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::division()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("/", "op_Division");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2(int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::DivInstr(true));
                });
                __addOverload2(int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::DivInstr(true));
                });
                __addOverload2(uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::DivInstr(false));
                });
                __addOverload2(uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::DivInstr(false));
                });

                __addOverload2(float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::DivInstr(true));
                });
                __addOverload2(float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::DivInstr(true));
                });
            }

            return op;
        }
    }
}
