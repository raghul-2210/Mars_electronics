const int ledPin = 13;
const int buttonPin = 2;

unsigned long startTime;   // When the LED turned on
unsigned long reactionTime; // How long it took you
bool ledIsOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  // INPUT_PULLUP keeps the pin HIGH until the button is pressed
  pinMode(buttonPin, INPUT_PULLUP); 
  
  Serial.println("Reaction Timer Ready! Wait for the LED...");
}

void loop() {
  // Wait a random time between 2 to 6 seconds if LED is off
  if (!ledIsOn) {
    delay(random(2000, 6000)); 
    digitalWrite(ledPin, HIGH);
    startTime = millis(); // Start the "stopwatch"
    ledIsOn = true;
  }

  // Check if button is pressed (LOW because of INPUT_PULLUP)
  if (ledIsOn && digitalRead(buttonPin) == LOW) {
    reactionTime = millis() - startTime; // The Math
    
    digitalWrite(ledPin, LOW);
    Serial.print("Reaction Time: ");
    Serial.print(reactionTime);
    Serial.println(" ms");
    
    ledIsOn = false; // Reset for the next round
    delay(2000);     // Brief pause before next test
    Serial.println("Next round starting soon...");
  }
}