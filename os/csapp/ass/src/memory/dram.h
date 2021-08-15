#ifndef dram_guard
#define dram_guard

#include <stdint.h>

#define MM_LEN 1000

uint64_t read64Bits_ram(uint64_t paddr);
void write64Bits_ram(uint64_t paddr,uint64_t data);

void print_register();
void print_stack();

#endif
