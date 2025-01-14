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


// UART'� yap�land�rma fonksiyonu
void ConfigureUART(void) {
    // UART0 mod�l�n� etkinle�tir
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // GPIO Pinlerini UART moduna yap�land�r
    GPIOPinConfigure(GPIO_PA0_U0RX); // PA0'� UART0 RX olarak yap�land�r
    GPIOPinConfigure(GPIO_PA1_U0TX); // PA1'i UART0 TX olarak yap�land�r
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // UART saat kayna��n� ayarla
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    // UART'� ba�lat
    UARTStdioConfig(0, 115200, 16000000); // 115200 baud h�z�, 16 MHz saat
}

// Kullan�c�dan girdi alma fonksiyonu
void GetUserInput(float *num1, float *num2, char *operation) {
    UARTprintf("Birinci sayiyi girin: ");
    *num1 = UARTgetc(); // Kullan�c�dan birinci say�y� al
    UARTprintf("�kinci sayiyi girin: ");
    *num2 = UARTgetc(); // Kullan�c�dan ikinci say�y� al

    UARTprintf("��lem t�r�n� secin (+, -, *, /): ");
    *operation = UARTgetc(); // Kullan�c�dan i�lem t�r�n� al
}

// ��lemi ger�ekle�tirme fonksiyonu
void PerformOperation(float num1, float num2, char operation) {
    float result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            UARTprintf("Sonu�: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            UARTprintf("Sonu�: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            UARTprintf("Sonu�: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                UARTprintf("Sonu�: %.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                UARTprintf("Hata: S�f�ra b�lme hatas�!\n");
            }
            break;
        default:
            UARTprintf("Ge�ersiz i�lem t�r�!\n");
            break;
    }
}

// Ana fonksiyon
int main(void) {
    // Sistemi 50 MHz'de �al��acak �ekilde ayarla
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // UART'� yap�land�r
    ConfigureUART();

    float num1, num2;
    char operation;

    while (1) {
        GetUserInput(&num1, &num2, &operation); // Kullan�c�dan girdi al
        PerformOperation(num1, num2, operation); // ��lemi ger�ekle�tir
    }
}
