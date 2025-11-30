#include <Servo.h>
Servo myServo;
int const pot_pin = A0;
int pot_val;
int angle;
void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  pot_val = analogRead(pot_pin);
  Serial.print("potVal: ");
  Serial.print(pot_val);
  angle = map(pot_val, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);
  myServo.write(angle);
  delay(15);
}
