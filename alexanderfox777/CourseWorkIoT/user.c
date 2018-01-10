/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#ifdef __XC32
#include <xc.h>          /* Defines special function registers, CP0 regs  */
#endif

#include <stdint.h>          /* For uint32_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include "user.h"            /* variables/params used by user.c               */
#include <sys/attribs.h>
#include "UART.h"

/******************************************************************************/
/* User Functions                                                             */

/******************************************************************************/

void InitGPIO(void) {
    /* Setup functionality and port direction */
    // LED output
    // Disable analog mode
    ANSELGbits.ANSG6 = 0;
    ANSELBbits.ANSB11 = 0;
    ANSELGbits.ANSG15 = 0;
    // Set directions to output
    TRISGbits.TRISG6 = 0;
    TRISBbits.TRISB11 = 0;
    TRISGbits.TRISG15 = 0;
    TRISDbits.TRISD4 = 0;

    // Turn off LEDs for initialization
    LD1_PORT_BIT = 0;
    LD2_PORT_BIT = 0;
    LD3_PORT_BIT = 0;
    LD4_PORT_BIT = 0;

    // Button inputs
    // Disable analog mode
    ANSELAbits.ANSA5 = 0;
    // Set directions to input
    TRISAbits.TRISA5 = 1;
    TRISAbits.TRISA4 = 1;

    TRISDCLR = 1<<11;
}

void init_piezo_buzzer(void) {
    T2CON = 0; // clear timer settings to defaults
    T2CONbits.TCKPS = 7; // divide clock by 256 with prescaler
    TMR2 = 0;
    // Set period for timer
//    PR2 = (100000000/(256 * 5000))-1;    
    // Set initial duty cycle to 50%
    OC8R = (100000000/(256 * 5000))/2;
    // Set reload duty cycle to 50%
    OC8RS = (100000000/(256 * 5000))/2;
    // Configure OC5 control register
    OC8CONbits.ON = 1;
    OC8CONbits.OC32 = 0;    // 16 bit mode
    OC8CONbits.OCTSEL = 0; // Select timer 2
    OC8CONbits.OCM = 6; // Select PWM mode without fault pin
    // Map OC8 signal to pin D4 (LED LD2)
    RPD12R = 12; // Select OC8
  //  RPD4R = 12; // Select OC8
    // Start Timer 2
    T2CONbits.ON = 1;
}

void InitApp(void) {
    // Initialize peripherals
    InitGPIO();
    uart4_init();
    init_piezo_buzzer();
}

void Delay(int t)
{
    while (t--);
}

void security()
{
    char c;
    int b = 0;
    int32_t pos_poten;
     while (1) {
        c = U4RXREG;
        if(c == '0')
            b = 0;
        else if(c == '1') 
            b = 1;
        if(b == 0)
        {
            PR2 = 0;
            LD1_PORT_BIT = 0;
            LD4_PORT_BIT = 0;
        }
        else if(b == 1)
        {
             LD1_PORT_BIT = 1;
             Delay(1000000);
             LD1_PORT_BIT = 0;
             Delay(1000000);
        }
        
        if(BTN1_PORT_BIT == 1 && b == 1)
        {
            LD4_PORT_BIT = 1;
        }
        
        if(LD4_PORT_BIT == 1)
            PR2 = PWM_PERIOD_COUNTS_5 - 1;
}
}