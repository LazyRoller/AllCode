/*  Simulation and testing of PWM unifinished / in progress */

#include "mbed.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//use pwm to flash LED
PwmOut PWM(p26);
DigitalIn button(p19);
//Create a serial connection over our USB
Serial pc(USBTX, USBRX);


int main() {
    // specify period first, then everything else
    //PWM.period(4.0f);   // 4 second period = .250Hz
    //PWM.write(0.50f);   // 50% duty cycle
    //while(1);           //LED will flash

 
    while(1) {
        //there is a counter that will be incremented every time the button is pressed.  this will switch the cases
        int counter = 0;
        if(button == 1)
        {
            counter++;
            
            if(counter > 3)
            {  
                counter = 0;
            }
        }
        if(counter == 0)
        {
            printf("counter is 0");
        }
        
        if(counter == 1)
        {
            printf("counter is 1");
        }
        if(counter == 2)
        {
            printf("counter is 2");
        }
        if(counter == 3)
        {
            printf("counter is 3");
        }
        
        /*switch (counter) {
        
            case 0:    // sensor is covered
        
                PWM.period_us(50.0f);   // 50uS period = 20kHz
                PWM.write(0.05f);   // 5% duty cycle
                wait(3.0);
                break;
        
            case 1:    // sensor in dim light
                PWM.period_us(50.0f);   // 50uS period = 20kHz
                PWM.write(0.05f);   // 5% duty cycle      
                wait(3.0);
                break;
        
            case 2:    // sensor in medium light
                PWM.period_us(50.0f);   // 50uS period = 20kHz
                PWM.write(0.05f);   // 5% duty cycle       
                wait(3.0);
                break;
        
            case 3:    // bright light shining on sensor
                PWM.period_us(50.0f);   // 50uS period = 20kHz
                PWM.write(0.05f);   // 5% duty cycle        
                wait(3.0);
                break;
                
            //default:   // error situation
            
               // pc.printf("error\n");
 
        }
        
        wait(0.5);        // delay in between reads for stability
 
    }*/
    }

}