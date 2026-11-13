/**
 * @file controller.hpp
 * @brief I2C controller interface.
 */

#ifndef ADAPTER_I2C_CONTROLLER_HPP
#define ADAPTER_I2C_CONTROLLER_HPP

#include <stdint.h>
#include "types.hpp"

namespace adapter
{
    namespace i2c
    {
        /**
         * @brief Interface for an I2C bus controller.
         *
         * Addresses are passed unshifted. Address validation and protocol
         * encoding are handled by the adapter.
         */
        class Controller
        {
        public:
            virtual ~Controller() {}

            /** @brief Configures the bus controller. */
            virtual bool configure(
                Role role,
                uint32_t frequency_hz,
                uint16_t own_address) = 0;

            /** @brief Starts a transaction, optionally using a repeated start. */
            virtual Status start(bool repeated) = 0;

            /** @brief Sends an address and transfer direction. */
            virtual Status send_address(
                uint16_t address,
                bool read) = 0;

            /** @brief Writes one byte to the bus. */
            virtual Status write(uint8_t value) = 0;

            /** @brief Reads one byte and sends the requested response. */
            virtual Status read(
                uint8_t &value,
                Response response) = 0;

            /** @brief Stops the current transaction. */
            virtual void stop() = 0;

            /** @brief Returns the current bus status. */
            virtual Status status() const = 0;
        };
    }
}

#endif
