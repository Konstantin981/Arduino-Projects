int sensor_low = 1023;
int sensor_high = 0;
int sensor_value;
const int led_pin = 13;
void setup() {
  pinMode(led_pin, OUTPUT);
  digitalWrite(led_pin, HIGH);
  while (millis() < 5000){
    sensor_value = analogRead(A0);
    if (sensor_value > sensor_high){
      sensor_high = sensor_value;
    }
    if (sensor_value < sensor_low){
      sensor_low = sensor_value;
    }
  }
  digitalWrite(led_pin, LOW);
}
void loop() {
  sensor_value = analogRead(A0);
  int pitch = map(sensor_value, sensor_low, sensor_high, 100, 1000);
  tone(8, pitch, 20);
  delay(10);
}
