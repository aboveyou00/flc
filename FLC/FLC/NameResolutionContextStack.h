#pragma once
#include "INameResolutionContext.h"

namespace flc
{
    namespace types
    {
        class NameResolutionContextStack : public INameResolutionContext
        {
        public:
            NameResolutionContextStack();
            ~NameResolutionContextStack();

            INameInfo *resolveName(std::string name, NameType nameType) override;
            //NameResolutionScope *createScope();
            //void pushScope(NameResolutionScope *scope);
            //NameResolutionScope *popScope();
        };
    }
}
