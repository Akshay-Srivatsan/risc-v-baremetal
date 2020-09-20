// Sets a pin to output mode (enables output, disables input)
void gpio_set_output(unsigned pin);

// Writes a pin
void gpio_write(unsigned pin, unsigned val);

// Sets a pin's inverted-output bit
void gpio_set_xor(unsigned pin, unsigned val);
