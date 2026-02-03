void fire(){
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(10, HIGH);

    delay(250);

    digitalWrite(6, HIGH);
    digitalWrite(10, LOW);
    delay(250);
}
void idle(){
   digitalWrite(3, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
}
int switchState = 0;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  if(switchState == LOW){
    idle;
  }
  else{
    fire;
  }
}
