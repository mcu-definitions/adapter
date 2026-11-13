/**
 * @file types.hpp
 * @brief Common analog comparator types.
 */

#ifndef ADAPTER_COMPARATOR_TYPES_HPP
#define ADAPTER_COMPARATOR_TYPES_HPP

#include <stdint.h>

namespace adapter
{
    namespace comparator
    {
        /** @brief Comparator interrupt condition. */
        enum class InterruptMode : uint8_t
        {
            Toggle,
            FallingEdge,
            RisingEdge
        };
    }
}

#endif
