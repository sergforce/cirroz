OUTPUT_FORMAT("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)

MEMORY {
    RAM(rwx) : ORIGIN = 0x80014000, LENGTH = 4k
}

SECTIONS {
    .text : {
	LONG(0x53555243)
	*startup.s.o(.text)

	*(.text .text.* .gnu.linkonce.t.*)
	
	. = ALIGN(0x4);

	*(.rodata .rodata.*)

    } > RAM

}