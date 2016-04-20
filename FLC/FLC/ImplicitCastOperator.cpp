#include "stdafx.h"
#include "CastOperator.h"
#include "OperatorOverloadMacros.h"
#include "ConvI1Instr.h"
#include "ConvI2Instr.h"
#include "ConvI4Instr.h"
#include "ConvI8Instr.h"
#include "ConvR4Instr.h"
#include "ConvR8Instr.h"

namespace flc
{
    namespace op
    {
        CastOperator *Operator::implicitCast()
        {
            static CastOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new CastOperator("op_Implicit");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType *args[1] = { nullptr };

                __addCast(nullLiteral, object);

                //From sbyte
                __addCast(int8, int16)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI2Instr(false, true, true));
                });
                __addCast(int8, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI4Instr(false, true, true));
                });
                __addCast(int8, int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, true, true));
                });
                __addCast(int8, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR4Instr());
                });
                __addCast(int8, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });

                //From byte
                __addCast(uint8, int16)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI2Instr(false, false, true));
                });
                __addCast(uint8, uint16)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI2Instr(false, false, false));
                });
                __addCast(uint8, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI4Instr(false, false, true));
                });
                __addCast(uint8, uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI4Instr(false, false, false));
                });
                __addCast(uint8, int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, false, true));
                });
                __addCast(uint8, uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, false, false));
                });
                __addCast(uint8, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR4Instr());
                });
                __addCast(uint8, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });

                //From short
                __addCast(int16, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI4Instr(false, true, true));
                });
                __addCast(int16, int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, true, true));
                });
                __addCast(int16, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR4Instr());
                });
                __addCast(int16, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });

                //From ushort
                __addCast(uint16, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI4Instr(false, false, true));
                });
                __addCast(uint16, uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI4Instr(false, false, false));
                });
                __addCast(uint16, int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, false, true));
                });
                __addCast(uint16, uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, false, false));
                });
                __addCast(uint16, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR4Instr());
                });
                __addCast(uint16, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });

                //From int
                __addCast(int32, int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, true, true));
                });
                __addCast(int32, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR4Instr());
                });
                __addCast(int32, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });

                //From uint
                __addCast(uint32, int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, false, true));
                });
                __addCast(uint32, uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, false, false));
                });
                __addCast(uint32, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR4Instr());
                });
                __addCast(uint32, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });

                //From long
                __addCast(int64, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR4Instr());
                });
                __addCast(int64, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });
                
                //From ulong
                __addCast(uint64, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR4Instr());
                });
                __addCast(uint64, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });

                //From char
                __addCast(char16, uint16)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI2Instr(false, false, false));
                });
                __addCast(char16, int32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI4Instr(false, false, true));
                });
                __addCast(char16, uint32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI4Instr(false, false, false));
                });
                __addCast(char16, int64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, false, true));
                });
                __addCast(char16, uint64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvI8Instr(false, false, false));
                });
                __addCast(char16, float32)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR4Instr());
                });
                __addCast(char16, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });

                //From float
                __addCast(float32, float64)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::ConvR8Instr());
                });
            }

            return op;
        }
    }
}
