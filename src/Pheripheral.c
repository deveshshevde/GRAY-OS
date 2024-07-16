
/* 
    * Function implementations
*/
#include "../include/Pheripheral.h"

void uart_init(void)
{
    unsigned int r;
    (*AUX_ENABLE ) = (*AUX_ENABLE) | 0x01; 
    *AUX_MU_CNTL = 0;
    *AUX_MU_LCR = 3;    
    *AUX_MU_MCR = 0;
    *AUX_MU_IER = 0;
    *AUX_MU_IIR = 0xc6;    
    *AUX_MU_BAUD = 270;    
    r=*GPFSEL1;
    r&=~((7<<12)|(7<<15)); 
    r|=(2<<12)|(2<<15);    
    *GPFSEL1 = r;
    *GPPUD = 0;            
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = (1<<14)|(1<<15);
    *AUX_MU_CNTL = 3;      
    r=150; while(r--) { asm volatile("nop"); }
    *GPPUDCLK0 = 0;        
}
void uart_trasmit(unsigned char data)
{
    while((*AUX_MU_LSR & 0x20) == 0);
    *AUX_MU_IO = data;
}

void delay( unsigned time){
    for (int i = 0; i<time; i++){
    asm volatile("nop");
    }
}