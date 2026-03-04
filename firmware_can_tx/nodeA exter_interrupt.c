//nodeA exter_interrupt


#include<lpc21xx.h>
#include"header.h"
extern can A1,A2,A3,A4;
extern u32 flag1,flag2,flag3,adc_on;

void EINT0_Handler(void) __irq
{
	flag1^=1;
	adc_on=0;
	if(flag1)
	{
	A1.byteA=0x11; 
	A1.byteB=adc_read(2);    //headlight no
	}
	else
	{
	A1.byteA=0x10;     //headlight off
	A1.byteB=adc_read(2);
	} 
	can_tx(A1);
	 

	EXTINT=1;
	VICVectAddr=0;
}


void EINT1_Handler(void) __irq
{
	flag2^=1;
	adc_on=0;
	if(flag2)
	{
	A2.byteA=0x13;     //rightind no
	A2.byteB=adc_read(2);
	}
	else
	{
	A2.byteA=0x12;     //rightind off
	A2.byteB=adc_read(2);
	}
	can_tx(A2);

	EXTINT=2;
	VICVectAddr=0;
}


void EINT2_Handler(void) __irq
{

	flag3^=1;
	adc_on=0;
	if(flag3)
	{
	A3.byteA=0x15;     //leftind no
	A3.byteB=adc_read(2);
	}
	else
	{
	A3.byteA=0x14;     //leftind off
	A3.byteB=adc_read(2);
		}
	can_tx(A3);
		
	EXTINT=4;
	VICVectAddr=0;
}


void config_vic_for_eint(void)
{
	VICIntSelect=0;
	VICVectAddr0|=(unsigned int)EINT0_Handler;
    VICVectAddr1|=(unsigned int)EINT1_Handler;
	VICVectAddr2|=(unsigned int)EINT2_Handler;
	VICVectCntl0|=14|(1<<5);
	VICVectCntl1|=15|(1<<5);
	VICVectCntl2|=16|(1<<5);
	VICIntEnable=(1<<14)|(1<<15)|(1<<16);
}


void config_eint(void)
{
	PINSEL1|=1;
	PINSEL0|=0xA0000000;	// (10<<28);
	EXTMODE=7;
	EXTPOLAR=0;
}
