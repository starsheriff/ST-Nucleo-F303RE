/* Entry Point */
/*ENTRY(Reset_Handler)*/

/* Specify the memory areas */
MEMORY
{
FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 512K
RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 64K
CCMRAM (rw)     : ORIGIN = 0x10000000, LENGTH = 16K
}

/* Define output sections */
SECTIONS
{
  .text : { *(.text*) } > FLASH
}
