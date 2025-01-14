#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/uart.h"
#include "utils/uartstdio.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/pin_map.h"
#include "utils/uartstdio.h"


// UART'ý yapýlandýrma fonksiyonu
void ConfigureUART(void) {
    // UART0 modülünü etkinleþtir
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // GPIO Pinlerini UART moduna yapýlandýr
    GPIOPinConfigure(GPIO_PA0_U0RX); // PA0'ý UART0 RX olarak yapýlandýr
    GPIOPinConfigure(GPIO_PA1_U0TX); // PA1'i UART0 TX olarak yapýlandýr
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // UART saat kaynaðýný ayarla
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    // UART'ý baþlat
    UARTStdioConfig(0, 115200, 16000000); // 115200 baud hýzý, 16 MHz saat
}

// Kullanýcýdan girdi alma fonksiyonu
void GetUserInput(float *num1, float *num2, char *operation) {
    UARTprintf("Birinci sayiyi girin: ");
    *num1 = UARTgetc(); // Kullanýcýdan birinci sayýyý al
    UARTprintf("Ýkinci sayiyi girin: ");
    *num2 = UARTgetc(); // Kullanýcýdan ikinci sayýyý al

    UARTprintf("Ýþlem türünü secin (+, -, *, /): ");
    *operation = UARTgetc(); // Kullanýcýdan iþlem türünü al
}

// Ýþlemi gerçekleþtirme fonksiyonu
void PerformOperation(float num1, float num2, char operation) {
    float result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            UARTprintf("Sonuç: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            UARTprintf("Sonuç: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            UARTprintf("Sonuç: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                UARTprintf("Sonuç: %.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                UARTprintf("Hata: Sýfýra bölme hatasý!\n");
            }
            break;
        default:
            UARTprintf("Geçersiz iþlem türü!\n");
            break;
    }
}

// Ana fonksiyon
int main(void) {
    // Sistemi 50 MHz'de çalýþacak þekilde ayarla
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // UART'ý yapýlandýr
    ConfigureUART();

    float num1, num2;
    char operation;

    while (1) {
        GetUserInput(&num1, &num2, &operation); // Kullanýcýdan girdi al
        PerformOperation(num1, num2, operation); // Ýþlemi gerçekleþtir
    }
}
