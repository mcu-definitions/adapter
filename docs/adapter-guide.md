# Adapter guide

## Implementing an interface

Include the relevant module header, derive the adapter class from the interface, and implement each pure virtual method.

For example, an ADC adapter supplies its native types as template arguments:

```cpp
#include <adapter/adc.hpp>

class DeviceADC :
    public adapter::adc::Converter<
        NativeInput,
        NativeReference,
        NativePrescaler,
        uint16_t
    >
{
public:
    bool configure(
        NativeReference reference,
        NativePrescaler prescaler
    ) override;

    bool select_input(NativeInput input) override;
    void start_conversion() override;
    bool conversion_complete() const override;
    uint16_t read_result() override;
    uint8_t resolution_bits() const override;
};
```

The declarations above must be implemented by the adapter.

## Check the adapter

After the class definition, require it to be concrete:

```cpp
#include <type_traits>

static_assert(
    !std::is_abstract<DeviceADC>::value,
    "ADC adapter is incomplete."
);
```

The check verifies that all inherited pure virtual methods have implementations with matching signatures.

## Use without dynamic allocation

A concrete adapter can be an automatic or static object:

```cpp
DeviceADC adc;
```

A peripheral library can receive it by reference to the interface:

```cpp
typedef adapter::adc::Converter<
    NativeInput,
    NativeReference,
    NativePrescaler,
    uint16_t
> ADCInterface;

void read_sensor(ADCInterface& adc);
```

No heap allocation is required. Calls through the interface use virtual dispatch.

## Group peripherals in an MCU

Each device-specific adapter can define an MCU class with accessors for its supported peripherals:

```cpp
class MCU
{
public:
    DeviceADC& adc()
    {
        return adc_;
    }

private:
    DeviceADC adc_;
};
```

The application creates the MCU directly:

```cpp
MCU mcu;

auto& adc = mcu.adc();
```

No extra MCU creation interface is necessary. The MCU and its peripheral lifetimes belong to the device-specific adapter. See [MCU composition](mcu.md).
