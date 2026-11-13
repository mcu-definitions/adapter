/**
 * @file types.hpp
 * @brief Common watchdog modes.
 */

#ifndef ADAPTER_WATCHDOG_TYPES_HPP
#define ADAPTER_WATCHDOG_TYPES_HPP

#include <stdint.h>

namespace adapter
{
    namespace watchdog
    {
        /** @brief Watchdog action mode. */
        enum class Mode : uint8_t
        {
            Reset,
            Interrupt,
            InterruptAndReset
        };
    }
}

#endif
