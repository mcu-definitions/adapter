/**
 * @file controller.hpp
 * @brief SPI controller interface.
 */

#ifndef ADAPTER_SPI_CONTROLLER_HPP
#define ADAPTER_SPI_CONTROLLER_HPP

#include <stdint.h>
#include "types.hpp"

namespace adapter
{
    namespace spi
    {
        /**
         * @brief Interface for an SPI controller.
         *
         * The adapter supplies a data type matching the supported transfer
         * width.
         */
        template <typename Data>
        class Controller
        {
        public:
            virtual ~Controller() {}

            /** @brief Configures the SPI transfer. */
            virtual bool configure(
                Mode mode,
                BitOrder bit_order,
                Role role,
                uint32_t clock_hz) = 0;

            /** @brief Returns whether a transfer can be started. */
            virtual bool ready() const = 0;

            /**
             * @brief Exchanges one data word.
             * @param transmitted Data to send.
             * @param received Receives the data returned by the peripheral.
             */
            virtual bool transfer(Data transmitted, Data &received) = 0;
        };
    }
}

#endif
