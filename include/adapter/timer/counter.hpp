/**
 * @file counter.hpp
 * @brief Timer/counter interface.
 */

#ifndef ADAPTER_TIMER_COUNTER_HPP
#define ADAPTER_TIMER_COUNTER_HPP

namespace adapter
{
    namespace timer
    {
        /**
         * @brief Interface for a hardware timer/counter.
         *
         * Native counter, mode, clock and compare-channel types are supplied
         * by the adapter.
         */
        template <
            typename Value,
            typename Mode,
            typename Clock,
            typename CompareChannel>
        class Counter
        {
        public:
            virtual ~Counter() {}

            /** @brief Configures the timer mode and clock source. */
            virtual bool configure(Mode mode, Clock clock) = 0;

            /** @brief Starts the timer. */
            virtual void start() = 0;

            /** @brief Stops the timer. */
            virtual void stop() = 0;

            /** @brief Sets the current counter value. */
            virtual bool set_value(Value value) = 0;

            /** @brief Returns the current counter value. */
            virtual Value value() const = 0;

            /** @brief Sets a compare-channel value. */
            virtual bool set_compare(
                CompareChannel channel,
                Value value) = 0;
        };

        /**
         * @brief Optional interface for timer input capture.
         */
        template <typename Value>
        class InputCapture
        {
        public:
            virtual ~InputCapture() {}

            /** @brief Returns whether a capture value is available. */
            virtual bool capture_ready() const = 0;

            /** @brief Returns the captured counter value. */
            virtual Value captured_value() = 0;
        };
    }
}

#endif
