/*
 * File:   main.c
 * Author: hector
 *
 * Created on 6 de enero de 2022, 04:34 PM
 */


#include <xc.h>
#define _XTAL_FREQ 500000                               //Used by the XC8 delay_ms(x) macro

//config bits that are part-specific for the PIC16F1829
#pragma config FOSC=INTOSC, WDTE=OFF, PWRTE=OFF, MCLRE=OFF, CP=OFF, CPD=OFF, BOREN=ON, CLKOUTEN=OFF, IESO=OFF, FCMEN=OFF
#pragma config WRT=OFF, PLLEN=OFF, STVREN=OFF, LVP=OFF

void main(void) {
    unsigned int delay;                                 //create a variable of 16 bits in length
    
    OSCCON = 0b00111000;                                //500KHz clock speed
    TRISBbits.TRISB0 = 0;                               //using pin as output
    __delay_ms(1000);    // delay = 11250;
    while (1) {
        while(delay-- != 0)continue;                    //each instruction is 8us (1/(500KHz/4))
        LATBbits.LATB0 ^= 1;                            //toggle the LED
     //   delay = 11250;  
        __delay_ms(1000); 
        //assign a value since it is at 0 from the delay loop
    }
                                                        //Alternative HI-TECH method using a predefined and more accurate macro
                                                        //    while(1){
                                                        //        __delay_ms(1000);
                                                        //        LATCbits.LATC0 ^= 1;
                                                        //
                                                        //    }

}