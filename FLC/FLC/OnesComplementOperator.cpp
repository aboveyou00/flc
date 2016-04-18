#include "stdafx.h"
#include "UnaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "NotInstr.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::onesComplement()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("~", "op_OnesComplement");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType *arg[1];

                __addOverload1(int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::NotInstr());
                });
                __addOverload1(int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::NotInstr());
                });
                __addOverload1(uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::NotInstr());
                });
                __addOverload1(uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::NotInstr());
                });
            }

            return op;
        }
    }
}
