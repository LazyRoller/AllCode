//Program to test RF and mbed connectivity

#include "mbed.h"

BusIn rf_digitalin (p11, p12, p14, p14);

BusOut lights (p7, p8, p9, p10);

int main() {
    while(1) 
    {
    if (rf_digitalin == 0x8)
        {
        lights = 0x8;
        }
    else
        {
        lights = 0x0;
        }
    }
}