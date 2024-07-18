/**
 * Writes the given value to the memory location specified by the given register.
 *
 * @param reg the register address to write to
 * @param val the value to write to the register
 *
 * @throws None
 */
void write_mem(long reg, unsigned int val) 
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
unsigned int read_mem(long reg) 
{ 
    return *(volatile unsigned int *)reg; 
}