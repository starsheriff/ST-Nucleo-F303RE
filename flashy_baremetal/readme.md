# Flashy Baremetal
Same as `flashy`, only with custom baremetal startup and linker scripts. There is no call to `SystemInit` required either.

For documentation of `main.c` see the [documentation of `flashy`](https://github.com/starsheriff/ST-Nucleo-F303RE/tree/master/flashy)


# Makefile
Most of the time I actually spent on the makefile. Getting the project to compile, and link was easier than getting the binary to actually work on the board. Pay attention to use the correct compiler options and the correct order of objects in the linker. `startup.o` has to come first!

## Object Dump

```
Disassembly of section .text:

08000000 <_reset_handler-0x8>:
 8000000:	2000ffff 	strdcs	pc, [r0], -pc	; <UNPREDICTABLE>
 8000004:	08000009 	stmdaeq	r0, {r0, r3}
 ...
```

# References
1. [topic on electronics.stackexchange.com](http://electronics.stackexchange.com/questions/30736/stm32f2-makefile-linker-script-and-start-up-file-combination-without-commercia)
2. [dwelch67 on github](https://github.com/dwelch67/stm32f4d). Lot's of good projects. He made the accepted answer on the above stackexchange topic.
