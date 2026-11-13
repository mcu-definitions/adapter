# GPIO

## `gpio::Port`

The port interface requires:

- `width()`: number of bit positions.
- `valid(bit)`: whether a bit position is available as GPIO.
- `set_direction(bit, direction)`: configures input or output.
- `write(bit, level)`: writes an output level.
- `read(bit)`: reads the current input level.

Bit positions are zero-based. The adapter defines which positions are valid.

## `gpio::PullControl`

Optional interface for internal pull configuration. Implement it only when the hardware supports configurable pulls.
