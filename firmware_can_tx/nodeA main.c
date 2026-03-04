#include<lpc21xx.h>
#include"header.h"

can A1,A2,A3,A4;
u32 flag1=0,flag2=0,flag3=0,adc;
u32 c1=0,adc_on=1;
int main()
{
	can_init();
	adc_init();
	config_vic_for_eint();
	config_eint();

	A1.id=0x501; //	   sw1 on
	A1.dlc=8;
	A1.rtr=0;	//data frame

	A2.id=0x502; //sw2 on
	A2.dlc=8;
	A2.rtr=0;




	A3.id=0x503;	//sw3 on
	A3.dlc=8;
	A3.rtr=0;


	A4.id=0x504;	//sw3 on
	A4.dlc=8;
	A4.rtr=0;

	while(1)
	{
		if(adc_on==1)
		{						
			A4.byteB=adc_read(2);
				delay_sec(5);
			can_tx(A4);
		}
		else
		adc_on=1;
	}
	/*
	   while(1)
	   {
	   c1++;
	 */
}
