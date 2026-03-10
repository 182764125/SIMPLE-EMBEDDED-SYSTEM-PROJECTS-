// Project 3: Temperature Monitoring System
int sensorPin = A1; // Temperature sensor connected to A1
int ledPin = 12;    // Indicator LED connected to 12

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(sensorPin);
  
  // Converting the analog reading to Voltage
  float voltage = sensorReading * (5.0 / 1024.0);
  
  // Converting Voltage to Celsius (For TMP36 sensor)
  float temperatureC = (voltage - 0.5) * 100;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // Threshold: If temperature is above 30 degrees, turn on LED
  if (temperatureC > 30) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}
