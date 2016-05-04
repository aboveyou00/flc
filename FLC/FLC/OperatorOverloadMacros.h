#pragma once

#include "RuntimeType.h"
#include "MethodGroup.h"
#include "SpecialMethodOverload.h"
#include "MethodBody.h"

//Unary
#define __addOverload1(type) arg[0] = types::RuntimeType::##type(); \
                             overloads->addOverload(types::RuntimeType::##type(), arg, 1)
#define __addOverload1_alt(rettype, type1) arg[0] = types::RuntimeType::##type1(); \
                                           overloads->addOverload(types::RuntimeType::##rettype(), arg, 1)

//Binary
#define __addOverload2(type) args[0] = types::RuntimeType::##type(); args[1] = types::RuntimeType::##type(); \
                             overloads->addOverload(types::RuntimeType::##type(), args, 2)
#define __addOverload2_alt(rettype, type1, type2) args[0] = types::RuntimeType::##type1(); args[1] = types::RuntimeType::##type2(); \
                                                  overloads->addOverload(types::RuntimeType::##rettype(), args, 2)

//Cast
#define __addCast(type, rettype) args[0] = types::RuntimeType::##type(); \
                                 overloads->addOverload(types::RuntimeType::##rettype(), args, 1)
