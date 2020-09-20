#include "riscv.h"

#define LED_RED 22
#define LED_GREEN 19
#define LED_BLUE 21

void setup_leds() {
  gpio_set_output(LED_RED);
  gpio_set_output(LED_GREEN);
  gpio_set_output(LED_BLUE);
  gpio_set_xor(LED_RED, 1);
  gpio_set_xor(LED_GREEN, 1);
  gpio_set_xor(LED_BLUE, 1);
}

void set_rgb(unsigned r, unsigned g, unsigned b) {
  gpio_write(LED_RED, r);
  gpio_write(LED_GREEN, g);
  gpio_write(LED_BLUE, b);
}

void notmain() {
  uart_puts("Hello, World!\r\n");
  setup_leds();
  while (1) {
    set_rgb(1, 1, 0);
    delay_sec(1);
    set_rgb(0, 1, 1);
    delay_sec(1);
    set_rgb(1, 0, 1);
    delay_sec(1);
  }
  while(1);
}
