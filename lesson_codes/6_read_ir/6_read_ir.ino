// Define the pins for the IR modules
#define IR_RIGHT 7
#define IR_LEFT 8

void setup() {
  // Set the IR module pins as inputs
  pinMode(IR_RIGHT, INPUT);
  pinMode(IR_LEFT, INPUT);

  // Begin serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the values from the IR modules
  int rightValue = digitalRead(IR_RIGHT);
  int leftValue = digitalRead(IR_LEFT);

  // Print the values to the serial monitor
  Serial.print("Right IR: ");
  Serial.println(rightValue);
  Serial.print("Left IR: ");
  Serial.println(leftValue);

  // Wait a bit for readability
  delay(200);
}
