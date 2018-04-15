
#include <Servo.h>

Servo monServo1; 
Servo monServo2;
int posiMoteur=0; 


void setup() {
  monServo1.attach(2);
  monServo2.attach(4);
}

void loop() {
  for(posiMoteur=0; posiMoteur<=90; posiMoteur +=1)
    {
      monServo1.write(posiMoteur);
      monServo2.write(posiMoteur);
      delay(15);
    }
      for(posiMoteur=90;posiMoteur>=0;posiMoteur-=1)
    {
      monServo1.write(posiMoteur);
      monServo2.write(posiMoteur);
      delay(15);
    }
}
