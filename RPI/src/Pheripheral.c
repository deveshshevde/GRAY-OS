
/* 
    * Function implementations
*/
#include "../include/Pheripheral.h"
#include "../include/helperfunc.h"

void uart_init ( void )
{
	unsigned int selector;
	selector = read_mem(*GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 2<<12;                      // set alt5 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 2<<15;                      
	write_mem(*GPFSEL1,selector);

	write_mem(*GPPUD,0);
	delay(150);
	write_mem(*GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	write_mem(*GPPUDCLK0,0);

	write_mem(*AUX_ENABLE,1);                  
	write_mem(*AUX_MU_CNTL,0);               
	write_mem(*AUX_MU_IER,0);                
	write_mem(*AUX_MU_LCR,3);                
	write_mem(*AUX_MU_MCR,0);                
	write_mem(*AUX_MU_BAUD,270);             

	write_mem(*AUX_MU_CNTL,3);               
}
void uart_trasmit(unsigned char c)
{
	while(1) {
		if(read_mem(*AUX_MU_LSR)&0x20) 
			break;
	}
	write_mem(*AUX_MU_IO,c);
}

char uart_receive ( void )
{
	while(1) {
		if(read_mem(*AUX_MU_LSR)&0x01) 
			break;
	}
	return(read_mem(*AUX_MU_IO)&0xFF);
}

void transmit_strig(const char *string){
    	for (int i = 0; string[i] != '\0'; i ++) {
		uart_trasmit((char)string[i]);
	}
}
void delay( unsigned time){
    for (int i = 0; i<time; i++){
    asm volatile("nop");
    }
}