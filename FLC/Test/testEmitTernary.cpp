#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitTernary)
    {
    public:
        TEST_METHOD(Test_emit_ternary)
        {
            UseString("true ? false : true");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            auto falseTarget = ExpectInstr<BrfalseInstr>()->getBranchTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            auto endTarget = ExpectInstr<BrInstr>()->getBranchTarget();

            auto falseInstr = ExpectInstr<LdcI4Instr>();
            ExpectDecorator(falseInstr, falseTarget);
            Assert::AreEqual(falseInstr->getConstantValue(), 1);

            auto popInstr = ExpectInstr<PopInstr>();
            ExpectDecorator(popInstr, endTarget);

            ExpectNoMore();
        }
    };
}
