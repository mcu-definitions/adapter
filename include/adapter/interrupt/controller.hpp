/**
 * @file controller.hpp
 * @brief Global interrupt controller interface.
 */

#ifndef ADAPTER_INTERRUPT_CONTROLLER_HPP
#define ADAPTER_INTERRUPT_CONTROLLER_HPP

namespace adapter
{
    namespace interrupt
    {
        /** @brief Interface for global interrupt control. */
        class Controller
        {
        public:
            virtual ~Controller() {}

            /** @brief Enables global interrupts. */
            virtual void enable() = 0;

            /** @brief Disables global interrupts. */
            virtual void disable() = 0;

            /** @brief Returns whether global interrupts are enabled. */
            virtual bool enabled() const = 0;
        };
    }
}

#endif
