/****************************************************************/
/**
 *  file        main.c
 *  containts   Run application code
 */
/****************************************************************/

/****************************************************************/
/*  Includes section                                            */
/****************************************************************/


/****************************************************************/
/*  Types And Constants                                         */
/****************************************************************/

/****************************************************************/
/*  Internal function prototype                                 */
/****************************************************************/

/*
******************************************************************************
PRACTICE 1: BIT MASK REVISION
******************************************************************************
Create a function to set or clear bit of a varible with below infor:
- Input: 
    + Param 1: address of variable          (unsigned int*)
    + Param 2: position of bit              (unsigned char)
    + Param 3: action set or clear bit      (unsigned char)
- Output: the bit of variable is set or clear at input possition.

Note: Only set/clear indicated bit and do not impact on status of other bits.

******************************************************************************
Advance: Set/clear serial multi bits >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
******************************************************************************
*/

/*
******************************************************************************
PRACTICE 2: BLINK RED_LED - PTD15
******************************************************************************
The RED_LED is connected to PTD15, please configure the PTD15 pin to blink
the led.

Hint: 
- Using function at "BIT MASK PRACTICE" to set/clear register value
- May be create 2 function, one for config, one for toggle  bit
******************************************************************************
Advance: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
******************************************************************************
*/

/*
******************************************************************************
PRACTICE 3: USING SW3 TO ENABLE/DISABLE BLINK RED LED - PTD15
******************************************************************************
The SW3 button is connected to PTC13, please configure the PTC13 pin to detect
SW3 state then enable/disable blink the led.

Hint: 
- Re-use PRACTICE 1 and 2
- Reading the value of Port Data Input Register (PDIR) of PORTC to detect state
- May create some macros for checking bit, state variable
******************************************************************************
Advance: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
******************************************************************************
*/

#include "header.h"

int main(void)
{
	//SetOrClearBit((unsigned int*) PCC_PORTD, 30u, SET_BIT);
	LEDConfig();
	SW2Config();
	
	while(1)
	{
		//LEDToggle();
		SW2Toggle();
	}
}
