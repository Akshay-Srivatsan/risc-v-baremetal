unsigned read_ticks() {
  return *(unsigned *)0x200BFF8;
}

unsigned read_us(void) {
    unsigned u = read_ticks();
    return u * 31;
}

unsigned read_ms(void) {
    unsigned u = read_ticks();
    return u / 32;
}

unsigned read_s(void) {
    unsigned u = read_ticks();
    return u / 32768;
}

void delay_us(unsigned us) {
    unsigned rb = read_us();
    while (1) {
        unsigned ra = read_us();
        if ((ra - rb) >= us) {
            break;
        }
    }
}

void delay_ms(unsigned ms) {
    delay_us(ms*1000);
}

void delay_sec(unsigned sec) {
    delay_ms(sec*1000);
}
