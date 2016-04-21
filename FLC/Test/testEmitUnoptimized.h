#pragma once
#include <string>
#include "CppUnitTest.h"
#include "../FLC/AllInstrs.h"

using namespace flc::emit;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void UseString(std::string str);

flc::emit::Instr *__expectInstr();
template <typename T>
T *ExpectInstr(std::string str)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    auto instr = dynamic_cast<T*>(__expectInstr());
    Assert::IsNotNull(instr);

    if (!str.empty()) Assert::IsTrue(str.compare(instr->toString()) == 0);

    return instr;
}
template <typename T>
T *ExpectInstr()
{
    return ExpectInstr<T>("");
}

void ExpectNoMore();
