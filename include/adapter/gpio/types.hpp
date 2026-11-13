/**
 * @file types.hpp
 * @brief Common GPIO types.
 */

#ifndef ADAPTER_GPIO_TYPES_HPP
#define ADAPTER_GPIO_TYPES_HPP

#include <stdint.h>

namespace adapter
{
    namespace gpio
    {
        /** @brief Pin direction. */
        enum class Direction : uint8_t
        {
            Input,
            Output
        };

        /** @brief Digital logic level. */
        enum class Level : uint8_t
        {
            Low,
            High
        };

        /** @brief Internal pull configuration. */
        enum class Pull : uint8_t
        {
            None,
            Up,
            Down
        };
    }
}

#endif
