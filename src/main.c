#include "../include/Pheripheral.h"


void os_Starts(void);


void os_Starts(void){
    uart_init();
    while (1)
    {   
        char x = 'a';
        uart_trasmit('x');
        x++;
        delay(1000);
    }

}