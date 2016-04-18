#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "AndInstr.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::bitwiseAnd()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("&", "op_BitwiseAnd");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2(int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AndInstr());
                });
                __addOverload2(int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AndInstr());
                });
                __addOverload2(uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AndInstr());
                });
                __addOverload2(uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AndInstr());
                });

                __addOverload2(bool8);
            }

            return op;
        }
    }
}
