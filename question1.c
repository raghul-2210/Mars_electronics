// Pin Definitions
const int led1 = 10; // 500ms interval
const int led2 = 11; // 1000ms interval
const int led3 = 12; // 1500ms interval

// Variables to store the last time each LED was updated
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;
unsigned long previousMillis3 = 0;

// Intervals in milliseconds
const long interval1 = 500;
const long interval2 = 1000;
const long interval3 = 1500;

// Current state of each LED
int ledState1 = LOW;
int ledState2 = LOW;
int ledState3 = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  // Capture the current time
  unsigned long currentMillis = millis();

  // Check LED 1 (500ms)
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis; // Save the last time you blinked
    ledState1 = !ledState1;          // Toggle the state
    digitalWrite(led1, ledState1);
  }

  // Check LED 2 (1000ms)
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    ledState2 = !ledState2;
    digitalWrite(led2, ledState2);
  }

  // Check LED 3 (1500ms)
  if (currentMillis - previousMillis3 >= interval3) {
    previousMillis3 = currentMillis;
    ledState3 = !ledState3;
    digitalWrite(led3, ledState3);
  }
}