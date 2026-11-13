# Watchdog

## Common type

`watchdog::Mode` represents reset, interrupt, or combined interrupt-and-reset operation.

## `watchdog::Controller`

The adapter supplies the native timeout selection type.

Required operations:

- `configure(timeout, mode)`
- `kick()`
- `disable()`

The adapter reports unsupported modes or unavailable disable operations by returning `false`.
