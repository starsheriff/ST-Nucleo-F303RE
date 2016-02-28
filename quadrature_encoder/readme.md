# Quadrature Encoder
A simple project where a quadrature encoder i ordered is read by the Nucleo board. 
The idea is to make a nice knob for the encoder, a beautiful display that simply displays the counter value and 
install it somewhere to play around with.

I have not yet desided how to display the counter value. Options are feeding through UART to another unit or just plain to a 
LCD display.



In the [reference manual](#ref_1), section 20.3.20, the encoder interface mode of the STM32F303 is explained.

## Timers in STM32F303RE
From the datasheet [[2]](#refs) we can find that there are a lot of timers available. 
There is nothing explicitely written in the datasheet about _encoder interface mode_. 
However in the reference manual [[1]](#refs), in sections _20.3.20_ and _21.3.15_, the encoder interface mode is described.
So, for the advanced timers `TIM1/8/20` and the general purpose timers `TIM2/3/4` the encoder interface mode is supported.

<a id="refs"></a>
# References
<a id="ref_1"></a>

1. [DM00043574 (STMF303 Reference Manual)](http://www.st.com/web/en/catalog/mmc/FM141/SC1169/SS1576/LN1531)
2. [DM00092070 STM-F303R8 Datasheet](http://www.st.com/web/en/catalog/mmc/FM141/SC1169/SS1576/LN1531)
