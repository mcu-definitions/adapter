/**
 * @file line.hpp
 * @brief External interrupt line interface.
 */

#ifndef ADAPTER_EXTERNAL_LINE_HPP
#define ADAPTER_EXTERNAL_LINE_HPP

#include "types.hpp"

namespace adapter
{
    namespace external
    {
        /** @brief Interface for one external interrupt line. */
        class Line
        {
        public:
            virtual ~Line() {}

            /** @brief Configures the line trigger condition. */
            virtual bool configure(Trigger trigger) = 0;

            /** @brief Enables the interrupt line. */
            virtual void enable() = 0;

            /** @brief Disables the interrupt line. */
            virtual void disable() = 0;

            /** @brief Returns whether an interrupt is pending. */
            virtual bool pending() const = 0;

            /** @brief Clears the pending interrupt flag. */
            virtual void clear_pending() = 0;
        };
    }
}

#endif
