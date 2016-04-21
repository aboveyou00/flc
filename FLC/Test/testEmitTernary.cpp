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

            Assert::IsTrue(false);

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            //auto falseTarget = ExpectInstr<BrfalseInstr>().getTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            //auto endTarget = ExpectInstr<BrInstr>().getTarget();

            auto falseInstr = ExpectInstr<LdcI4Instr>();
            Assert::AreEqual(falseInstr->getConstantValue(), 1);
            //ExpectTarget(falseInstr, falseTarge);

            //ExpectTarget(ExpectInstr<NopInstr>(), endTarget);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
