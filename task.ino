// Define the pin numbers
const int sensorPin = 2; // Motion sensor connected to digital pin 2
const int ledPin = 13;    // Built-in LED connected to digital pin 13

volatile bool motionDetected = false; // Volatile variable for ISR communication

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Configure the motion sensor pin for input
  pinMode(sensorPin, INPUT);

  // Enable pin change interrupt for the motion sensor pin
  attachInterrupt(digitalPinToInterrupt(sensorPin), motionISR, CHANGE);
}

void loop() {
  // Since the motion detection is handled by interrupt,
  // the loop function can remain empty 
}

// Interrupt Service Routine for motion detection
void motionISR() {
  // Read the value from the motion sensor
  int motionSensorValue = digitalRead(sensorPin);

  // Print the sensor value to the Serial Monitor
  Serial.print("Motion Sensor: ");
  Serial.println(motionSensorValue);

  // Check if motion is detected
  if (motionSensorValue == HIGH) {
    // If motion is detected, turn on the LED
    digitalWrite(ledPin, HIGH);
    // Print the LED status to the Serial Monitor
    Serial.println("LED Status: ON");
  } else {
    // If no motion is detected, turn off the LED
    digitalWrite(ledPin, LOW);
    // Print the LED status to the Serial Monitor
    Serial.println("LED Status: OFF");
  }
}
