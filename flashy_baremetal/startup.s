
;.syntax unified
/* vectors.s */
.cpu cortex-m4
;.fpu softvfp
.thumb

.word	  0x2000FFFF
.word	  _reset_handler
.word   infloop        /* 2 NMI */
.word   infloop        /* 3 HardFault */
.word   infloop        /* 4 MemManage */
.word   infloop        /* 5 BusFault */
.word   infloop        /* 6 UsageFault */
.word   infloop        /* 7 RESERVED */
.word   infloop        /* 8 RESERVED */
.word   infloop        /* 9 RESERVED*/
.word   infloop        /* 10 RESERVED */
.word   infloop        /* 11 SVCall */
.word   infloop        /* 12 Debug Monitor */
.word   infloop        /* 13 RESERVED */
.word   infloop        /* 14 PendSV */
.word   infloop        /* 15 SysTick */
.word   infloop        /* 16 External Interrupt(0) */
.word   infloop        /* 17 External Interrupt(1) */
.word   infloop        /* 18 External Interrupt(2) */
.word   infloop        /* 19 ...   */

.thumb_func
.global _reset_handler
_reset_handler:
  /* ;bl  SystemInit */
  bl  main
  b infloop
  
.thumb_func
infloop:
  b infloop
  
  

