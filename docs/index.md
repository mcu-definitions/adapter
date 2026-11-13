# Adapter

Hardware-independent C++11 interfaces for MCU adapters.

This repository defines peripheral contracts. Device-specific adapters implement these interfaces using their hardware definitions. Reusable peripheral libraries depend on the contracts, not on a particular microcontroller.

## Getting started

- [Getting started](getting-started.md) - implement an ADC contract and construct an `MCU` directly.
- [Adapter guide](adapter-guide.md) - inheritance, `override`, and interface checks.
- [MCU composition](mcu.md) - group supported peripherals in an `MCU` class.

## Design

- [Architecture](architecture.md) - how hardware definitions, contracts, adapters, and libraries relate.
- [Contract rules](contract-rules.md) - interface and naming conventions.
- [Module reference](modules.md) - overview of available interfaces.

## Peripheral modules

| Module | Documentation | Module | Documentation |
| --- | --- | --- | --- |
| ADC | [ADC](modules/adc.md) | GPIO | [GPIO](modules/gpio.md) |
| PWM | [PWM](modules/pwm.md) | Timer | [Timer](modules/timer.md) |
| Serial | [Serial](modules/serial.md) | SPI | [SPI](modules/spi.md) |
| I2C | [I2C](modules/i2c.md) | EEPROM | [EEPROM](modules/eeprom.md) |
| Watchdog | [Watchdog](modules/watchdog.md) | External interrupts | [External](modules/external.md) |
| Comparator | [Comparator](modules/comparator.md) | Interrupts | [Interrupt](modules/interrupt.md) |
| Clock | [Clock](modules/clock.md) | Power | [Power](modules/power.md) |
| Reset | [Reset](modules/reset.md) | | |

## C++ API

The generated site also provides **Classes**, **Namespaces**, and **Files** navigation for the interfaces declared in `include/adapter/`.

```cpp
#include <adapter/adc.hpp>
#include <adapter/gpio.hpp>
```

The interfaces are header-only and require C++11 or later. Each adapter implements only the contracts supported by its device. `MCU` objects use normal C++ construction; no factory or `make()` contract is required.
