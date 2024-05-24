#include <Stepper.h>

const int stepsPerRevolution = 200;  // Sesuaikan dengan jumlah langkah per putaran motor Anda
const int sensorPin = 6;  // Pin untuk sensor magnet
const int stepDelay = 0;  // Delay antar langkah dalam milidetik

// Inisialisasi library stepper pada pin 8 hingga 11
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // Start the serial communication
  myStepper.setSpeed(80);
  // Inisialisasi port serial
  Serial.begin(9600);
  // Inisialisasi sensor pin sebagai input
  pinMode(sensorPin, INPUT);  // Initialize serial communication at a baud rate of 9600
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the incoming byte:
    int incomingByte = Serial.read();
    
    // Check if the incoming data is equal to 1
    if (incomingByte == '1') { // assuming '1' is sent as ASCII character
      // Perform the action when data equals 1
      myStepper.step(-200);
      // Add your action here
    }
  
    while(digitalRead(sensorPin)){
      myStepper.step(-1);
    }
  
  }



}
