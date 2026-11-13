# Serial

## Common frame types

- `Mode`: asynchronous or synchronous.
- `DataBits`: five through nine data bits.
- `Parity`: none, even or odd.
- `StopBits`: one or two stop bits.

## `serial::Peripheral`

Required operations configure the frame, report transmit and receive readiness, write and read frames, and report transmission completion.

The adapter returns `false` from `configure()` for unsupported frame combinations. The data type supplied by the adapter must hold the largest frame supported by the peripheral.
