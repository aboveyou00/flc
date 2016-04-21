#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitCompound)
    {
    public:
        TEST_METHOD(Test_emit_compound_empty)
        {
            UseString("{}");

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_compound_1xint32)
        {
            UseString("{42}");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 42);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_compound_3xint32)
        {
            UseString("{1 2 3}");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            ExpectInstr<PopInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<PopInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_compound_complex)
        {
            UseString("{\r\n    1 + 2\r\n    2 * 2 * 2 * 2 * 2 * 2 * 2 * 2\r\n    42\r\n}");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<AddInstr>();
            ExpectInstr<PopInstr>();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<MulInstr>();
            ExpectInstr<PopInstr>();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 42);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
