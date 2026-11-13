# Timer

## `timer::Counter`

The counter interface uses native counter value, mode, clock and compare-channel types supplied by the adapter.

Required operations:

- `configure(mode, clock)`
- `start()`
- `stop()`
- `set_value(value)`
- `value()`
- `set_compare(channel, value)`

## `timer::InputCapture`

Optional interface for timers with input capture support.
