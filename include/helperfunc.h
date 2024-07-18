#include "../include/main.h"
#include "../include/print.h"
#include "../include/IRQ.h"
#include "../include/timer.h"
/**
 * Writes the given value to the memory location specified by the given register.
 *
 * @param reg the register address to write to
 * @param val the value to write to the register
 *
 * @throws None
 */
static inline void write_mem(long reg, unsigned int val) 
{
     *(volatile unsigned int *)reg = val; 
}
/**
 * Reads the value from the memory location specified by the given register.
 *
 * @param reg the register address to read from
 *
 * @return the value read from the register
 *
 * @throws None
 */
static inline unsigned int read_mem(long reg) 
{ 
    return *(volatile unsigned int *)reg; 
}

uint64_t get_exception_level(void) {
    uint64_t el;
    asm volatile(
        "mrs %0, CurrentEL\n"
        "lsr %0, %0, #2\n"
        : "=r" (el) // Output operand
        : // No input operands
        : "x0" // Clobbered register
    );
    return el;
}