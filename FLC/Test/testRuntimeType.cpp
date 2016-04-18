#include "stdafx.h"
#include "CppUnitTest.h"
#include "../FLC/RuntimeType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
    TEST_CLASS(TestRuntimeType)
    {
    public:

        TEST_METHOD(Test_RuntimeType_getName)
        {
            auto int32 = flc::types::RuntimeType::int32();
            Assert::IsTrue(int32->getQualifiedName().compare("System::Int32") == 0);
            Assert::IsTrue(int32->getName().compare("Int32") == 0);
        }

    };
}
