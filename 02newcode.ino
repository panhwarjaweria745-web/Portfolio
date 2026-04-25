#include <Servo.h>

const int trigPin = 2;      // Trigger pin of the ultrasonic sensor
const int echoPin = 3;     // Echo pin of the ultrasonic sensor
const int servoPin = 9;     // Servo signal pin

Servo myServo;              // Create servo object

void setup() {
  Serial.begin(9600);       // Initialize serial communication

  pinMode(trigPin, OUTPUT); // Set trig pin as output
  pinMode(echoPin, INPUT);  // Set echo pin as input
  
  myServo.attach(servoPin); // Attach the servo to the pin
  myServo.write(0);         // Set initial position of the servo
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  int distance = duration * 0.0343 / 2;

  // Display the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control the servo based on distance
  if (distance > 0 && distance < 15) {   // If an object is within 20 cm
    for (int angle = 0; angle <= 180; angle += 90) { // Spin the servo back and forth
      myServo.write(angle);
      delay(100);
    }
    for (int angle = 180; angle >= 0; angle -= 90) {
      myServo.write(angle);
      delay(100);
    }
  } else {
    myServo.write(0);         // Set the servo to a default position if nothing is detected
  }

  delay(1000);  // Delay before the next reading
}
