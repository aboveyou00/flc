#include "stdafx.h"
#include "CppUnitTest.h"
#include "../FLC/Errors.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(TestError)
	{
	public:
		
		TEST_METHOD(Test_wereErrorsReported)
		{
            Assert::IsFalse(flc::wereErrorsReported());
            flc::reportError("Error message");
            Assert::IsTrue(flc::wereErrorsReported());
		}

	};
}