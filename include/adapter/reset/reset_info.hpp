/**
 * @file reset_info.hpp
 * @brief Reset cause information interface.
 */

#ifndef ADAPTER_RESET_RESET_INFO_HPP
#define ADAPTER_RESET_RESET_INFO_HPP

namespace adapter
{
    namespace reset
    {
        /**
         * @brief Interface for reading the reset cause.
         *
         * The adapter supplies the native reset cause type.
         */
        template <typename Cause>
        class ResetInfo
        {
        public:
            virtual ~ResetInfo() {}

            /** @brief Returns the recorded reset cause. */
            virtual Cause cause() const = 0;
        };

        /**
         * @brief Optional interface for reset control operations.
         */
        template <typename Cause>
        class ResetControl
        {
        public:
            virtual ~ResetControl() {}

            /** @brief Clears the recorded reset cause flags. */
            virtual void clear_cause() = 0;

            /** @brief Requests a system reset. */
            virtual void request_reset() = 0;
        };
    }
}

#endif
