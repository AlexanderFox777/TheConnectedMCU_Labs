/**
     *\file
     *\brief initialization and system functions
*/

#include <xc.h>          /* Defines special function registers, CP0 regs  */
#include <stdint.h>          /* For uint32_t definition                       */
#include <sys/attribs.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "user.h"            /* variables/params used by user.c               */
#include "OLED.h"
#include "OledChar.h"
#include "OledGrph.h"
#include "UART.h"
#include <string.h>
#include <stdlib.h>

#define X_MAX 128
#define Y_MAX 28
#define X_center 64
#define Y_center 14

volatile    int n, i=0;

/*!
    * \brief GPIO initialization for board,
    * Initialization for buttons and LEDs
    * Disabling analog mode and setting pins directions
*/  
void InitGPIO(void) {
    // LED output
    // Disable analog mode for G6
    ANSELGbits.ANSG6 = 0;
    // Set direction to output for G6
    TRISGbits.TRISG6 = 0;

    // Initialize outputs for other LEDs
    ANSELBbits.ANSB11 = 0;
    ANSELGbits.ANSG15 = 0;

    TRISBbits.TRISB11 = 0;
    TRISGbits.TRISG15 = 0;
    TRISDbits.TRISD4 = 0;

    // Turn off LEDs for initialization
    LD1_PORT_BIT = 0;
    LD2_PORT_BIT = 0;
    LD3_PORT_BIT = 0;
    LD4_PORT_BIT = 0;

    // Initilalize input for BTN1
    // Disable analog mode
    ANSELAbits.ANSA5 = 0;
    // Set direction to input
    TRISAbits.TRISA5 = 1;

    // Initialize input for BTN2
    TRISAbits.TRISA4 = 1;
}

/*!
    * \brief GPIO initialization for schield,
    * Initialization for buttons and LEDs
    * Disabling analog mode and setting pins directions
*/  
void InitBIOSGPIO(void) {
    /* Setup functionality and port direction */
    // LED outputs
    // Disable analog mode
    // Set directions to output
    TRISE = 0;
   
    // Test LEDs
    LATE = 0xff;        
    
    // Turn off LEDs for initialization
    LATE = 0;

    // Button inputs
    ANSELGbits.ANSG7 = 0;
    
    
    
    ANSELEbits.ANSE8 = 0;
    ANSELEbits.ANSE8 = 0;
 
    ANSELCbits.ANSC1 = 0;
    
    // Set directions to input
    TRISGbits.TRISG7 = 1;
    TRISDbits.TRISD5 = 1;
    TRISFbits.TRISF1 = 1;
    TRISAbits.TRISA2 = 1; 
    
    TRISEbits.TRISE8 = 1;
    TRISEbits.TRISE9 = 1;
    TRISAbits.TRISA14 = 1;
    TRISCbits.TRISC1 = 1; 
    

}
/*!
    * \brief App initialization, 
    * Calling initialization functions for GPIO and OLED
    * Basic OLED configuration
*/ 
void InitApp(void) {
    // Initialize peripherals
    InitGPIO();
    InitBIOSGPIO();
    
    OledHostInit();
    OledDspInit();
    OledDvrInit();
}

/*!
    * \brief Task #1,
    * takes semaphore and than outputs text to the OLED
*/ 
void Task1(void * pvParameters) {
    
    uint8_t word[] =  "No-winIwinyou";
    uint8_t displayed_str[16];
    memset(displayed_str, ' ', sizeof(displayed_str));
    displayed_str[6] = word[6];
    displayed_str[15] = '\0';
    uint32_t pos = 6;
    
    while (1) {
       
        // TODO: Take mutex here
        
        xSemaphoreTake(xMutexOLED, portMAX_DELAY);
         
        // TODO: Give mutex here
          OledSetCursor(0,1);
        OledPutString(displayed_str);
        
        if (BTN_3_SCHLD) {
            if(pos < 6) {
                displayed_str[pos] = ' ';
            } else {
                displayed_str[pos] = word[pos];
            }
            pos += 1;
            DelayMs(100);
        }
        if (BTN_4_SCHLD) {
            if(pos > 6) {
                displayed_str[pos] = ' ';
            } else {
               displayed_str[pos] = word[pos];
            }
            pos -= 1;
            DelayMs(100);
        }
        
        xSemaphoreGive(xMutexOLED);
    
        vTaskDelay(1);     
    }
}

/*!
    * \brief Task #2,
    * takes semaphore and than outputs text to the OLED
*/ 
void Task2(void * pvParameters) {
    int n=0; 
   
    char buff1 = 'a';
    char buff2 = '0';
    char buff3 = '7';
    char buff4 = '3';
    
   
    while (1) {
        
        xSemaphoreTake(xMutexOLED, portMAX_DELAY);

       
      if (BIOS_SW4_PORT_BIT==1)
      {
          
            if (BIOS_SW3_PORT_BIT==0)
            {
                OledSetCursor(1, 4);
                OledPutString("Vulkan Kazino");   
            }
            
            if (BIOS_SW3_PORT_BIT==1)
            {
                OledSetCursor(1, 4);
                OledPutString("             ");
                OledSetCursor(1,30);
                OledPutChar(buff1++);
                OledSetCursor(4,30);
                OledPutChar(buff2++);
                OledSetCursor(8,30);
                OledPutChar(buff3++);
                OledSetCursor(12,30);
                OledPutChar(buff4++);
                DelayMs(250);
            }
         
        }
      if (BIOS_SW4_PORT_BIT==0)
      {
            OledSetCursor(1, 4);
            OledPutString("             ");
            OledSetCursor(1,30);
            OledPutChar(' ');
            OledSetCursor(4,30);
            OledPutChar(' ');
            OledSetCursor(8,30);
            OledPutChar(' ');
            OledSetCursor(12,30);
            OledPutChar(' ');
            buff1 = 'a';
            buff2 = '0';
            buff3 = '7';
            buff4 = '3';
       }
        
        // TODO: Give mutex here
        xSemaphoreGive(xMutexOLED);
        vTaskDelay(1);
         
    }
}

// TODO: Define function ClockTask here

// TODO: Define SerialInTask here

void DelayMs(int t) {
    volatile long int count = t*33356;
    
    while (count--)
        ;
}