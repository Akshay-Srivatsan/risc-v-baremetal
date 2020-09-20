typedef struct {
  unsigned txdata;
  unsigned rxdata;
  unsigned txctrl;
  unsigned rxctrl;
  unsigned ie;
  unsigned ip;
  unsigned div;
} uart_reg_t;

volatile uart_reg_t *const UART_0 = (uart_reg_t *)0x10013000;
volatile uart_reg_t *const UART_1 = (uart_reg_t *)0x10023000;

int uart_can_putc(void) {
  return UART_0->txdata == 0;
}

void uart_putc(unsigned c) {
  while (UART_0->txdata);
  UART_0->txdata = c;
}

void uart_puts(char *c) {
  while (*c != 0) {
    uart_putc(*c++);
  }
}
