/**
 * @file sleep.hpp
 * @brief Sleep mode interface.
 */

#ifndef ADAPTER_POWER_SLEEP_HPP
#define ADAPTER_POWER_SLEEP_HPP

namespace adapter
{
    namespace power
    {
        /**
         * @brief Interface for entering a supported sleep mode.
         *
         * The adapter supplies the native sleep mode type.
         */
        template <typename Mode>
        class SleepController
        {
        public:
            virtual ~SleepController() {}

            /** @brief Enters the selected sleep mode. */
            virtual bool enter(Mode mode) = 0;
        };
    }
}

#endif
