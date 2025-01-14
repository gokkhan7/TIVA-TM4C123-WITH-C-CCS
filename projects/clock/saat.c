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
void send_common(char c) {   // Lcd ayarlar� icin rs=0' a cek data portlar�na yaz enable ac kapa
    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0xf0));
    GPIOPinWrite(LCDPORT,RS,0x00);
    LcdEnable();
    Beklet(50000);

    GPIOPinWrite(LCDPORT,ALL_DATA,(c & 0x0f)<<4); // Low nibble degerlerini maskeleme ile al
    GPIOPinWrite(LCDPORT,RS,0x00);
    LcdEnable();
    Beklet(50000);
}

void write_char(char c){  // Rs degerini 1'e cek data portlar�na yaz ve enable(signal) pinin ac kapa
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
void Lcd_clear(void){ // Lcd ekran� temizle ve eve d�n komutu
    send_common(0x01);   //lcd clear
    send_common(0x02);  //return home
    Beklet(1000);
}
void LcdDisplayOn(){  // Lcd ekran� ac�k cursor ve blink kapal�
    send_common(0x0c);  //sadece display on
    Beklet(1000);
}

void LcdCursorOn(){ // Lcd ekran� ac�k cursor ac�k
    send_common(0x0e); // hem display hem cursor
    Beklet(1000);
}
void LcdBlinkOn(){ // Lcd ekran� cursor ve blink ac�k
    send_common(0x0f);  // display cursor ve blink on
    Beklet(1000);
}

void Gotox_y(char row, char col){ // Lcd satir ve sutun ayarlar�
    char adress;    // Baslang�c noktas� 0,0 olarak ayarland�
    if(row == 0)
        adress=0;
    else if(row==1)
        adress=0x40;
    else
        adress=0;
    adress|=col;
    send_common(0x80 | adress);  // Lcd ekran�nda adresleme 0x80h den baslar ve (gelen deger 0. satir ise 80h+sutun) (1.satir ise 80h+40h+sutun sayisi olur)
}

void Lcdwritestring(const char  dizi[], int dizisayisi){ //Lcd cok karakter yazmas� icin tek karakter yazma modunu bir dongu icersinde cagirdik
    char i=0;
    while(dizisayisi--){ // Dizinin eleman say�s� degeri 0 olmad�kca karakterleri ekrana bas
        write_char(dizi[i++]);
    }
}
void Lcd_dec(){ // Lcd baslang�c ayarlar�
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
    GPIOPinWrite(LCDPORT, ALL_DATA,  0xF0);  //0BNF** // N=1 �C�N 2 SAT�R F=1 �C�N 5X10 DOT
    Beklet(50000);

    send_common(0x0e); // EKRAN ACIK kursor ac�k
    send_common(0x01); // ekran� temizle
    send_common(0x06); // entry mode set 0b0I/DS0 //ID=1 �MLEC OTO KAY S =0 EKRAN SABIT
    Lcd_clear();
}



