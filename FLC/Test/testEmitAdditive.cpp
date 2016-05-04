#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"
#include "../FLC/RuntimeType.h"

namespace Test
{
    TEST_CLASS(TestEmitAdditive)
    {
    public:
        TEST_METHOD(Test_emit_addInt32)
        {
            UseString("2 + 3");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<AddInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_subInt32)
        {
            UseString("5 - 4");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<SubInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_addInt32Int64)
        {
            UseString("32 + 0xFFFFFFFFL");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 32);
            ExpectInstr<ConvI8Instr>();
            Assert::IsTrue(ExpectInstr<LdcI8Instr>()->getConstantValue() == (int64_t)0xFFFFFFFFLL);
            ExpectInstr<AddInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_add_leftAssociative)
        {
            UseString("1 + 2 + 3");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            ExpectInstr<AddInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<AddInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_add_opPrecedence)
        {
            UseString("4 + 2 * 3");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<MulInstr>();
            ExpectInstr<AddInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_add_opPrecedence_mulLhs)
        {
            UseString("6 * 3 - 4");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 6);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 3);
            ExpectInstr<MulInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 4);
            ExpectInstr<SubInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_add_opPrecedence_divLhs)
        {
            UseString("30 / 10 + 5");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 30);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 10);
            ExpectInstr<DivInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<AddInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_addString)
        {
            UseString("\"one\" + \"two\"");

            Assert::IsTrue(false);

            Assert::IsTrue(ExpectInstr<LdstrInstr>()->getValue().compare("one") == 0);
            Assert::IsTrue(ExpectInstr<LdstrInstr>()->getValue().compare("two") == 0);
            //ExpectInstr<CallInstr>(); //Sytem.String [mscorlib]System.String::concat(string, string)
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_addStringInt32)
        {
            UseString("\"one\" != 2");

            Assert::IsTrue(false);

            Assert::IsTrue(ExpectInstr<LdstrInstr>()->getValue().compare("one") == 0);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 2);
            Assert::IsTrue(ExpectInstr<BoxInstr>()->getBoxType()->isSameAs(flc::types::RuntimeType::int32()));
            //ExpectInstr<CallInstr>(); //Sytem.String [mscorlib]System.String::concat(string, string)
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
