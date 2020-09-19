.equ GPIO_0, 0x10012000
.equ GPIO_OUTPUT_EN, 0x08
.equ GPIO_OUTPUT_VAL, 0x0c
.equ GPIO_OUTPUT_XOR, 0x40

.equ LED_RED, 1 << 22
.equ LED_GREEN, 1 << 19
.equ LED_BLUE, 1 << 21

.equ RGB_ENABLE, LED_RED | LED_GREEN | LED_BLUE

.equ SLEEP_TIME, 0x200000

.macro sleep duration register
  li \register, \duration
sleep\@:
  addi \register, \register, -1
  bge \register, x0, sleep\@
.endm

start:
  li t0, GPIO_0
gpio_enable:
  li t1, RGB_ENABLE
  sw t1, GPIO_OUTPUT_EN(t0)
  sw t1, GPIO_OUTPUT_XOR(t0)
red_on:
  li t1, LED_RED
  sw t1, GPIO_OUTPUT_VAL(t0)
  sleep SLEEP_TIME, t2
green_on:
  li t1, LED_GREEN
  sw t1, GPIO_OUTPUT_VAL(t0)
  sleep SLEEP_TIME, t2
blue_on:
  li t1, LED_BLUE
  sw t1, GPIO_OUTPUT_VAL(t0)
  sleep SLEEP_TIME, t2
  j red_on

