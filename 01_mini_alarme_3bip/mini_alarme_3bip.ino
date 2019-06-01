
  const int ledPin = 5;     //sortie LED
  const int inputPin = 2;   //capteur de mouvement
  const int pinSpeaker = 6; //sortie buzzer
  int val = 0; 

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);     //definition sortie
  pinMode(inputPin, INPUT);    //definition entrée
  pinMode(pinSpeaker, OUTPUT); //definition sortie
}



void joueSon(long duree, int frequence){
  // fonction sur la durée du son
  duree *= 1000;               // en milliseconde
  int period = (1.0/frequence)*1000000;
  long temps_passe = 0;

  while (temps_passe < duree){
    digitalWrite(pinSpeaker,HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(pinSpeaker, LOW);
    temps_passe = temps_passe + period; 
  }
} 


void loop() {
  val = digitalRead(inputPin);
  if (val == HIGH){   
    digitalWrite(ledPin, HIGH);
    joueSon(300, 160);
    delay(150);
    joueSon(300, 60);
    delay(150);
    joueSon(300, 1060);
    delay(150);
  }
  else{
    digitalWrite(ledPin, LOW);
    joueSon(0, 0);
    delay(300); 
  }
}
