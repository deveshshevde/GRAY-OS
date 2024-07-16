    #ifndef PHERIPHERAL_H
    #define PHERIPHERAL_H
    #include "main.h"
    /* 
    * pheripheral base address link :
    * https://forums.raspberrypi.com/viewtopic.php?t=244031
    */

   /* 
   * So we are taking virtual addr here 
   * MMU(hardware level) will itself tranfer(or map) those virtual addr to physical addr    
   */

    //https://www.raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf -> page 6

  /*
    * Physical addresses range from 0x20000000 to 0x20FFFFFF for peripherals. The bus
    * addresses for peripherals are set up to map onto the peripheral bus address range starting at
    * 0x7E000000. Thus a peripheral advertised here at bus address 0x7Ennnnnn is available at
    * physical address 0x20nnnnnn.
  */
const unsigned int PHERIPHERAL_BASE_ADDR   = 0xFE000000; // which is 0x7e00000 acc. to datasheet

/* These are only GPIO's register */

#define GPFSEL0        ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR + 0x200000))
#define GPFSEL1        ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR + 0x200004))
#define GPFSEL2        ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200008))
#define GPFSEL3        ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x0020000C))
#define GPFSEL4        ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200010))
#define GPFSEL5        ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200014))
#define GPSET0         ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x0020001C))
#define GPSET1         ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200020))
#define GPCLR0         ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200028))
#define GPLEV0         ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200034))
#define GPLEV1         ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200038))
#define GPEDS0         ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200040))
#define GPEDS1         ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200044))
#define GPHEN0         ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200064))
#define GPHEN1         ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200068))
#define GPPUD          ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200094))
#define GPPUDCLK0      ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x00200098))
#define GPPUDCLK1      ((__IO unsigned int *)(PHERIPHERAL_BASE_ADDR+0x0020009C))


/* Miny UART register definations */
/* The AUX_ENABLES register is used to enable the three modules: UART1, SPI1, SPI2 */
#define AUX_ENABLE      ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215004))
/* The AUX_MU_IO_REG register is primarily used to write data to and read data from the UART FIFOs */
#define AUX_MU_IO       ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215040))
/* The AUX_MU_IER register is used to enable and disable interrupts in the UART FIFOs */
#define AUX_MU_IER      ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215044))
/* The AUX_MU_IIR_REG register shows the interrupt status */
#define AUX_MU_IIR      ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215048))
/* refer data sheet or update later*/
#define AUX_MU_LCR      ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x0021504C))
#define AUX_MU_MCR      ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215050))
#define AUX_MU_LSR      ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215054))
#define AUX_MU_MSR      ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215058))
#define AUX_MU_SCRATCH  ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x0021505C))
#define AUX_MU_CNTL     ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215060))
#define AUX_MU_STAT     ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215064))
#define AUX_MU_BAUD     ((__IO unsigned int*)(PHERIPHERAL_BASE_ADDR+0x00215068))





#endif