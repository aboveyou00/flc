#include "stdafx.h"
#include "UnaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "NegInstr.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::negation()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("-", "op_Negation");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType *arg[1];

                __addOverload1(int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::NegInstr());
                });
                __addOverload1(int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::NegInstr());
                });

                __addOverload1(float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::NegInstr());
                });
                __addOverload1(float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::NegInstr());
                });
            }

            return op;
        }
    }
}
