/**
 * @file controller.hpp
 * @brief Watchdog controller interface.
 */

#ifndef ADAPTER_WATCHDOG_CONTROLLER_HPP
#define ADAPTER_WATCHDOG_CONTROLLER_HPP

#include "types.hpp"

namespace adapter
{
    namespace watchdog
    {
        /**
         * @brief Interface for a watchdog controller.
         *
         * The adapter supplies the native timeout selection type.
         */
        template <typename Timeout>
        class Controller
        {
        public:
            virtual ~Controller() {}

            /** @brief Configures the timeout and operating mode. */
            virtual bool configure(Timeout timeout, Mode mode) = 0;

            /** @brief Services the watchdog. */
            virtual void kick() = 0;

            /** @brief Disables the watchdog when supported and permitted. */
            virtual bool disable() = 0;
        };
    }
}

#endif
