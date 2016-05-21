# Quadrature Encoder
A simple project where a quadrature encoder i ordered is read by the Nucleo board. 
The idea is to make a nice knob for the encoder, a beautiful display that simply displays the counter value and 
install it somewhere to play around with.

I have not yet desided how to display the counter value. Options are feeding through UART to another unit or just plain to a 
LCD display.



In the [reference manual](#ref_1), section 20.3.20, the encoder interface mode of the STM32F303 is explained.

## Timers with Encoder Interface Mode
From the datasheet [[2]](#refs) we can find that there are a lot of timers available. 
There is nothing explicitely written in the datasheet about _encoder interface mode_. 
However in the reference manual [[1]](#refs), in sections _20.3.20_ and _21.3.15_, the encoder interface mode is described.
So, for the advanced timers `TIM1/8/20` and the general purpose timers `TIM2/3/4` the encoder interface mode is supported.

In the reference manual `TI1` and `TI2` are mentioned. These refer to channels 1 and 2 respectively, see figure 141 in the reference manual (page 510).

Let's see how to connect to the timers physically on the Nucleo board. Table 13 in the Nucleo user manual shows that only one of the timers with support for the encoder interface mode is connected with the proper channels; timer 3.


|Timer (Channel) |Pin (uc)  | Pin (Nucleo) |
|---|---|---|
|TIM1 | xx| xx|
|TIM3_CH1 | PB4 | D4 |
| TIM3_CH2 | PC7 | D9 |
|TIM20, Ch. 1| PE2 | - |
|TIM20, Ch. 2| PE3 | - |

## Configure Timer (in Encoder Interface Mode)
I want the counter to work in 4x mode. That is, I want the counter to count on all 4 edges, rising and falling of both input channels. That gives the highest resolution, see this [tutorial (4.)](#refs) for some more information about quadrature encoders.

### Initialization

* set SMS='011 in register TIM3_SMCR (enables counting on all four edges)
* set polarity of input channels TI1 and TI2 with CC1P and CC2P bits in register TIM3CCER
* CN1P, CN2P must be cleared
* 



<a id="refs"></a>
# References
<a id="ref_1"></a>

1. [DM00043574 (STMF303 Reference Manual)](http://www.st.com/web/en/catalog/mmc/FM141/SC1169/SS1576/LN1531)
2. [DM00118585 STM32F303RE Datasheet](http://www.st.com/web/en/catalog/mmc/FM141/SC1169/SS1576/LN1531)
3. [DM00105823 STM32 Nucleo-64 boards User Manual](http://www.st.com/web/catalog/tools/FM116/CL1620/SC959/SS1532/LN1847/PF260945)
4. [Quadrature Encoder Tutorial](http://tutorial.cytron.com.my/2012/01/17/quadrature-encoder)
