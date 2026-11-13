# I2C

## Common types

- `Role`: master or slave.
- `Response`: ACK or NACK after a received byte.
- `Status`: common bus operation results.

## `i2c::Controller`

Required operations:

- `configure(role, frequency_hz, own_address)`
- `start(repeated)`
- `send_address(address, read)`
- `write(value)`
- `read(value, response)`
- `stop()`
- `status()`

Addresses are passed unshifted. The adapter handles address validation and protocol encoding.
