const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;
const int tempPin = A0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(tempPin);
  float voltage = reading * (5.0 / 1024.0);
  float tempC = (voltage - 0.5) * 100;
  
  Serial.print("Temp: ");
  Serial.println(tempC);

  if (tempC < 20) {
    setColor(0, 0, 255); 
  } 
  else if (tempC >= 20 && tempC <= 30) {
    setColor(0, 255, 0); 
  } 
  else {
    setColor(255, 0, 0); 
  }

  delay(500);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}