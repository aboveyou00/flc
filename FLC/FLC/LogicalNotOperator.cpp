#include "stdafx.h"
#include "UnaryOperator.h"
#include "OperatorOverloadMacros.h"
#include "LdcI4Instr.h"
#include "CeqInstr.h"

namespace flc
{
    namespace op
    {
        UnaryOperator *Operator::logicalNot()
        {
            static UnaryOperator *op = nullptr;
            if (op == nullptr)
            {
                op = new UnaryOperator("!", "op_LogicalNot");

                auto overloads = op->getPredefinedOverloads();
                types::RuntimeType *arg[1];

                __addOverload1(bool8)->setEmitCallImplementation([](emit::MethodBody *method)
                {
                    method->emit(new emit::LdcI4Instr(0));
                    method->emit(new emit::CeqInstr());
                });
            }

            return op;
        }
    }
}
