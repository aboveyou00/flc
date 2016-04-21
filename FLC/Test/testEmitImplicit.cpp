#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitImplicit)
    {
    public:
        TEST_METHOD(Test_emit_impInt32Float64)
        {
            UseString("2 + 5 * 9.4d - 3");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<ConvR8Instr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<ConvR8Instr>();
            Assert::AreEqual(ExpectInstr<LdcR8Instr>()->getConstantValue(), 9.4);
            ExpectInstr<MulInstr>();
            ExpectInstr<AddInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<ConvR8Instr>();
            ExpectInstr<SubInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
