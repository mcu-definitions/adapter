# Getting started

This repository provides **interfaces**, not hardware implementations. A device-specific adapter implements the interfaces and exposes its peripherals through an `MCU` object.

## 1. Include the interface

Add this repository's `include/` directory to your compiler include paths. For an ADC:

```cpp
#include <adapter/adc.hpp>
```

## 2. Implement the ADC contract

The `Converter` interface requires four types: input, reference, prescaler and result. A real adapter obtains the first three from its device's hardware definitions.

```cpp
class ADC : public adapter::adc::Converter<
    Input, Reference, Prescaler, uint16_t
>
{
public:
    bool configure(Reference, Prescaler) override;
    bool select_input(Input) override;
    void start_conversion() override;
    bool conversion_complete() const override;
    uint16_t read_result() override;
    uint8_t resolution_bits() const override;
};
```

Implement each declared method using the device's hardware definitions and registers. The compiler requires every pure virtual method to be implemented before `ADC` can be instantiated; `override` checks the method signatures.

## 3. Group peripherals in the MCU

The device-specific adapter can own its peripheral objects in an `MCU` class:

```cpp
class MCU
{
public:
    ADC& adc()
    {
        return adc_;
    }

private:
    ADC adc_;
};
```

The adapter defines `MCU`; this repository does not prescribe its peripheral list.

## 4. Construct and use the MCU

No factory or `make()` is needed:

```cpp
MCU mcu;
auto& adc = mcu.adc();

adc.configure(Reference::Supply, Prescaler::Div128);
adc.select_input(Input::A0);
adc.start_conversion();

while (!adc.conversion_complete()) {}

uint16_t value = adc.read_result();
```

The `Input`, `Reference` and `Prescaler` names above refer to types supplied by the device-specific adapter.

## 5. Run a complete example

[`examples/getting-started.cpp`](../examples/getting-started.cpp) is a complete C++11 example. It uses a **simulated ADC** to demonstrate the contract and MCU construction; it does **not** configure real hardware.

From the repository root, compile it with a C++11 compiler:

```sh
g++ -std=c++11 -Wall -Wextra -pedantic -Iinclude examples/getting-started.cpp -o getting-started
./getting-started
```

Expected output:

```text
ADC: 512
```

In a real device-specific adapter, replace the simulated behaviour with register operations and native hardware types. The `adapter` repository itself stays hardware-independent.

## Next

- [Adapter guide](adapter-guide.md) — interface implementation and compile-time checks
- [MCU composition](mcu.md) — peripheral ownership and lifetime
- [Modules](modules.md) — available contracts and optional capabilities
