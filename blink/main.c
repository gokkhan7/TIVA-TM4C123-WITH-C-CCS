
#include "stdint.h"
#include "stdbool.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "driverlib/sysctl.h"
#include "driverlib/sysctl.c"
#include "driverlib/pin_map.h"
#include "math.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"

void main(void)
{

    SysCtlClockSet(
            SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
                    | SYSCTL_OSC_MAIN); //clock ayarý yapýldý (40000000) 40MHz
    SysCtlClockGet();

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); //portfaktif
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,
                          GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3); //portfde 1,2,3 pinler cýkýs olarak tanýmlandý

    while (1)
    {
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 2);   //kirmizi led
        SysCtlDelay(13333333);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0);
        /////////////////////////////////////////////
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 4);  // mavi led
        SysCtlDelay(13333333); // burda set edip sonradan rst etmediði için eger aralara 0 koymasaydým üstüne yanacaktý.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
        /////////////////////////////////////////////
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 8);   // yeþil led
        SysCtlDelay(13333333);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0);
        //////////////////////////////////////////////
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 14); //beyaz
        SysCtlDelay(13333333);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3, 0);
        break;

    }

}
