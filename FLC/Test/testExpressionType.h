#pragma once
#include <string>
#include "../FLC/RuntimeType.h"

void testExpressionType(const std::string& expression, flc::types::RuntimeType* expectedType);
void testExpressionType(const std::string& expression, flc::types::RuntimeType* expectedType, flc::types::RuntimeType* suggestedType);
