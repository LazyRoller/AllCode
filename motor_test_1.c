//Motor Driver Test 1

#include "mbed.h"

float pause = 0.002;

DigitalIn PB1 (p11);           //Start the while loop forward on motor
DigitalIn PB2 (p12);           //start the while loop for Testing

DigitalOut motorlineA (p21);   //Line A
DigitalOut motorlineB (p22);   //Line B
DigitalOut motorlineC (p23);   //Line C

int main() 
{
    while (1)
    {
        
    motorlineA=0;
    motorlineB=0;
    motorlineC=0;
    while (PB1 ==1)            //Motor test with 2mS wait time between phase
        {
        motorlineA=1;
        wait(pause);
        motorlineA=0;
        motorlineB=1;
        wait(pause);
        motorlineB=0;
        motorlineC=1;
        wait(pause);
        motorlineC=0;
        }                      //End of 3 phase Motor Loop
        
        
    while (PB2 ==1)            //Timing test at 5 second intervals with lines pulsing
        {
        motorlineC=1;
        wait(5);
        motorlineC=0;
        motorlineB=1;
        wait(5);
        motorlineB=0;
        motorlineA=1;
        wait(5);
        motorlineA=0;
        }                     //End of Test Loop
    }                         //End of loop 
        
}                             //End of main
