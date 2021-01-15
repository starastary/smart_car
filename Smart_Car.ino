#include <IRremote.h>
int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;

int motor1pin1 = 3;
int motor1pin2 = 4;
int motor2pin1 = 1;
int motor2pin2 = 2;

void setup()
{ 
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(0, OUTPUT); 
  pinMode(5, OUTPUT);
  STOP();
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
void loop() {
    if (irrecv.decode(&results)) {
    Serial.println(results.value);
    switch(results.value) {
      case 16732845:
        STOP();
        break;
      case 16736925:
        FWD();
        break;
      case 16754775:
        REVERSE();
        break;
      case 1386468383:
        LEFT();
        break;
      case 16761405:
        RIGHT();
        break;
    }
    irrecv.resume(); // Receive the next value
  }
}


void STOP() {
    analogWrite(0, 0); //ENA pin
    analogWrite(5, 0); //ENB pin
    
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, HIGH);
}

void FWD() {
    analogWrite(0, 200); //ENA pin
    analogWrite(5, 200); //ENB pin

    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
}

void REVERSE() {
    analogWrite(0, 200); //ENA pin
    analogWrite(5, 200); //ENB pin

    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
}

void LEFT() {
    analogWrite(0, 200); //ENA pin
    analogWrite(5, 200); //ENB pin

    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
}

void RIGHT() {
    analogWrite(0, 200); //ENA pin
    analogWrite(5, 200); //ENB pin

    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
}
