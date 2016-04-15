#pragma once

//Unary
#define __addOverload1(type) overloads->addOverload(types::RuntimeType::##type, &types::RuntimeType::##type, 1)

//Binary
#define __addOverload2(type) args[0] = types::RuntimeType::##type; args[1] = types::RuntimeType::##type; \
                             overloads->addOverload(types::RuntimeType::##type, args, 2)
#define __addOverload2_alt(type1, type2) args[0] = types::RuntimeType::##type1; args[1] = types::RuntimeType::##type2; \
                                         overloads->addOverload(types::RuntimeType::##type1, args, 2); \
                                         args[0] = types::RuntimeType::##type2; args[1] = types::RuntimeType::##type1; \
                                         overloads->addOverload(types::RuntimeType::##type1, args, 2)
