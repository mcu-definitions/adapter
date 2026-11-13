/**
 * @file converter.hpp
 * @brief ADC converter interface.
 */

#ifndef ADAPTER_ADC_CONVERTER_HPP
#define ADAPTER_ADC_CONVERTER_HPP

#include <stdint.h>

namespace adapter
{
    namespace adc
    {
        /**
         * @brief Interface for an analog-to-digital converter.
         *
         * Native input, reference, prescaler and result types are supplied
         * by the adapter.
         */
        template <
            typename Input,
            typename Reference,
            typename Prescaler,
            typename Result>
        class Converter
        {
        public:
            virtual ~Converter() {}

            /** @brief Configures the converter. */
            virtual bool configure(
                Reference reference,
                Prescaler prescaler) = 0;

            /** @brief Selects the conversion input. */
            virtual bool select_input(Input input) = 0;

            /** @brief Starts a conversion. */
            virtual void start_conversion() = 0;

            /** @brief Returns whether the current conversion is complete. */
            virtual bool conversion_complete() const = 0;

            /** @brief Returns the raw conversion result. */
            virtual Result read_result() = 0;

            /** @brief Returns the configured converter resolution in bits. */
            virtual uint8_t resolution_bits() const = 0;
        };
    }
}

#endif
