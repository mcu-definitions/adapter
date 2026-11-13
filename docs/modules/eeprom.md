# EEPROM

## `eeprom::Memory`

The memory interface uses native address and data types supplied by the adapter.

Required operations:

- `size_bytes()`
- `ready()`
- `read(address, value)`
- `write(address, value)`
- `wait_ready()`

Read and write operations return `false` when the operation cannot be completed.
