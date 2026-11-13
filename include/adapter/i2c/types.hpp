/**
 * @file types.hpp
 * @brief Common I2C types and status values.
 */

#ifndef ADAPTER_I2C_TYPES_HPP
#define ADAPTER_I2C_TYPES_HPP

#include <stdint.h>

namespace adapter
{
    namespace i2c
    {
        /** @brief Bus controller role. */
        enum class Role : uint8_t
        {
            Master,
            Slave
        };

        /** @brief Response after a received byte. */
        enum class Response : uint8_t
        {
            Ack,
            Nack
        };

        /** @brief Common bus operation status. */
        enum class Status : uint8_t
        {
            Success,
            Busy,
            AddressNack,
            DataNack,
            ArbitrationLost,
            BusError,
            Timeout,
            Error
        };
    }
}

#endif
