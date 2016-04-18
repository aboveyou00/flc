#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "RemInstr.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::modulus()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("%", "op_Modulus");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2(int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::RemInstr(true));
                });
                __addOverload2(int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::RemInstr(true));
                });
                __addOverload2(uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::RemInstr(false));
                });
                __addOverload2(uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::RemInstr(false));
                });

                __addOverload2(float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::RemInstr(true));
                });
                __addOverload2(float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::RemInstr(true));
                });
            }

            return op;
        }
    }
}
