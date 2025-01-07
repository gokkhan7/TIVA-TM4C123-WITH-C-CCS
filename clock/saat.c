/*
 * saat.c
 *
 *  Created on: 17 Kas 2024
 *      Author: gkhn1
 */
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.c"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.c"
#include "saat.h"

void LcdEnable(){  // Lcd Enable pin ac kapa (sinyal ac kapa)
    GPIOPinWrite(LCDPORT,EN,0x02);
    Beklet(1000);
    GPIOPinWrite(LCDPORT,EN,0x00);
}
void send_common(char c) {   // Lcd ayarlarý icin rs=0' a cek data portlarýna yaz enable ac kapa
    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0xf0));
    GPIOPinWrite(LCDPORT,RS,0x00);
    LcdEnable();
    Beklet(50000);

    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0x0f)<<4); // Low nibble degerlerini maskeleme ile al
    GPIOPinWrite(LCDPORT,RS,0x00);
    LcdEnable();
    Beklet(50000);
}

void write_char(char c){  // Rs degerini 1'e cek data portlarýna yaz ve enable(signal) pinin ac kapa
    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0xf0));
    GPIOPinWrite(LCDPORT,RS,0x01);
    LcdEnable();
    Beklet(50000);

    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0x0f)<<4);
    GPIOPinWrite(LCDPORT,RS,0x01);
    LcdEnable();
    Beklet(50000);
}
void home(){  // Lcd return home komutu
    send_common(0x02);
    Beklet(1000);
}
void Lcd_clear(void){ // Lcd ekraný temizle ve eve dön komutu
    send_common(0x01);   //lcd clear
    send_common(0x02);  //return home
    Beklet(1000);
}
void LcdDisplayOn(){  // Lcd ekraný acýk cursor ve blink kapalý
    send_common(0x0c);  //sadece display on
    Beklet(1000);
}

void LcdCursorOn(){ // Lcd ekraný acýk cursor acýk
    send_common(0x0e); // hem display hem cursor
    Beklet(1000);
}
void LcdBlinkOn(){ // Lcd ekraný cursor ve blink acýk
    send_common(0x0f);  // display cursor ve blink on
    Beklet(1000);
}

void Gotox_y(char row, char col){ // Lcd satir ve sutun ayarlarý
    char adress;    // Baslangýc noktasý 0,0 olarak ayarlandý
    if(row == 0)
        adress=0;
    else if(row==1)
        adress=0x40;
    else
        adress=0;
    adress|=col;
    send_common(0x80 | adress);  // Lcd ekranýnda adresleme 0x80h den baslar ve (gelen deger 0. satir ise 80h+sutun) (1.satir ise 80h+40h+sutun sayisi olur)
}

void Lcdwritestring(const char  dizi[], int dizisayisi){ //Lcd cok karakter yazmasý icin tek karakter yazma modunu bir dongu icersinde cagirdik
    char i=0;
    while(dizisayisi--){ // Dizinin eleman sayýsý degeri 0 olmadýkca karakterleri ekrana bas
        write_char(dizi[i++]);
    }
}
void Lcd_dec(){ // Lcd baslangýc ayarlarý
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);    // 3 kez 30h gonder
    GPIOPinTypeGPIOOutput(LCDPORT, 0xFF);
    Beklet(50000);
    GPIOPinWrite(LCDPORT,RS,0x00);
    GPIOPinWrite(LCDPORT, ALL_DATA,  0x30 );
    LcdEnable();
    Beklet(50000);
    GPIOPinWrite(LCDPORT, ALL_DATA,  0x30 );
    LcdEnable();
    Beklet(50000);
    GPIOPinWrite(LCDPORT, ALL_DATA,  0x30 );
    LcdEnable();
    Beklet(50000);


    GPIOPinWrite(LCDPORT, ALL_DATA,  0x20 ); //0B0010 // 4BIT LCD 0B001DL
    Beklet(50000);
    GPIOPinWrite(LCDPORT, ALL_DATA,  0xF0);  //0BNF** // N=1 ÝCÝN 2 SATÝR F=1 ÝCÝN 5X10 DOT
    Beklet(50000);

    send_common(0x0e); // EKRAN ACIK kursor acýk
    send_common(0x01); // ekraný temizle
    send_common(0x06); // entry mode set 0b0I/DS0 //ID=1 ÝMLEC OTO KAY S =0 EKRAN SABIT
    Lcd_clear();
}



