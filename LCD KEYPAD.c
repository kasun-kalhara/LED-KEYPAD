/*
 * File:   LCD KEYPAD.c
 * Author: Kasun
 *
 * Created on October 2, 2021, 4:49 PM
 */

#define _XTAL_FREQ 4000000
#include <xc.h>
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// Define pins for keypad
#define RowA    RB0
#define RowB    RB1
#define RowC    RB2
#define RowD    RB3
#define C1      RB4
#define C2      RB5
#define C3      RB6
#define Keypad_PORT PORTB
#define Keypad_PORT_Dir TRISB
// Define pins for LCD
#define RS      RD2
#define EN      RD3
#define D4      RD4
#define D5      RD5
#define D6      RD6
#define D7      RD7
#include "lcd1.h"
#include "keypad.h"


void main(void) {
    TRISC =0x00;
    TRISD =0x00;
    char str[20];
    char Key = 'n';
    InitKeypad();
    Lcd_Init();
    while(1){
        Lcd_Clear();
        Lcd_Set_Cursor(1,1);
        Lcd_Write_String("AA1307");
        while(1){
            Key = GetKey();
            Lcd_Clear();
            Lcd_Set_Cursor(1,1);
            Lcd_Write_Char(Key);
        }
    }  
    
    return;
}
