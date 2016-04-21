#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitEquality)
    {
    public:
        TEST_METHOD(Test_emit_ceqBool8)
        {
            UseString("true == false");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            ExpectInstr<CeqInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_ceqInt32)
        {
            UseString("23 == 5");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 23);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<CeqInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        //"Hello" == "World"
        //"foo" != "bar"
        TEST_METHOD(Test_emit_ceq_opPrecedence)
        {
            UseString("23 == 5 == false");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 23);
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 5);
            ExpectInstr<CeqInstr>();
            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            ExpectInstr<CeqInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_equality_string)
        {
            UseString("\"Hello\" == \"World\"");

            Assert::IsTrue(false);

            Assert::IsTrue(ExpectInstr<LdstrInstr>()->getValue().compare("Hello") == 0);
            Assert::IsTrue(ExpectInstr<LdstrInstr>()->getValue().compare("World") == 0);
            //ExpectInstr<CallInstr>(); //bool [mscorlib]System.String::op_Equality(string, string)
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_inequality_string)
        {
            UseString("\"foo\" != \"bar\"");

            Assert::IsTrue(false);

            Assert::IsTrue(ExpectInstr<LdstrInstr>()->getValue().compare("foo") == 0);
            Assert::IsTrue(ExpectInstr<LdstrInstr>()->getValue().compare("bar") == 0);
            //ExpectInstr<CallInstr>(); //bool [mscorlib]System.String::op_Inequality(string, string)
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
