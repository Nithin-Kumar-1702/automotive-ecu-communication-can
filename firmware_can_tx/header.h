// header


#include <LPC21xx.H>
#include<stdio.h>

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef	unsigned short int u16;
typedef	signed short int s16;

typedef struct can_msg
{
 u32 id;
 u8 rtr;
 u32 dlc;
 u32 byteA;
 u32 byteB;

}can;

extern void can_init(void);
extern void can_tx(can v);
extern void delay_ms( u32 ms);
extern void delay_sec(unsigned int sec);
extern void EINT0_Handler(void)__irq;
extern void EINT1_Handler(void)__irq;
extern void EINT2_Handler(void)__irq;
extern void config_vic_for_eint(void);
extern void config_eint(void);

extern void adc_init(void);
extern unsigned int adc_read(int ch_num);

