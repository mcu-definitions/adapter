# ADC

## `adc::Converter`

The converter interface uses native input, reference and prescaler types supplied by the adapter, plus a result type.

Required operations:

- `configure(reference, prescaler)`
- `select_input(input)`
- `start_conversion()`
- `conversion_complete()`
- `read_result()`
- `resolution_bits()`

`read_result()` returns the raw conversion result. Conversion to voltage or engineering units belongs to a higher-level library or application.

## `adc::TriggerControl`

Optional interface for converters that support selectable trigger sources.
