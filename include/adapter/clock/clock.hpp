/**
 * @file clock.hpp
 * @brief Clock interface.
 */

#ifndef ADAPTER_CLOCK_CLOCK_HPP
#define ADAPTER_CLOCK_CLOCK_HPP

#include <stdint.h>

namespace adapter
{
    namespace clock
    {
        /**
         * @brief Interface for querying clock domains.
         *
         * The adapter supplies the native clock domain type.
         */
        template <typename Domain>
        class Clock
        {
        public:
            virtual ~Clock() {}

            /** @brief Returns the frequency of a clock domain in hertz. */
            virtual uint32_t frequency_hz(Domain domain) const = 0;
        };

        /**
         * @brief Optional interface for runtime clock prescaler control.
         */
        template <typename Prescaler>
        class PrescalerControl
        {
        public:
            virtual ~PrescalerControl() {}

            /** @brief Sets the clock prescaler. */
            virtual bool set_prescaler(Prescaler prescaler) = 0;
        };
    }
}

#endif
