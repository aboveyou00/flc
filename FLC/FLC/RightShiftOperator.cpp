#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "ShrInstr.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::rightShift()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator(">>", "op_RightShift");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2_alt(int32, int32, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ShrInstr(true));
                });
                __addOverload2_alt(uint32, uint32, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ShrInstr(false));
                });
                __addOverload2_alt(int64, int64, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ShrInstr(true));
                });
                __addOverload2_alt(uint64, uint64, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ShrInstr(false));
                });
            }

            return op;
        }
    }
}
