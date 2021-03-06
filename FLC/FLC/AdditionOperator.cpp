#include "stdafx.h"
#include "BinaryOperator.h"
#include "RuntimeType.h"
#include "OperatorOverloadMacros.h"
#include "AddInstr.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::addition()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("+", "op_Addition");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2(int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AddInstr(false, true));
                });
                __addOverload2(int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AddInstr(false, true));
                });
                __addOverload2(uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AddInstr(false, false));
                });
                __addOverload2(uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AddInstr(false, false));
                });

                __addOverload2(float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AddInstr(false, true));
                });
                __addOverload2(float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::AddInstr(false, true));
                });

                __addOverload2(string);
                __addOverload2_alt(string, string, object);
                __addOverload2_alt(string, object, string);
            }

            return op;
        }
    }
}
