.section ".text.boot"

.globl _start
_start:
  la sp, __stack_top__
  li sp, 0x80001000
  la gp, __global_pointer$

  call _cstart
halt:
  nop
  j halt

.globl put32
.globl PUT32
put32:
PUT32:
  sw a1, 0(a0)
  ret

.globl get32
.globl GET32
get32:
GET32:
  lw a1, 0(a0)
  ret
