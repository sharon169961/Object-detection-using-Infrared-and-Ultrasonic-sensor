int duration;
int distance;

const int trigPin = 10;  // Ultrasonic sensor trigger pin
const int echoPin = 11;  // Ultrasonic sensor echo pin
const int irSensorPin = 3;  // IR sensor pin
const int ledPin = 13;  // LED pin for visual feedback

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set pin modes for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Set pin modes for IR sensor and LED
  pinMode(irSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // IR Sensor behavior
  if (digitalRead(irSensorPin) == LOW) { // Object detected
    digitalWrite(ledPin, HIGH);  // Turn on LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED
  }

  // Ultrasonic sensor behavior
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  // Small delay to prevent overwhelming the serial monitor
}
