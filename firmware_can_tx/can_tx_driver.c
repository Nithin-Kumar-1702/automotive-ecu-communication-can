// can_driver_tx


#include <LPC21xx.H>
#include"header.h"

void can_init(void)
{
VPBDIV = 1;          //pclk=60mhz;
//PINSEL1|=0x40000;  //p0.25 ->Rd1
PINSEL1|=(1<<18);
PINSEL1|=(1<<16);
C1MOD=0x1;		   //reset mode

	AFMR=2;			   //accept all	incoming  msg
C1BTR = 0x001C001D;  // ~125 kbps (approx)
C1MOD=0x0;		   //release reset mode
}



#define TCS ((C1GSR>>3)&1)
void can_tx(can v)
{
C1TID1=v.id;		   //set id
C1TFI1=v.dlc<<16;	   //set dlc=8,RTR=0,FF=0

if(v.rtr==0)		   //data frame
{
C1TDA1=v.byteA;		   //set lower bit
C1TDB1=v.byteB;		   //set upper bit
}

else				  //Remote frame
C1TFI1|=(1<<30);	  //set RTR=1;

C1CMR=1|(1<<5);		  //select txbuf & start tx
while(TCS==0);		  //monitor TCS

}
