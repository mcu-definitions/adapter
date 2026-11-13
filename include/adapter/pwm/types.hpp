/**
 * @file types.hpp
 * @brief Common PWM types.
 */

#ifndef ADAPTER_PWM_TYPES_HPP
#define ADAPTER_PWM_TYPES_HPP

#include <stdint.h>

namespace adapter
{
    namespace pwm
    {
        /** @brief PWM output polarity. */
        enum class Polarity : uint8_t
        {
            Normal,
            Inverted
        };
    }
}

#endif
