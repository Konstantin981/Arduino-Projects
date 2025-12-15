int buttons[6] = {2, 0, 0, 0, 0, 0};

int notes[] = {262,294,330,349};
void setup() {
  Serial.begin(9600);
}

void loop() {
  int key_val = analogRead(A0);
  Serial.println(key_val);
  if(key_val == 1023){
    tone(8, notes[0]);
  }
  else if(key_val>=990 && key_val<=1010){
    tone(8, notes[1]);
  }
  else if(key_val>=505 && key_val <= 515){
    tone(8, notes[2]);
  }
  else if(key_val>=5 && key_val<=10){
    tone(8, notes[3]);
  }
  else{
    noTone(8);
  }
}