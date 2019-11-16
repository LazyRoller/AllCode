// LCD Test - "Hello World!" Display



#include "mbed.h"
#include "TextLCD.h"

char word[5];
int speedvalue=0;
int wheelrotation=2;
char PB1=0;
char PB2 =0;

DigitalIn RFforward (p11);    //Remote Button A
DigitalIn RFreverse (p12);    //Remote Button B
DigitalIn RFstop (p13);       //Remote Button C
DigitalIn RFremoteD (p14);    //Remote Button D


TextLCD lcd(p15, p16, p17, p18, p19, p20); // rs, e, d4-d7


void remotefunctionA()   //Clockwise rotation function
{
if (RFforward ==1); 
    {
    wheelrotation=1;
    }
    else                  //default stop
        {
        wheelrotation=2; 
        speedvalue==0; 
        }
}


void remotefunctionB()   //CounterClockwise rotation function
{
if (RFreverse ==1); 
    {
    wheelrotation=0;
    }
if (RFreverse ==0);                    //default stop
    {
    wheelrotation=2;  
    speedvalue==0;
    }
}

void remotefunctionC()   //speed level increase
{
if (RFstop ==1); 
    {
    speedvalue+=5;
    }
}


int main() 
{
    while (PB2 ==1) //Power button
    {
    remotefunctionA();
    remotefunctionB();
    if (PB1 ==1)
        {
        lcd.cls(); //Clear screen
        }
        
    lcd.locate(0,0);
    lcd.printf("Direction");
    
    if (wheelrotation==0) //Reverse direction
        {
        word[0]='c';
        word[1]='c';
        word[2]='w';
        word[3]=0;
              
        } 
    else if (wheelrotation==1) //Forward Direction
        {
        word[0]='c';
        word[1]='w';
        word[2]=0;
        }
    else                            //Default to stop
        {
        word[0]='s';
        word[1]='t';
        word[2]='o';
        word[3]='p';
        word[4]=0;
        }
     }   
        
    lcd.printf(word);           //print string of word on to lcd screen
    lcd.locate(1,0);            //second line is speed value
    lcd.printf("speed %i",speedvalue);
    
}
