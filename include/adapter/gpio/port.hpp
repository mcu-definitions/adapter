/**
 * @file port.hpp
 * @brief GPIO port interface.
 */

#ifndef ADAPTER_GPIO_PORT_HPP
#define ADAPTER_GPIO_PORT_HPP

#include <stdint.h>
#include "types.hpp"

namespace adapter
{
    namespace gpio
    {
        /**
         * @brief Interface for a digital I/O port.
         *
         * Pin indices are zero-based. The adapter defines which indices are
         * valid for the port.
         */
        class Port
        {
        public:
            virtual ~Port() {}

            /** @brief Returns the number of bit positions in the port. */
            virtual uint8_t width() const = 0;

            /** @brief Returns whether a bit position can be used as GPIO. */
            virtual bool valid(uint8_t bit) const = 0;

            /** @brief Configures a pin direction. */
            virtual bool set_direction(
                uint8_t bit,
                Direction direction) = 0;

            /** @brief Writes a digital output level. */
            virtual bool write(uint8_t bit, Level level) = 0;

            /** @brief Reads the current digital input level. */
            virtual Level read(uint8_t bit) const = 0;
        };

        /**
         * @brief Optional interface for configurable internal pulls.
         *
         * Implement this interface only when the port supports internal
         * pull configuration.
         */
        class PullControl
        {
        public:
            virtual ~PullControl() {}

            /** @brief Configures the internal pull for a pin. */
            virtual bool set_pull(uint8_t bit, Pull pull) = 0;
        };
    }
}

#endif
