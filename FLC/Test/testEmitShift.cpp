#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitMultiplicative)
    {
    public:
        TEST_METHOD(Test_emit_shlInt32)
        {
            UseString("1 << 2");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<ShlInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_shrInt32)
        {
            UseString("4 >> 2");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<ShrInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_shift_leftAssociative)
        {
            UseString("4 >> 2 << 3");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<ShrInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<ShlInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
