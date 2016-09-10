#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitIf)
    {
    public:
        TEST_METHOD(Test_emit_if)
        {
            UseString("if (true) false");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            auto endTarget = ExpectInstr<BrfalseInstr>()->getBranchTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);

            auto pop = ExpectInstr<PopInstr>();
            ExpectDecorator(pop, endTarget);

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_if_else)
        {
            UseString("if (true) false else true");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            auto falseTarget = ExpectInstr<BrfalseInstr>()->getBranchTarget();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            auto endTarget = ExpectInstr<BrInstr>()->getBranchTarget();

            auto ldfalse = ExpectInstr<LdcI4Instr>();
            ExpectDecorator(ldfalse, falseTarget);
            Assert::AreEqual(ldfalse->getConstantValue(), 1);

            auto pop = ExpectInstr<PopInstr>();
            ExpectDecorator(pop, endTarget);

            ExpectNoMore();
        }
    };
}
