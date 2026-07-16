#include <reg51.h>

void delay_1ms()
{
    TMOD = 0x01;     

    TH0 = 0xFC;     
    TL0 = 0x18;

    TR0 = 1;         
    while(TF0 == 0); 

    TR0 = 0;         
    TF0 = 0;        
}

void main()
{
    unsigned int i;

    while(1)
    {
        for(i = 0; i < 1000; i++)
        {
            delay_1ms();   

        P2 = ~P2;          
    }
}