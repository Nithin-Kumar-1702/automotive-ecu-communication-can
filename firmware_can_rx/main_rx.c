//main_rx

#include <LPC21xx.H>
#include "header.h"
#define Hled1 (1<<17)
#define Hled2 (1<<18)
#define Rled (1<<19)
#define Lled (1<<20)
#define SPEED_LED (1<<21)

/*
#define Hled1 (1)
#define Hled2 (2)
#define Rled (4)
#define Lled (8)
#define SPEED_LED (16)
 */
can r1;
u32 flag=0,Rf=0,Lf=0,adc_val=0;

int main()
{
	u32 speed,adc;
	can_init();
	config_vic_for_can();
	uart0_init(9600);

	IODIR0|=Hled1|Hled2|Rled|Lled|SPEED_LED;
	IOSET0=Hled1|Hled2|Rled|Lled|SPEED_LED;


	 uart0_tx_string("nodeb\r\n");

	while(1)
	{
		if(Rf==1)
		{
			while(1)
			{
				IOCLR0=Rled;
				delay_ms(500);
				IOSET0=Rled;
				delay_ms(500);
				if(flag==1)
					break;
			}
		}

		if(Lf==1)
		{
			while(1)
			{
				IOCLR0=Lled;
				delay_ms(500);
				IOSET0=Lled;
				delay_ms(500);
				if(flag==1)
					break;
			}
		}

		if(flag==1)
		{
			flag=0;
			if(r1.rtr==0)
			{
				adc=r1.byteB;
				/*


				 */
				speed=(adc* 220)/1023;
				uart0_integer(speed);
				 uart0_tx_string("\r\n");
				if(speed>30)
					IOCLR0=SPEED_LED;
				else
					IOSET0=SPEED_LED;


				switch(r1.byteA&0xff)
				{
					case 0x11: IOSET0=Hled1|Hled2;
						   break;
					case 0x10: IOCLR0=Hled1|Hled2;
						   break;
					case 0x13: 
						   Rf=1;
						   Lf=0;
						   break;
					case 0x12: 
						   Rf=0;
						   break;
					case 0x15: 
						   Rf=0;
						   Lf=1;
						   break;
					case 0x14: 
						   Lf=0;
						   break;
				}
			}
		}
	}
}
