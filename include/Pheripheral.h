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

/* Other registers addr*/

#define GPFSEL0        (PHERIPHERAL_BASE_ADDR + 0x200000)
/*
* will define later!!
/
/
/
/
/
*/