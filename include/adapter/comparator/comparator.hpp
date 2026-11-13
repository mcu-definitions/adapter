/**
 * @file comparator.hpp
 * @brief Analog comparator interface.
 */

#ifndef ADAPTER_COMPARATOR_COMPARATOR_HPP
#define ADAPTER_COMPARATOR_COMPARATOR_HPP

#include "types.hpp"

namespace adapter
{
    namespace comparator
    {
        /**
         * @brief Interface for an analog comparator.
         *
         * The adapter supplies the native input selection type.
         */
        template <typename Input>
        class Comparator
        {
        public:
            virtual ~Comparator() {}

            /** @brief Configures the comparator inputs and interrupt mode. */
            virtual bool configure(
                Input positive,
                Input negative,
                InterruptMode mode) = 0;

            /** @brief Enables the comparator. */
            virtual void enable() = 0;

            /** @brief Disables the comparator. */
            virtual void disable() = 0;

            /** @brief Returns the current comparator output state. */
            virtual bool output() const = 0;

            /** @brief Returns whether a comparator interrupt is pending. */
            virtual bool interrupt_pending() const = 0;

            /** @brief Clears the comparator interrupt flag. */
            virtual void clear_interrupt() = 0;
        };
    }
}

#endif
