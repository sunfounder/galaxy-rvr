// Define the pin for the ultrasonic module
#define ULTRASONIC_PIN 10

void setup() {
  // Start the serial communication
  Serial.begin(9600);
}

void loop() {

  // A 4ms delay is required, otherwise the reading may be 0
  delay(4);

  //Set to OUTPUT to send signal
  pinMode(ULTRASONIC_PIN, OUTPUT);

  // Clear the trigger pin
  digitalWrite(ULTRASONIC_PIN, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by sending a high pulse for 10us
  digitalWrite(ULTRASONIC_PIN, HIGH);
  delayMicroseconds(10);

  // Set the trigger pin back to low
  digitalWrite(ULTRASONIC_PIN, LOW);

  //Set to INPUT to read
  pinMode(ULTRASONIC_PIN, INPUT);

  // pulseIn returns the duration of the pulse on the pin
  float duration = pulseIn(ULTRASONIC_PIN, HIGH);

  // Calculate the distance (in cm) based on the speed of sound (340 m/s or 0.034 cm/us)
  float distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("The distance is: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Delay a bit to let the sensor settle before the next measurement
  delay(200);
}
