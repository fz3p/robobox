#include <IRremote.h>

long val;
int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn(); 
}

void dump(decode_results*results){
  int count = results->rawlen;
  Serial.println("Signal reçu !");
  val = results->value; 
  Serial.println(val, DEC);
  Serial.print("Longueur du signal (");
  Serial.print(count,DEC);
  Serial.println("):");

  // permet de recuperer le tableau des codes
  for (int i = 0 ; i < count;i++){
    Serial.print(i);
    if ((i % 2) == 1) {
      Serial.print(" : Pair : ");
      Serial.println(results->rawbuf[i]*USECPERTICK, DEC);
    }else{
      Serial.print(" Impair : ");
      Serial.println(-(int)results->rawbuf[i]*USECPERTICK, DEC);
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results) == 1){
    dump(&results);
    irrecv.resume(); //receive next value
  }
}
