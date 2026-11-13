/**
 * @file types.hpp
 * @brief Common serial frame types.
 */

#ifndef ADAPTER_SERIAL_TYPES_HPP
#define ADAPTER_SERIAL_TYPES_HPP

#include <stdint.h>

namespace adapter
{
    namespace serial
    {
        /** @brief Serial transfer mode. */
        enum class Mode : uint8_t
        {
            Asynchronous,
            Synchronous
        };

        /** @brief Number of data bits per frame. */
        enum class DataBits : uint8_t
        {
            Five = 5,
            Six = 6,
            Seven = 7,
            Eight = 8,
            Nine = 9
        };

        /** @brief Frame parity. */
        enum class Parity : uint8_t
        {
            None,
            Even,
            Odd
        };

        /** @brief Number of stop bits. */
        enum class StopBits : uint8_t
        {
            One = 1,
            Two = 2
        };
    }
}

#endif
