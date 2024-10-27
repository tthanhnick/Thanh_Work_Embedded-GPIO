#include "header.h"

void SetOrClearBit(unsigned int *address, unsigned char position, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (1U<<position);
	}
	else
	{
		*address &= ~(1U<<position);
	}
	return;
}

void SetOrClearMultiBit(unsigned int *address, unsigned char position, unsigned int mask, unsigned char action)
{
	if (action == SET_BIT)
	{
		*address |= (mask<<position);
	}
	else
	{
		*address &= ~(mask<<position);
	}
	return;
}

void LEDConfig (void)
{
	SetOrClearBit((unsigned int*) PCC_PORTD, 30u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) PORTD_PCR15, 8u, 1u, SET_BIT); // Port D 15 gpio
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 15u, SET_BIT); // GPIO D pin 15 output
}

void delay(void)
{
	for(int i=0; i< 300000; i++);
}

void LEDToggle (void)
{
	SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, CLEAR_BIT); 
	delay();    
	SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT); 
	delay();    
}

void SW2Config (void)
{
	SetOrClearBit((unsigned int*) PCC_PORTC, 30u, SET_BIT);
	SetOrClearMultiBit((unsigned int*) PORTC_PCR12, 8u, 1u, SET_BIT); //enable Pin 12 gpio
	SetOrClearBit((unsigned int*) GPIOD_PDDR, 12u, CLEAR_BIT); // GPIO Port D Pin 12  Input
	
	SetOrClearMultiBit((unsigned int*) GPIOD_PDOR, 15u, 1u, SET_BIT);
	
}

void SW2Toggle (void)
{
	unsigned int state = ((*(unsigned int*)GPIOC_PDIR) & (1 << 12)); // if input GPIO C Pin 12 is true
	if (state)
	{
		SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, CLEAR_BIT); 
	}
	else
	{
		SetOrClearBit((unsigned int*) GPIOD_PDOR, 15u, SET_BIT); 
	}
}
