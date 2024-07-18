#include "../include/Pheripheral.h"


void os_Starts(void);

int uninitialized_variable;

void os_Starts(void){
    uart_init();
    transmit_strig("Gray-OS is Booting HAHA!!\n");
    uint64_t el = get_exception_level();
    transmit_strig("EL: ");
    transmit_strig((const char*)&el);
    transmit_strig("\n");
    while (1)
    {   
        uart_trasmit(uart_receive());
    }
}