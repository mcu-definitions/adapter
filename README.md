# Adapter

Hardware-independent C++11 interfaces for microcontroller adapters and peripheral libraries.

## Scope

This repository defines the interfaces that device-specific adapters implement to expose hardware through a common API. It contains contracts, not implementations.

It does not contain hardware definitions, register addresses or peripheral drivers.

- Hardware definitions describe a device.
- A device-specific adapter implements these interfaces using its hardware definitions.
- Peripheral libraries consume the interfaces without depending on a specific device.

## Getting started

Start with the [Getting Started guide](docs/getting-started.md) to implement an ADC interface, group it in an `MCU` class and construct it directly. A [complete C++11 example](examples/getting-started.cpp) is also available.

## MCU objects

A device-specific adapter can provide an `MCU` class that groups its available peripherals. Applications construct it directly:

```cpp
MCU mcu;

ADC& adc = mcu.adc();
```

The `MCU` class and its accessors belong to the device-specific adapter, not this repository. No common MCU interface or creation helper is required.

See [MCU composition](docs/mcu.md) for the recommended structure.

## Modules

- GPIO
- ADC
- PWM
- Timer
- Serial
- SPI
- I2C
- EEPROM
- Watchdog
- External interrupts
- Analog comparator
- Global interrupts
- Clock
- Power management
- Reset

Optional hardware features are represented by separate interfaces. An adapter only implements an optional interface when the hardware supports that feature.

## Requirements

- C++11 or later.
- Header-only.
- No device-specific dependencies.
- No dynamic allocation requirement.

## Include

Add `include/` to the compiler's include paths:

```cpp
#include <adapter/adapter.hpp>
```

Individual modules can be included separately:

```cpp
#include <adapter/adc.hpp>
#include <adapter/gpio.hpp>
```

## Adapter conformance

Contracts use pure virtual functions. An adapter derives from the relevant interface and implements its required methods using `override`.

A class that omits a required method remains abstract. Adapters can verify that their concrete class is not abstract:

```cpp
#include <type_traits>

static_assert(
    !std::is_abstract<MyAdapter>::value,
    "Adapter does not implement the complete interface."
);
```

This checks interface conformance at compile time. It does not verify the functional correctness of the implementation.

## Documentation

API documentation is generated with Doxygen using `Doxyfile`.

## License

See [LICENSE](LICENSE).
