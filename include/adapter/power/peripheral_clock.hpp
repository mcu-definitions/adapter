/**
 * @file peripheral_clock.hpp
 * @brief Peripheral clock control interface.
 */

#ifndef ADAPTER_POWER_PERIPHERAL_CLOCK_HPP
#define ADAPTER_POWER_PERIPHERAL_CLOCK_HPP

namespace adapter
{
    namespace power
    {
        /**
         * @brief Optional interface for peripheral clock gating.
         *
         * The adapter supplies the native peripheral identifier type.
         */
        template <typename Peripheral>
        class PeripheralClockControl
        {
        public:
            virtual ~PeripheralClockControl() {}

            /** @brief Enables or disables a peripheral clock. */
            virtual bool set_enabled(
                Peripheral peripheral,
                bool enabled) = 0;
        };
    }
}

#endif
