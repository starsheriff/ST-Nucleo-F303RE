
;.syntax unified
/* vectors.s */
.cpu cortex-m4
;.fpu softvfp
.thumb

.word	  0x2000FFFF
.word	  _reset_handler

.thumb_func
.global _reset_handler
_reset_handler:
  /* ;bl  SystemInit */
  bl  main
  b infloop
  
.thumb_func
infloop:
  b infloop
  
  

