#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitInclusiveOr)
    {
    public:
        TEST_METHOD(Test_emit_orInt32)
        {
            UseString("32 | 63");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 32);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 63);
            ExpectInstr<OrInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_or_leftAssociative)
        {
            UseString("1 | 2 | 4");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<OrInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<OrInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
