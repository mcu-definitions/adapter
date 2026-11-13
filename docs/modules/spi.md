# SPI

## Common types

- `Mode`: clock polarity and phase.
- `BitOrder`: most-significant-first or least-significant-first.
- `Role`: master or slave.

## `spi::Controller`

The adapter supplies a data type matching the supported transfer width.

Required operations:

- `configure(mode, bit_order, role, clock_hz)`
- `ready()`
- `transfer(transmitted, received)`

`transfer()` exchanges one word and writes the received word to the output reference.
