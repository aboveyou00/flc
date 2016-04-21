#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitMultiplicative)
    {
    public:
        TEST_METHOD(Test_emit_mulInt32)
        {
            UseString("2 * 3");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<MulInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_divInt32)
        {
            UseString("10 / 5");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 10);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<DivInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_remInt32)
        {
            UseString("10 % 2");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 10);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<RemInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_div_leftAssociative)
        {
            UseString("12 / 6 / 2");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 12);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 6);
            ExpectInstr<DivInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<DivInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
