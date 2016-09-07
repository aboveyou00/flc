#include "stdafx.h"
#include <cstdarg>
#include "MethodGroup.h"
#include "SpecialMethodOverload.h"
#include "RuntimeType.h"
#include "ParameterInfo.h"

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

        /// Note: This method uses overload resolution to find the best MethodOverload that can fit the parameter types
        /// The selected overload may be subjected to implicit conversions.
        MethodOverload* MethodGroup::findOverload(RuntimeType** parameters, int parameterCount)
        {
            return findOverload(nullptr, parameters, parameterCount);
        }
        /// Note: This method uses overload resolution to find the best MethodOverload that can fit the parameter types
        /// The selected overload may be subjected to implicit conversions.
        MethodOverload* MethodGroup::findOverload(RuntimeType* returnType, RuntimeType** parameters, int parameterCount)
        {
            std::vector<MethodOverload*> candidates;
            candidates.clear();
            for (int q = 0; q < getOverloadCount(); q++)
            {
                auto overload = getOverload(q);
                if (returnType != nullptr && !overload->getReturnType()->isSameAs(returnType)) continue;
                if (overload->isMatchForParameters(parameters, parameterCount)) candidates.push_back(overload);
            }
            if (candidates.size() == 0) return nullptr;
            if (candidates.size() == 1) return candidates[0];
            
            MethodOverload *better = candidates[0];
            for (size_t q = 1; q < candidates.size(); q++)
            {
                better = findBetterOverload(returnType, parameters, parameterCount, better, candidates[q]);
                if (better == nullptr)
                {
                    return nullptr;
                    //Ambiguous - no one overload is clearly "better"
                    //TODO: Log a useful error message
                }
            }
            return better;
        }

        /// Note: This method does not use overload resolution. It finds the only MethodOverload with exactly the same parameter types.
        /// If such a MethodOverload does not exist, nullptr is returned instead.
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

        SpecialMethodOverload* MethodGroup::addOverload(RuntimeType* returnType, RuntimeType** parameters, int parameterCount)
        {
            //TODO: GC?
            ParameterInfo** params = new ParameterInfo*[parameterCount];
            for (int q = 0; q < parameterCount; q++)
            {
                params[q] = new ParameterInfo(parameters[q]);
            }
            return addOverload(returnType, params, parameterCount);
        }
        SpecialMethodOverload* MethodGroup::addOverload(RuntimeType* returnType, ParameterInfo** parameters, int parameterCount)
        {
            auto oldOverload = findOverload(returnType, parameters, parameterCount);
            if (oldOverload != nullptr) throw std::invalid_argument("You tried to add a duplicate method overload to a method group!");

            auto new_overload = new SpecialMethodOverload(returnType, parameters, parameterCount);
            _overloads.push_back(new_overload);
            return new_overload;
        }

        MethodOverload *MethodGroup::findBetterOverload(RuntimeType *returnType, RuntimeType **parameters, int parameterCount, MethodOverload *one, MethodOverload *two)
        {
            if (one->isBetterMatch(parameters, parameterCount, two)) return one;
            else if (two->isBetterMatch(parameters, parameterCount, one)) return two;
            else return nullptr;
        }
    }
}
