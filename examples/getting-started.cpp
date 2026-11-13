#include <adapter/adc.hpp>
#include <stdint.h>
#include <stdio.h>

enum class Input
{
    A0
};
enum class Reference
{
    Supply
};
enum class Prescaler
{
    Div128
};

class ADC : public adapter::adc::Converter<
                Input, Reference, Prescaler, uint16_t>
{
public:
    bool configure(Reference, Prescaler) override
    {
        return true;
    }

    bool select_input(Input) override
    {
        return true;
    }

    void start_conversion() override
    {
        result_ = 512;
        complete_ = true;
    }

    bool conversion_complete() const override
    {
        return complete_;
    }

    uint16_t read_result() override
    {
        return result_;
    }

    uint8_t resolution_bits() const override
    {
        return 10;
    }

private:
    uint16_t result_ = 0;
    bool complete_ = false;
};

class MCU
{
public:
    ADC &adc()
    {
        return adc_;
    }

private:
    ADC adc_;
};

int main()
{
    MCU mcu;
    auto &adc = mcu.adc();

    adc.configure(Reference::Supply, Prescaler::Div128);
    adc.select_input(Input::A0);
    adc.start_conversion();

    while (!adc.conversion_complete())
    {
    }

    uint16_t value = adc.read_result();
    printf("ADC: %u\n", static_cast<unsigned>(value));
}
