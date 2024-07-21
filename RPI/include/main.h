#ifndef MAIN_H
#define MAIN_H

#define __IO volatile
#define __I  volatile const

/* Typedefs */
typedef unsigned int uint32_t;
typedef unsigned long uint64_t;



extern void delay( unsigned time);
extern void uart_trasmit(unsigned char data);
extern uint64_t get_exception_level(void);
#endif