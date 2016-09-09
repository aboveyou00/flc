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
template <typename T>
void ExpectInstr(T *instr)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    Assert::IsNotNull(instr);
    Assert::AreSame(__expectInstr(), instr);
}

template <typename TInstr, typename TDecorator>
TDecorator *ExpectDecorator(TInstr *instr, std::string str)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    Assert::IsNotNull(instr);

    auto &decorators = instr->getDecorators();
    for (size_t q = 0; q < decorators.size(); q++)
    {
        auto tdecor = dynamic_cast<TDecorator*>(decorators[q]);
        if (tdecor != nullptr && (str.empty() || str.compare(tdecor->toString()) == 0)) return tdecor;
    }

    Assert::IsTrue(false);
}
template <typename TInstr, typename TDecorator>
TDecorator *ExpectDecorator(TInstr *instr)
{
    return ExpectDecorator(instr, "");
}
template <typename TInstr, typename TDecorator>
void ExpectDecorator(TInstr *instr, TDecorator *decorator)
{
    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    Assert::IsNotNull(instr);
    Assert::IsNotNull(decorator);

    auto &decorators = instr->getDecorators();
    for (size_t q = 0; q < decorators.size(); q++)
    {
        if (decorators[q] == decorator) return;
    }

    Assert::IsTrue(false);
}

void ExpectNoMore();
