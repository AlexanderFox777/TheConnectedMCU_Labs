#include <stdint.h>
/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

// Add I/O name macros here
#define LD1_PORT_BIT        LATGbits.LATG6
#define LD2_PORT_BIT        LATDbits.LATD4
#define LD3_PORT_BIT        LATBbits.LATB11
#define LD4_PORT_BIT        LATGbits.LATG15

#define BTN1_PORT_BIT       PORTAbits.RA5
#define BTN2_PORT_BIT       PORTAbits.RA4

#define PWM_FREQ_HZ_0         (5000.0f)
#define PWM_FREQ_HZ_1         (200.0f)
#define PWM_FREQ_HZ_2         (300.0f)
#define PWM_FREQ_HZ_3         (400.0f)
#define PWM_FREQ_HZ_4         (500.0f)
#define PWM_FREQ_HZ_5         (600.0f)
#define PWM_FREQ_HZ_6         (700.0f)
#define PWM_FREQ_HZ_7         (800.0f)
#define PWM_FREQ_HZ_8         (900.0f)
#define PWM_FREQ_HZ_9         (1000.0f)
#define PWM_FREQ_HZ_10         (1100.0f)
#define PWM_FREQ_HZ_11         (1200.0f)
#define PWM_FREQ_HZ_12         (1300.0f)
#define PWM_FREQ_HZ_13         (1400.0f)
#define PWM_FREQ_HZ_14         (1500.0f)
#define PWM_FREQ_HZ_15         (1600.0f)
#define PWM_PERIOD_COUNTS_0   (100000000/(256 * PWM_FREQ_HZ_0))
#define PWM_PERIOD_COUNTS_1   (100000000/(256 * PWM_FREQ_HZ_1))
#define PWM_PERIOD_COUNTS_2   (100000000/(256 * PWM_FREQ_HZ_2))
#define PWM_PERIOD_COUNTS_3   (100000000/(256 * PWM_FREQ_HZ_3))
#define PWM_PERIOD_COUNTS_4   (100000000/(256 * PWM_FREQ_HZ_4))
#define PWM_PERIOD_COUNTS_5   (100000000/(256 * PWM_FREQ_HZ_5))
#define PWM_PERIOD_COUNTS_6   (100000000/(256 * PWM_FREQ_HZ_6))
#define PWM_PERIOD_COUNTS_7   (100000000/(256 * PWM_FREQ_HZ_7))
#define PWM_PERIOD_COUNTS_8   (100000000/(256 * PWM_FREQ_HZ_8))
#define PWM_PERIOD_COUNTS_9   (100000000/(256 * PWM_FREQ_HZ_9))
#define PWM_PERIOD_COUNTS_10   (100000000/(256 * PWM_FREQ_HZ_10))
#define PWM_PERIOD_COUNTS_11   (100000000/(256 * PWM_FREQ_HZ_11))
#define PWM_PERIOD_COUNTS_12   (100000000/(256 * PWM_FREQ_HZ_12))
#define PWM_PERIOD_COUNTS_13   (100000000/(256 * PWM_FREQ_HZ_13))
#define PWM_PERIOD_COUNTS_14   (100000000/(256 * PWM_FREQ_HZ_14))
#define PWM_PERIOD_COUNTS_15   (100000000/(256 * PWM_FREQ_HZ_15))
#define MAX_ADC_VALUE       (4095)
#define VR1_AN_CHAN_NUM     (8)
// typedef uint8_t BYTE;

/******************************************************************************/
/* User Function Prototypes                                                    /
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

void InitApp(void);         /* I/O and Peripheral Initialization */
void DelayMs(int t);
void security(void);