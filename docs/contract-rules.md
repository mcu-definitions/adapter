# Contract rules

## Pure virtual interfaces

Each contract is an abstract class with a public virtual destructor and pure virtual operations.

An adapter derives from the relevant interface and implements every required operation. Use `override` on every implementation.

If a required operation is missing or its signature does not match, the adapter class remains abstract or the compiler reports an override error.

## Concrete adapter check

Place a compile-time check after the adapter class definition:

```cpp
#include <type_traits>

static_assert(
    !std::is_abstract<MyAdapter>::value,
    "Adapter does not implement the complete interface."
);
```

This makes an incomplete adapter fail at the point where the adapter is defined.

## MCU construction

Each device-specific adapter may define an `MCU` class that exposes its supported peripherals. Applications construct it directly:

```cpp
MCU mcu;
```

MCU construction is standard C++ object construction, not an interface contract. The MCU class is responsible for exposing and managing its concrete peripheral adapters.

## Functional behaviour

The compiler can verify inheritance and method signatures. It cannot determine whether a method correctly configures a register or performs the intended hardware operation.

The adapter developer is responsible for the implementation's functional correctness and must follow the documented behaviour of each operation.

## Native types

Template parameters preserve native types supplied by the adapter, including input selections, timer modes, counter values, channel identifiers and timeout selections.

Common enums are introduced only where the meaning is consistent across devices.

## Optional capabilities

A base interface contains only operations expected to be available for that resource.

Features that may not exist on every device are represented by separate interfaces. An adapter implements those interfaces only when the corresponding hardware capability exists.

Examples include ADC trigger selection, GPIO pull configuration, timer input capture, PWM polarity control, clock prescaler control and peripheral clock gating.

## Naming and source rules

- Namespace root: `adapter`.
- Module namespaces use one word where practical.
- File names: `snake_case.hpp`.
- Types: `PascalCase`.
- Functions: `snake_case`.
- Include guards: `UPPER_SNAKE_CASE`.
- Header-only.
- C++11.
