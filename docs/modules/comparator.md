# Analog comparator

## Common type

`comparator::InterruptMode` represents toggle, falling-edge and rising-edge events.

## `comparator::Comparator`

The adapter supplies the native input selection type.

Required operations configure the positive and negative inputs, select the interrupt mode, enable or disable the comparator, read its output, report a pending interrupt and clear the interrupt flag.
