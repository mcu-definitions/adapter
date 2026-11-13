# Architecture

## Responsibilities

This repository defines hardware-independent interfaces for device-specific adapters. It does not describe or implement a specific device.

The architecture separates three responsibilities:

1. **Hardware definitions** describe the registers, pins, peripherals, memory and capabilities of one device.
2. **Adapters** implement the interfaces in this repository using one hardware definitions package.
3. **Peripheral libraries** consume these interfaces without depending directly on a specific hardware definitions package.

## Dependencies

- Hardware definitions do not depend on this repository.
- This repository does not depend on hardware definitions or device-specific adapters.
- A device-specific adapter depends on this repository and on the definitions package it adapts.
- A peripheral library depends on the interfaces and receives an adapter implementation.

## MCU objects

A device-specific adapter may define an `MCU` class containing its available peripherals. The application constructs it directly:

```cpp
MCU mcu;
auto& adc = mcu.adc();
```

This repository specifies no MCU construction mechanism or common set of peripheral accessors. Those details belong to the device-specific adapter. See [MCU composition](mcu.md).

## Runtime use

The interfaces use pure virtual functions. A concrete adapter implements the relevant interface and can be instantiated as a local or static object. A peripheral library receives a reference to the interface.

Dynamic allocation is not required. Calls through interface references use virtual dispatch.

## Design rules

- Interfaces describe required behaviour, not register layouts.
- No device names, register addresses or hardware implementations belong here.
- Adapters reuse existing definitions; they do not duplicate hardware facts.
- Native types are used where options vary between devices.
- Optional hardware features use separate interfaces.
- A device does not implement an optional interface for a feature it does not support.
- C++11 is the minimum language standard.
