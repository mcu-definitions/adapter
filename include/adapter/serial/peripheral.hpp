/**
 * @file peripheral.hpp
 * @brief Serial peripheral interface.
 */

#ifndef ADAPTER_SERIAL_PERIPHERAL_HPP
#define ADAPTER_SERIAL_PERIPHERAL_HPP

#include <stdint.h>
#include "types.hpp"

namespace adapter
{
    namespace serial
    {
        /**
         * @brief Interface for a serial communication peripheral.
         *
         * The adapter supplies a data type capable of holding the largest
         * frame supported by the peripheral.
         */
        template <typename Data>
        class Peripheral
        {
        public:
            virtual ~Peripheral() {}

            /** @brief Configures the serial frame and baud rate. */
            virtual bool configure(
                uint32_t baud_rate,
                Mode mode,
                DataBits data_bits,
                Parity parity,
                StopBits stop_bits) = 0;

            /** @brief Returns whether a frame can be transmitted. */
            virtual bool transmit_ready() const = 0;

            /** @brief Writes one frame for transmission. */
            virtual bool write(Data value) = 0;

            /** @brief Returns whether a received frame is available. */
            virtual bool receive_ready() const = 0;

            /** @brief Reads one received frame. */
            virtual Data read() = 0;

            /** @brief Returns whether the transmission is fully complete. */
            virtual bool transmission_complete() const = 0;
        };
    }
}

#endif
