#include "../include/Pheripheral.h"


void os_Starts(void);

int uninitialized_variable;

void os_Starts(void){
    uart_init();
    transmit_strig("Gray-OS is Booting HAHA!!\n");
    while (1)
    {   
        uart_trasmit(uart_receive());
    }

}