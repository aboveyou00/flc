#include "stdafx.h"
#include "MethodGroup.h"
#include <cstdarg>

namespace flc
{
    namespace types
    {
        MethodGroup::MethodGroup(std::string name)
            : MethodGroup(name, nullptr, 0)
        {
        }
        MethodGroup::MethodGroup(std::string name, std::vector<MethodOverload*>* overloads)
            : MethodGroup(name, &(*overloads)[0], overloads->size())
        {
        }
        MethodGroup::MethodGroup(std::string name, MethodOverload** overloads, int overloadCount)
            : _name(name)
        {
            for (int q = 0; q < overloadCount; q++)
            {
                _overloads.push_back(overloads[q]);
            }
        }
        MethodGroup::~MethodGroup()
        {
        }

        std::string MethodGroup::getName()
        {
            return _name;
        }
        NameType MethodGroup::getNameType()
        {
            return NameType::Member;
        }

        int MethodGroup::getOverloadCount()
        {
            return (int)_overloads.size();
        }
        MethodOverload* MethodGroup::getOverload(int idx)
        {
            //Let vector handle invalid indexes
            return _overloads.at(idx);
        }

        MethodOverload* MethodGroup::findOverload(RuntimeType** parameters, int parameterCount)
        {
            return findOverload(nullptr, parameters, parameterCount);
        }
        MethodOverload* MethodGroup::findOverload(RuntimeType* returnType, RuntimeType** parameters, int parameterCount)
        {
            for (int q = 0; q < getOverloadCount(); q++)
            {
                auto overload = getOverload(q);
                if (returnType != nullptr && !overload->getReturnType()->isSameAs(returnType)) continue;
                if (overload->isMatchForParameters(parameters, parameterCount)) return overload;
            }
            return nullptr;
        }
        MethodOverload* MethodGroup::findOverload(RuntimeType* returnType, ParameterInfo** parameters, int parameterCount)
        {
            for (int q = 0; q < getOverloadCount(); q++)
            {
                auto overload = getOverload(q);
                if (!overload->getReturnType()->isSameAs(returnType)) continue;
                if (overload->getParameterCount() != parameterCount) continue;
                bool allSameParams = true;
                for (int w = 0; w < parameterCount; w++)
                {
                    if (!overload->getParameterInfo(w)->isSameAs(parameters[w]))
                    {
                        allSameParams = false;
                        break;
                    }
                }
                if (allSameParams) return overload;
            }
            return nullptr;
        }

        MethodOverload* MethodGroup::addOverload(RuntimeType* returnType, RuntimeType** parameters, int parameterCount)
        {
            //TODO: GC?
            ParameterInfo** params = new ParameterInfo*[parameterCount];
            for (int q = 0; q < parameterCount; q++)
            {
                params[q] = new ParameterInfo(parameters[q]);
            }
            return addOverload(returnType, params, parameterCount);
        }
        MethodOverload* MethodGroup::addOverload(RuntimeType* returnType, ParameterInfo** parameters, int parameterCount)
        {
            auto oldOverload = findOverload(returnType, parameters, parameterCount);
            if (oldOverload != nullptr) throw std::string("You tried to add a duplicate method overload to a method group!");

            auto new_overload = new MethodOverload(returnType, parameters, parameterCount);
            _overloads.push_back(new_overload);
            return new_overload;
        }
    }
}
