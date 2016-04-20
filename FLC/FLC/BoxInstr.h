#pragma once
#include "Instr.h"
#include "RuntimeType.h"

namespace flc
{
    namespace emit
    {
        class BoxInstr : public Instr
        {
        public:
            BoxInstr(types::RuntimeType *type);
            ~BoxInstr();

            types::RuntimeType *getBoxType();

            void stringify(std::stringstream *stream) override;

        private:
            types::RuntimeType *boxType;
        };
    }
}

//8C <type>   box <type>
