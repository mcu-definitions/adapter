/**
 * @file memory.hpp
 * @brief Non-volatile memory interface.
 */

#ifndef ADAPTER_EEPROM_MEMORY_HPP
#define ADAPTER_EEPROM_MEMORY_HPP

#include <stdint.h>

namespace adapter
{
    namespace eeprom
    {
        /**
         * @brief Interface for byte-addressable non-volatile memory.
         */
        template <typename Address, typename Data>
        class Memory
        {
        public:
            virtual ~Memory() {}

            /** @brief Returns the memory capacity in bytes. */
            virtual uint32_t size_bytes() const = 0;

            /** @brief Returns whether the memory can accept an operation. */
            virtual bool ready() const = 0;

            /** @brief Reads one byte from the supplied address. */
            virtual bool read(Address address, Data &value) = 0;

            /** @brief Writes one byte to the supplied address. */
            virtual bool write(Address address, Data value) = 0;

            /** @brief Waits until the current write operation completes. */
            virtual void wait_ready() = 0;
        };
    }
}

#endif
