const int sensorPin = A0;
const float baselineTemp = 28.0;
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
}
void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value:  ");
  Serial.print(sensorVal);
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", Volts:; ");
  Serial.print(voltage);
  float temperature = (voltage-0.5) * 100;
  Serial.print(", Temperature: ");
  Serial.println(temperature);
  if(temperature<baselineTemp+2){
  digitalWrite(3, LOW);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  }else if(temperature>baselineTemp+2 && temperature<baselineTemp+3){
  digitalWrite(3, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  }else if(temperature>baselineTemp+3 && temperature<baselineTemp+4){
  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  }else if(temperature>baselineTemp+4){
  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  delay(1000);
  }
  delay(500);
}
