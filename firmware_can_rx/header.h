// header


typedef unsigned int u32;
typedef unsigned char u8;

typedef struct can_msg
{
u8 id;
u8 rtr;
u32 dlc;
u32 byteA;
u32 byteB;
}can;


extern void can_init(void);
extern void can_rx(can *ptr);
extern void can_tx(can v);
extern void can_rx_handler(void) __irq;
extern void config_vic_for_can(void);


extern void delay_ms(unsigned int ms);
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);
extern unsigned char uart0_rx(void);
extern void uart0_integer(int num);
extern void uart0_tx_string( char *ptr);
