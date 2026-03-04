
// rx_can_interrupt



#include <LPC21xx.H>
#include "header.h"

extern can r1;
extern u32 flag;
extern u32 adc_val;

void can_rx_handler(void) __irq
{
	r1.id=C1RID;
	r1.dlc=(C1RFS>>16)&0xF;     //extract dlc
	r1.rtr=(C1RFS>>30)&1;       //extract rtr
	if(r1.rtr==0){              //if data-frame
		r1.byteA=C1RDA;		    // received data storein byteA    
		r1.byteB=C1RDB;
	}
	C1CMR=(1<<2);
	flag=1;	
    VICVectAddr=0;
}

void config_vic_for_can(void)
{
    VICIntSelect=0;
	VICVectAddr5=(u32)can_rx_handler;
	VICVectCntl5=26|(1<<5);     //Assign CAN1 Rx intr to slot5
	VICIntEnable=(1<<26);       //En CAN1 Rx Intr in VIC peripheral
	C1IER=1;                    //En CAN1 Rx intr in CAN1 Peri
}
