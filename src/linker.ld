/*
* .text section -> 

*/

/*
TODO: Instruction to setup toolchain for macOS 
*/
/*
* brew tap messense/macos-cross-toolchains
 #install aarch64-unknown-linux-gnu toolchain
* brew install aarch64-unknown-linux-gnu
*/

/*
	* Not using ENTRY(__some_handler__) as it is not required 
	* but if you are using gdb debugger ig you may should use it there
*/

SECTIONS
{
	/* Must add boot section whether it is called or not */
	/* Keep this section anyway or you can remove KEEP as it is already refrence */
	.text.boot : { KEEP(*(.text.boot)) }
	/* text section of elf file*/
	.text : { *(.text) }
	/* read only section of elf file*/
	.rodata : { *(.rodata) }
	/* initialised data section*/
	.data : { *(.data) }
	. = ALIGN(0x8);
	/* un-initialised bss section -> must be cleared during */
	bss_start_addr = .; /* current start addr of bss start */
	.bss : { *(.bss*) } 
	bss_end_addr = .;/* update end addr of section using '.' */
}