#include "stdafx.h"
#include "CppUnitTest.h"
#include "testEmitUnoptimized.h"

namespace Test
{
    TEST_CLASS(TestEmitLiteral)
    {
    public:
        TEST_METHOD(Test_emit_int32)
        {
            UseString("1");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_int64)
        {
            UseString("25l");

            Assert::IsTrue(ExpectInstr<LdcI8Instr>()->getConstantValue() == (int64_t)25);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_uint32)
        {
            UseString("0xFFFFFFFFu");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), (int32_t)-1);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_uint64)
        {
            UseString("0xFFFFFFFFFFFFFFFFul");

            Assert::IsTrue(ExpectInstr<LdcI8Instr>()->getConstantValue() == (int64_t)-1);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_float32)
        {
            UseString("1.23f");

            Assert::AreEqual(ExpectInstr<LdcR4Instr>()->getConstantValue(), 1.23f);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_float64)
        {
            UseString("1.23");

            Assert::AreEqual(ExpectInstr<LdcR8Instr>()->getConstantValue(), 1.23);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_bool8)
        {
            UseString("true false");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 1);
            ExpectInstr<PopInstr>();

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), 0);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_char16)
        {
            UseString("'c'");

            Assert::AreEqual(ExpectInstr<LdcI4Instr>()->getConstantValue(), (int32_t)'c');
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_string)
        {
            UseString("\"Hello, World!\"");

            Assert::IsTrue(ExpectInstr<LdstrInstr>()->getValue().compare("Hello, World!") == 0);
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }

        TEST_METHOD(Test_emit_nullLiteral)
        {
            UseString("null");

            ExpectInstr<LdnullInstr>();
            ExpectInstr<PopInstr>();

            ExpectNoMore();
        }
    };
}
