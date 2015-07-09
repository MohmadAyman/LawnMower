#include "Encoder.h"

        Encoder encoderLeft(2, 3);
        Encoder encoderRight(21,20);
        
        void setup() { 
            attachInterrupt(0, doEncoder, CHANGE); 
            attachInterrupt(2, doEncoder, CHANGE); 
      
            Serial.begin (9600);
        } 
        
        void loop(){
            // do some stuff here - the joy of interrupts is that they take care of themselves
            serial.print(encoderRight.postion);
            serial.print(encoderLeft.postion);
        }
        
  void doEncoder(){
      encoderRight.update();
      encoderLeft.update();
  }    
