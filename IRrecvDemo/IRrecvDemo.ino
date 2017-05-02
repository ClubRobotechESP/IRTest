/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 7;
boolean lampe = false;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    int valeur = getValue(results.value);
    Serial.println(valeur);
    if(valeur == 10 ){
      lampe =!lampe;
       digitalWrite(10, lampe);
    }
     
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}


int getValue(long value){
  int val =-1;
  switch(value){
    case 16582903 : val=1;break;
    case 16615543 : val=2;break;
    case 16599223 : val=3;break;
    case 16591063 : val=4;break;
    case 16623703 : val=5;break;
    case 16607383 : val=6;break;
    case 16586983 : val=7;break;
    case 16619623 : val=8;break;
    case 16603303 : val=9;break;
    case 16593103 : val=0;break;
    case 16580863 : val=10;break;
    default : val=-1;
    
  }
  return val;
}

