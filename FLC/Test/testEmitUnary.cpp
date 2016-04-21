#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitUnary)
    {
    public:
        TEST_METHOD(Test_emit_unaryPlusInt32)
        {
            UseString("+4");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_negInt32)
        {
            UseString("-4");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<NegInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_notInt32)
        {
            UseString("!true");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            ExpectInstr<CeqInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_complementInt32)
        {
            UseString("~357");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 357);
            ExpectInstr<NotInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_unary_rightAssociative)
        {
            UseString("-~25");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 25);
            ExpectInstr<NotInstr>();
            ExpectInstr<NegInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_unary_opPrecedence)
        {
            UseString("~5 * 5 * 5");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<NotInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<MulInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_unary_parenthesized)
        {
            UseString("~(5 * 5 * 5)");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<MulInstr>();
            ExpectInstr<NotInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_unary_onNewLine)
        {
            UseString("    3 % 2    \r\n    -4    \r\n    +4    ");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<RemInstr>();
            ExpectInstr<PopInstr>();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<NegInstr>();
            ExpectInstr<PopInstr>();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_notunary_onSameLine)
        {
            UseString("    3 % 2 - 4 + 4    ");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<RemInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<SubInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<AddInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
