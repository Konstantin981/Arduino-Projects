int sensor_value;
int sensor_min=1023;
int sensor_max=0;
const int ledPin=13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalwrite(ledPin, HIGH);
  while (millis()<5000){
    sensor_value = analogRead(A0);
    if(sensor_value>sensor_max)
      sensor_max = sensor_value;
    if(sensor_value<sensor_min)
      sensor_min = sensor_value;
  }
  digitalWrite(ledPin, LOW);
}

void loop() {
  sensor_value = analogRead(A0);
  int pitch = map(sensor_vakue,sensor_min,sensor_max, 50,4000);
  tone(8,pitch,20);
  delay(10);
}
