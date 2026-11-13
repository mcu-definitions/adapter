# PWM

## `pwm::Channel`

The channel interface uses native waveform mode and duty types supplied by the adapter.

Required operations:

- `configure(mode, frequency_hz)`
- `enable()`
- `disable()`
- `set_duty(duty)`
- `resolution_bits()`

The adapter reports unsupported mode, frequency or duty combinations by returning `false`.

## `pwm::PolarityControl`

Optional interface for hardware with configurable output polarity.
