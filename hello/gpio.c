typedef struct {
  unsigned input_val;
  unsigned input_en;
  unsigned output_en;
  unsigned output_val;
  unsigned pue;
  unsigned ds;
  unsigned rise_ie;
  unsigned rise_ip;
  unsigned fall_ie;
  unsigned fall_ip;
  unsigned high_ie;
  unsigned high_ip;
  unsigned low_ie;
  unsigned low_ip;
  unsigned _0;
  unsigned _1;
  unsigned out_xor;
} gpio_reg_t;

volatile gpio_reg_t *const GPIO = (gpio_reg_t *)0x10012000;

void gpio_set_output(unsigned pin) {
  GPIO->output_en |= 1 << pin;
  GPIO->input_en &= ~(1 << pin);
}

void gpio_write(unsigned pin, unsigned val) {
  if (val) {
    GPIO->output_val |= 1 << pin;
  } else {
    GPIO->output_val &= ~(1 << pin);
  }
}

void gpio_set_xor(unsigned pin, unsigned val) {
  if (val) {
    GPIO->out_xor |= 1 << pin;
  } else {
    GPIO->out_xor &= ~(1 << pin);
  }
}

