.global start

start:
    mrs	x0, mpidr_el1
    /*
     * The MPIDR_EL1 (Multiprocessor Affinity Register) is a system register 
     * in the ARM architecture that provides information about the identity 
     * and topology of processors in a multiprocessor system. This register 
     * is essential for distinguishing between different cores and managing 
     * processor-specific operations.
     */		
	and	x0, x0,#0xFF		
	cbz	x0, main_core		
    // Isolation the cor4e ID by masking last 8bit
	b	halt
halt:
    b halt
main_core:
    adr x0, bss_start_addr
    adr x1, bass_end_addr
    sub x1, x1 , x0 ; will get total space of bss section in code since we have 
                    ; to initialise it to '0' because they may be unini. global or
                    ; static data
    cbz x1, bss_mem_to_zero ; return if bss section is of 0 bytes
bss_mem_to_zero_loop:
    str xzr, [x0]   ; store 0 in the addr pointed by the x0(start of bss)
    add x0, x0, #8  ; inc the pointer to make next byte 0
    subs x1, x1, #8 ; sub 8 to find the remaining size 
    b.gt bss_mem_to_zero_loop ; do again and again 
bss_mem_to_zero:
    ret 

	ldr     x1, =start
    mov     sp, x1 
	bl	os_Starts
	b 	halt		
