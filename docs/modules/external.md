# External interrupts

## `external::Line`

The common trigger values are low level, any change, falling edge and rising edge.

Required operations configure the trigger, enable or disable the line, report pending state and clear the pending flag.

## `external::PinChangeGroup`

The adapter supplies the native mask type. The interface configures the group's mask and controls its interrupt state.
