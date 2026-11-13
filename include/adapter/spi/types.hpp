/**
 * @file types.hpp
 * @brief Common SPI types.
 */

#ifndef ADAPTER_SPI_TYPES_HPP
#define ADAPTER_SPI_TYPES_HPP

#include <stdint.h>

namespace adapter
{
    namespace spi
    {
        /** @brief SPI clock polarity and phase. */
        enum class Mode : uint8_t
        {
            Mode0,
            Mode1,
            Mode2,
            Mode3
        };

        /** @brief Bit transfer order. */
        enum class BitOrder : uint8_t
        {
            MostSignificantFirst,
            LeastSignificantFirst
        };

        /** @brief Controller role. */
        enum class Role : uint8_t
        {
            Master,
            Slave
        };
    }
}

#endif
