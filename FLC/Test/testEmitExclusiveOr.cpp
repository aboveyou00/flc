#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitExclusiveOr)
    {
    public:
        TEST_METHOD(Test_emit_xorInt32)
        {
            UseString("95 ^ 58");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 95);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 58);
            ExpectInstr<XorInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_xor_leftAssociative)
        {
            UseString("12 ^ 13 ^ 14");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 12);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 13);
            ExpectInstr<XorInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 14);
            ExpectInstr<XorInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
