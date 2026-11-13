/**
 * @file trigger.hpp
 * @brief Optional ADC trigger interface.
 */

#ifndef ADAPTER_ADC_TRIGGER_HPP
#define ADAPTER_ADC_TRIGGER_HPP

namespace adapter
{
    namespace adc
    {
        /**
         * @brief Interface for converters with selectable trigger sources.
         *
         * The adapter supplies its native trigger selection type.
         */
        template <typename Trigger>
        class TriggerControl
        {
        public:
            virtual ~TriggerControl() {}

            /** @brief Selects the conversion trigger source. */
            virtual bool set_trigger(Trigger trigger) = 0;
        };
    }
}

#endif
