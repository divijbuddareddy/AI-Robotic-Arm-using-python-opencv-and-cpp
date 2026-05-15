// Arduino code for receiving color detection signals from Python OpenCV script

const int redPin = 9;    // LED pin for red ball (signal A)
const int greenPin = 10; // LED pin for green ball (signal C)
const int bluePin = 11;  // LED pin for blue ball (signal B)

void setup() {
  Serial.begin(9600);  // Match baud rate with Python script
  
  // Set LED pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  // Initialize all LEDs to OFF
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  
  Serial.println("Arduino ready to receive color signals");
}

void loop() {
  if (Serial.available() > 0) {
    char signal = Serial.read();  // Read single character: 'A', 'B', or 'C'
    
    // Turn off all LEDs first
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    
    // Light up corresponding LED based on signal
    if (signal == 'A') {
      digitalWrite(redPin, HIGH);   // Red ball detected
      Serial.println("Red ball detected");
    } 
    else if (signal == 'B') {
      digitalWrite(bluePin, HIGH);  // Blue ball detected
      Serial.println("Blue ball detected");
    } 
    else if (signal == 'C') {
      digitalWrite(greenPin, HIGH); // Green ball detected
      Serial.println("Green ball detected");
    }
    
    delay(100);  // Small delay for stability
  }
}
