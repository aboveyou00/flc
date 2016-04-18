#include "stdafx.h"
#include "CppUnitTest.h"
#include "../FLC/Compiler.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
    TEST_CLASS(TestCompiler)
    {
    public:

        TEST_METHOD(Test_compileTestFile)
        {
            flc::Compiler compiler;

            Assert::IsTrue(compiler.tryAddSourceFile("test.fl"));
            Assert::IsTrue(compiler.tryCompile());
        }

        TEST_METHOD(Test_compileFromString)
        {
            flc::Compiler compiler;

            Assert::IsTrue(compiler.tryAddSource("60*60*24*365 + \" seconds in a year.\""));
            Assert::IsTrue(compiler.tryCompile());
        }

    };
}
