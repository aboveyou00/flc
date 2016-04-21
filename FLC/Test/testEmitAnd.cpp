#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitAnd)
    {
    public:
        TEST_METHOD(Test_emit_andInt32)
        {
            UseString("42 & 99");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 42);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 99);
            ExpectInstr<AndInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_and_leftAssociative)
        {
            UseString("3851 & 29568 & 2598");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3851);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 29568);
            ExpectInstr<AndInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2598);
            ExpectInstr<AndInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_bitwise_opPrecedence)
        {
            UseString("(1 | 2 ^ 3 & 4) == 5");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<AndInstr>();
            ExpectInstr<XorInstr>();
            ExpectInstr<OrInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<CeqInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_bitwise_parenthesizedOpPrecedence)
        {
            UseString("(((1 | 2) ^ 3) & 4) == 5");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<OrInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<XorInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<AndInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<CeqInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
