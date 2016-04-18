#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "ShlInstr.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::leftShift()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("<<", "op_LeftShift");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2_alt(int32, int32, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ShlInstr());
                });
                __addOverload2_alt(uint32, uint32, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ShlInstr());
                });
                __addOverload2_alt(int64, int64, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ShlInstr());
                });
                __addOverload2_alt(uint64, uint64, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ShlInstr());
                });
            }

            return op;
        }
    }
}
