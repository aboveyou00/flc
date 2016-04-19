#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "CltInstr.h"
#include "LdcInstr.h"
#include "CeqInstr.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::greaterThanOrEqual()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator(">=", "op_GreaterThanOrEqual");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2_alt(bool8, int32, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CltInstr(true));
                    method->emit(new emit::LdcInstr(0));
                    method->emit(new emit::CeqInstr());
                });
                __addOverload2_alt(bool8, uint32, uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CltInstr(false));
                    method->emit(new emit::LdcInstr(0));
                    method->emit(new emit::CeqInstr());
                });
                __addOverload2_alt(bool8, int64, int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CltInstr(true));
                    method->emit(new emit::LdcInstr(0));
                    method->emit(new emit::CeqInstr());
                });
                __addOverload2_alt(bool8, uint64, uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CltInstr(false));
                    method->emit(new emit::LdcInstr(0));
                    method->emit(new emit::CeqInstr());
                });

                __addOverload2_alt(bool8, float32, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CltInstr(true));
                    method->emit(new emit::LdcInstr(0));
                    method->emit(new emit::CeqInstr());
                });
                __addOverload2_alt(bool8, float64, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CltInstr(true));
                    method->emit(new emit::LdcInstr(0));
                    method->emit(new emit::CeqInstr());
                });
            }

            return op;
        }
    }
}
