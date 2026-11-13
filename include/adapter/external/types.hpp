/**
 * @file types.hpp
 * @brief Common external interrupt types.
 */

#ifndef ADAPTER_EXTERNAL_TYPES_HPP
#define ADAPTER_EXTERNAL_TYPES_HPP

#include <stdint.h>

namespace adapter
{
    namespace external
    {
        /** @brief External interrupt trigger condition. */
        enum class Trigger : uint8_t
        {
            LowLevel,
            AnyChange,
            FallingEdge,
            RisingEdge
        };
    }
}

#endif
