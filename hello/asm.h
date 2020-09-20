void PUT32(unsigned addr, unsigned v);
void put32(volatile void *addr, unsigned v);

void PUT16(unsigned addr, unsigned short v);
void put16(volatile void *addr, unsigned short v);

void PUT8(unsigned addr, unsigned char v);
void put8(volatile void *addr, unsigned char v);

unsigned GET32(unsigned addr);
unsigned get32(const volatile void *addr);

unsigned short GET16(unsigned addr);
unsigned short get16(const volatile void *addr);

unsigned char GET8(unsigned addr);
unsigned char get8(const volatile void *addr);
