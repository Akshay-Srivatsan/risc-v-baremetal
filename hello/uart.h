// Checks if the UART can be written to without blocking
int uart_can_putc(void);

// Writes a character to the UART, blocking if necessary
void uart_putc(unsigned c);

// Writes a string to the UART, blocking if necessary
void uart_puts(char *c);
