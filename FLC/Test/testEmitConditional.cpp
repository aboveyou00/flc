#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitConditional)
    {
    public:
        TEST_METHOD(Test_emit_conditionalOr)
        {
            UseString("false || true");

            Assert::IsTrue(false);

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            //auto endTarget = ExpectInstr<BrtrueInstr>().getTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);

            //ExpectTarget(ExpectInstr<NopInstr>(), endTarget);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_conditionalAnd)
        {
            UseString("true && false");

            Assert::IsTrue(false);

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            //auto endTarget = ExpectInstr<BrfalseInstr>().getTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);

            //ExpectTarget(ExpectInstr<NopInstr>(), endTarget);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_bothConditionals)
        {
            UseString("false || (true && false)");

            Assert::IsTrue(false);

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            //auto endTarget = ExpectInstr<BrtrueInstr>().getTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            //auto endTarget2 = ExpectInstr<BrfalseInstr>().getTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);

            //ExpectTarget(ExpectInstr<NopInstr>(), endTarget2);

            //ExpectTarget(ExpectInstr<NopInstr>(), endTarget);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
