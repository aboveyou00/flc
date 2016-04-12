#pragma once
#include <type_traits>

namespace flc
{
    namespace types
    {
        enum class NameType : int
        {
            Any = ~0,
            Member = 0b1,
            Type = 0b10
        };

        using T = std::underlying_type_t<NameType>;

        inline NameType operator | (NameType lhs, NameType rhs)
        {
            return (NameType)(static_cast<T>(lhs) | static_cast<T>(rhs));
        }
        inline NameType& operator |= (NameType& lhs, NameType rhs)
        {
            return lhs = (NameType)(static_cast<T>(lhs) | static_cast<T>(rhs));
        }
        inline NameType operator & (NameType lhs, NameType rhs)
        {
            return (NameType)(static_cast<T>(lhs) & static_cast<T>(rhs));
        }
        inline NameType& operator &= (NameType& lhs, NameType rhs)
        {
            return lhs = (NameType)(static_cast<T>(lhs) & static_cast<T>(rhs));
        }
    }
}
