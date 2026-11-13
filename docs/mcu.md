# MCU composition

An MCU class is defined by each device-specific adapter. It groups the hardware peripherals exposed by that adapter.

The interfaces repository does not define an MCU base class or enforce a common set of peripheral accessors.

## Example

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

The `ADC` type above is the concrete peripheral adapter, which implements the required ADC interface.

Applications create the MCU using its constructor:

```cpp
MCU mcu;

ADC& adc = mcu.adc();
```

The MCU object owns its ADC in this example, so references obtained through `adc()` remain valid while the MCU exists. An adapter can choose a different lifetime strategy if necessary.

## Requirements

- Implement the peripheral interfaces using `override`.
- Expose only peripherals supported by the device.
- Keep hardware access in the concrete peripheral adapters.
- Provide a public default constructor if applications should use `MCU mcu;`.
- No separate factory class or creation helper is needed.
