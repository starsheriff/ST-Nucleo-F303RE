# Nucleo F303RE Projects

Many thanks to [Patryk Jaworski](http://regalis.com.pl/en/arm-cortex-stm32-gnulinux), 
he published a very nice tutorial explaining how to use the STM Nucleo boards under Linux.
The basic project template follows his instructions quite closely and I will repeat a lot from his blog.

## Linker Script
The linker script `STM32F303XE_FLASH.ld`, which is shipped along with the STM32Cube package has a quite nasty copyright.
(I think) it is not allowed to publish it on github, so you have to download the STM32Cube package yourselv and extract the file.
Although, strictly speaking you wouldn't be allowed to use it with a GNU compiler...

Here's the copyright passage from the linker script:
```
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. This file may only be built (assembled or compiled and linked)
**  using the Atollic TrueSTUDIO(R) product. The use of this file together
**  with other tools than Atollic TrueSTUDIO(R) is not permitted.
```

## Note on OpenOCD
OpenOCD supports the Nucleo F303 (and others?) only from version 0.9.0. Most Linux distributions have (at the time of writing)
only older versions in the repository.

# References
1. [STM32F303RE on STM.com](http://www.st.com/web/en/catalog/mmc/FM141/SC1169/SS1576/LN1531/PF259246)
* [http://regalis.com.pl/en/arm-cortex-stm32-gnulinux](http://regalis.com.pl/en/arm-cortex-stm32-gnulinux/)
* [STM Cube](http://www.st.com/web/catalog/tools/FM147/CL1794/SC961/SS1743/LN1897/PF260613)

