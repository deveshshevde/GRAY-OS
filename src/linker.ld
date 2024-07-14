/*
* .text section -> 

*/

SECTIONS
{
	.text.boot : { *(.text.boot) }
	.text : { *(.text) }
	.rodata : { *(.rodata) }
	.data : { *(.data) }
	. = ALIGN(0x8);
	bss_start_addr = .;
	.bss : { *(.bss*) } 
	bss_end_addr = .;
}