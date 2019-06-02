#include <IRremote.h>

long val;
int IRpin = 10;
int pinLed = 4;

IRrecv irrecv(IRpin);
decode_results results; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(pinLed,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results) == 1){
    val = results.value; 
    Serial.println(val,DEC);
    irrecv.resume();
  }
  if(val == 16724175){
    digitalWrite(pinLed, HIGH);
  }else if(val!= 16724175){
    digitalWrite(pinLed, LOW);
  }
}
