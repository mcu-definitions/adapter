/**
 * @file pin_change_group.hpp
 * @brief Pin-change interrupt group interface.
 */

#ifndef ADAPTER_EXTERNAL_PIN_CHANGE_GROUP_HPP
#define ADAPTER_EXTERNAL_PIN_CHANGE_GROUP_HPP

#include <stdint.h>

namespace adapter
{
    namespace external
    {
        /** @brief Interface for a group of pin-change interrupt sources. */
        template <typename Mask>
        class PinChangeGroup
        {
        public:
            virtual ~PinChangeGroup() {}

            /** @brief Sets the enabled pin mask for the group. */
            virtual bool set_mask(Mask mask) = 0;

            /** @brief Enables the group interrupt. */
            virtual void enable() = 0;

            /** @brief Disables the group interrupt. */
            virtual void disable() = 0;

            /** @brief Returns whether the group interrupt is pending. */
            virtual bool pending() const = 0;

            /** @brief Clears the pending group interrupt flag. */
            virtual void clear_pending() = 0;
        };
    }
}

#endif
