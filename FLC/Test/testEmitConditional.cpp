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

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            auto endTarget = ExpectInstr<BrtrueInstr>()->getBranchTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);

            auto pop = ExpectInstr<PopInstr>();
            ExpectDecorator(pop, endTarget);

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_conditionalAnd)
        {
            UseString("true && false");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            auto endTarget = ExpectInstr<BrfalseInstr>()->getBranchTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);

            auto pop = ExpectInstr<PopInstr>();
            ExpectDecorator(pop, endTarget);

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_bothConditionals)
        {
            UseString("false || (true && false)");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            auto endTarget = ExpectInstr<BrtrueInstr>()->getBranchTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            auto endTarget2 = ExpectInstr<BrfalseInstr>()->getBranchTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);

            auto pop = ExpectInstr<PopInstr>();
            ExpectDecorator(pop, endTarget2);
            ExpectDecorator(pop, endTarget);

            ExpectNoMore();
        }
    };
}
