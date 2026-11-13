# Modules

| Module | Interface | Purpose |
|---|---|---|
| GPIO | `gpio::Port` | Digital input and output. |
| GPIO | `gpio::PullControl` | Optional internal pull configuration. |
| ADC | `adc::Converter` | Analog input conversion. |
| ADC | `adc::TriggerControl` | Optional conversion trigger selection. |
| PWM | `pwm::Channel` | PWM output channel. |
| PWM | `pwm::PolarityControl` | Optional output polarity control. |
| Timer | `timer::Counter` | Timer and counter operation. |
| Timer | `timer::InputCapture` | Optional input capture. |
| Serial | `serial::Peripheral` | Serial frame transmission and reception. |
| SPI | `spi::Controller` | SPI transfers. |
| I2C | `i2c::Controller` | Two-wire bus transfers. |
| EEPROM | `eeprom::Memory` | Byte-addressable non-volatile storage. |
| Watchdog | `watchdog::Controller` | Watchdog configuration and servicing. |
| External | `external::Line` | External interrupt line. |
| External | `external::PinChangeGroup` | Pin-change interrupt group. |
| Comparator | `comparator::Comparator` | Analog comparison. |
| Interrupt | `interrupt::Controller` | Global interrupt state. |
| Clock | `clock::Clock` | Clock domain frequency. |
| Clock | `clock::PrescalerControl` | Optional runtime prescaler control. |
| Power | `power::SleepController` | Sleep mode control. |
| Power | `power::PeripheralClockControl` | Optional peripheral clock gating. |
| Reset | `reset::ResetInfo` | Reset cause information. |
| Reset | `reset::ResetControl` | Optional reset control operations. |

Optional interfaces must only be implemented when the corresponding hardware capability exists.
