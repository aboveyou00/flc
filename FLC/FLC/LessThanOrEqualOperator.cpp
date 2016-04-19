#include "stdafx.h"
#include "BinaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "CgtInstr.h"
#include "LdcI4Instr.h"
#include "CeqInstr.h"

namespace flc
{
    namespace op
    {
        BinaryOperator *Operator::lessThanOrEqual()
        {
            static BinaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new BinaryOperator("<=", "op_LessThanOrEqual");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType* args[2];

                __addOverload2_alt(bool8, int32, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CgtInstr(true));
                    method->emit(new emit::LdcI4Instr(0));
                    method->emit(new emit::CeqInstr());
                });
                __addOverload2_alt(bool8, uint32, uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CgtInstr(false));
                    method->emit(new emit::LdcI4Instr(0));
                    method->emit(new emit::CeqInstr());
                });
                __addOverload2_alt(bool8, int64, int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CgtInstr(true));
                    method->emit(new emit::LdcI4Instr(0));
                    method->emit(new emit::CeqInstr());
                });
                __addOverload2_alt(bool8, uint64, uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CgtInstr(false));
                    method->emit(new emit::LdcI4Instr(0));
                    method->emit(new emit::CeqInstr());
                });

                __addOverload2_alt(bool8, float32, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CgtInstr(true));
                    method->emit(new emit::LdcI4Instr(0));
                    method->emit(new emit::CeqInstr());
                });
                __addOverload2_alt(bool8, float64, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::CgtInstr(true));
                    method->emit(new emit::LdcI4Instr(0));
                    method->emit(new emit::CeqInstr());
                });
            }

            return op;
        }
    }
}
