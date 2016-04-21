#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitRelational)
    {
    public:
        TEST_METHOD(Test_emit_ltInt32)
        {
            UseString("10 < 20");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 10);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 20);
            ExpectInstr<CltInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_gtInt32)
        {
            UseString("7 > 2");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 7);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<CgtInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_lteInt32)
        {
            UseString("25 <= 93");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 25);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 93);
            ExpectInstr<CgtInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            ExpectInstr<CeqInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_gteInt32)
        {
            UseString("5 >= 5");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<CltInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            ExpectInstr<CeqInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_ltComplexExpr)
        {
            UseString("1 + 2 + 3 < (5 * 2 ^ 4)");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<AddInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<AddInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<XorInstr>();
            ExpectInstr<CltInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
