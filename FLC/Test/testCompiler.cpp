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
            auto compiler = new flc::Compiler();

            Assert::IsTrue(compiler->tryAddSourceFile("test.fl"));
            Assert::IsTrue(compiler->tryCompile());
        }

    };
}
