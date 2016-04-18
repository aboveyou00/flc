#include "stdafx.h"
#include "NameResolutionContextStack.h"

namespace flc
{
    namespace types
    {
        NameResolutionContextStack::NameResolutionContextStack()
        {
        }
        NameResolutionContextStack::~NameResolutionContextStack()
        {
        }

        INameInfo *NameResolutionContextStack::resolveName(std::string name, NameType)
        {
            return nullptr;
        }
    }
}
