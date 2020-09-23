#include "mbed.h"

DigitalOut greLed1(p30);
DigitalOut greLed2(p29);
DigitalOut greLed3(p28);
DigitalOut redLed1(p11);
DigitalOut redLed2(p12);
DigitalOut redLed3(p13);
DigitalIn sw1(p19,PullUp);
DigitalIn sw2(p20,PullUp);
DigitalIn swFlip(p21,PullDown);

int main() {
    greLed1 = 1;
    greLed2 = 1;
    greLed3 = 1;
    redLed1 = 0;
    redLed2 = 0;
    redLed3 = 0;
        
    while(1){
        if (sw1 == 0) {
            if (greLed1 == 1) {
                greLed1 = !greLed1;
                wait(0.2);
            } else if (greLed2 == 1) {
                greLed2 = !greLed2;
                wait(0.2);
            } else if (greLed3 == 1) {
                greLed3 = !greLed3;
                wait(0.2);
            } else if (greLed3 == 0) {
                greLed1 = 1;
                greLed2 = 1;
                greLed3 = 1;
                wait(0.2);
            }
        }
        if (sw2 == 0) {
            if (redLed1 == 0) {
                redLed1 = !redLed1;
                wait(0.2);
            } else if (redLed2 == 0) {
                redLed2 = !redLed2;
                wait(0.2);
            } else if (redLed3 == 0) {
                redLed3 = !redLed3;
                wait(0.2);
            } else if (redLed3 == 1) {
                redLed1 = 0;
                redLed2 = 0;
                redLed3 = 0;
                wait(0.2);
            }
        }
        if (swFlip == 1) {
            int tempLed = !redLed1;
            redLed1 = !greLed1;
            greLed1 = tempLed;
            
            tempLed = !redLed2;
            redLed2 = !greLed2;
            greLed2 = tempLed;
            
            tempLed = !redLed3;
            redLed3 = !greLed3;
            greLed3 = tempLed;
            wait(0.2);
        }
    }
}
