#ifndef MAIN_H
#define MAIN_H

#define __IO volatile
#define __I  volatile const


extern void delay( unsigned time);
extern void uart_trasmit(unsigned char data);
#endif