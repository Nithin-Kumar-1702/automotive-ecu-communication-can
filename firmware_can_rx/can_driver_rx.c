
// can1_driver_rx

#include <LPC21xx.H>
#include"header.h"

void can_init(void)
{
VPBDIV=1;          //pclk=60mhz;
PINSEL1|=0x40000;  //p0.25 ->Rd1
C1MOD=0x1;		   //reset mode
AFMR=2;			   //accept all	incoming 
C1BTR = 0x003C0007;  // ~125 kbps (approx)
C1MOD=0x0;		   //release reset mode
} 


#define RBS (C1GSR&1)
void can_rx(can *ptr){
while(RBS==0);                 //waiting for DF /RF to receive
ptr->id=C1RID;				   //stored id into id varibl
ptr->dlc=(C1RFS>>16)&0xF;     //extract dlc
ptr->rtr=(C1RFS>>30)&1;       //extract rtr
if(ptr->rtr==0){              //if data-frame
ptr->byteA=C1RDA;            // store 1 byte of data in rx
ptr->byteB=C1RDB;

}
C1CMR=(1<<2);                 //*release rxbuf	
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
