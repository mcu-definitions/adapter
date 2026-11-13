/**
 * @file channel.hpp
 * @brief PWM channel interface.
 */

#ifndef ADAPTER_PWM_CHANNEL_HPP
#define ADAPTER_PWM_CHANNEL_HPP

#include <stdint.h>
#include "types.hpp"

namespace adapter
{
    namespace pwm
    {
        /**
         * @brief Interface for one PWM output channel.
         *
         * The adapter supplies the native waveform mode and duty value types.
         */
        template <typename Mode, typename Duty>
        class Channel
        {
        public:
            virtual ~Channel() {}

            /** @brief Configures the waveform mode and output frequency. */
            virtual bool configure(
                Mode mode,
                uint32_t frequency_hz) = 0;

            /** @brief Enables the PWM output. */
            virtual void enable() = 0;

            /** @brief Disables the PWM output. */
            virtual void disable() = 0;

            /** @brief Sets the output duty value. */
            virtual bool set_duty(Duty duty) = 0;

            /** @brief Returns the duty resolution in bits. */
            virtual uint8_t resolution_bits() const = 0;
        };

        /**
         * @brief Optional interface for configurable output polarity.
         */
        class PolarityControl
        {
        public:
            virtual ~PolarityControl() {}

            /** @brief Sets the PWM output polarity. */
            virtual bool set_polarity(Polarity polarity) = 0;
        };
    }
}

#endif
