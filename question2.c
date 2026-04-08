// RGB LED pins
const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

// Normal LED pin
const int ledPin = 13;

// Potentiometer pin
const int potPin = A0;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin); // 0–1023

  // ── RGB colour control ──────────────────────────────────────────────
  // Divide the 0–1023 range into 6 colour zones (~170 steps each)
  // Red→Yellow→Green→Cyan→Blue→Magenta→Red (HSV hue wheel)

  int r, g, b;
  int zone = potValue / 171;       // 0–5
  int step = (potValue % 171) * 255 / 171; // brightness within zone

  switch (zone) {
    case 0: r = 255;        g = step;       b = 0;          break; // Red → Yellow
    case 1: r = 255 - step; g = 255;        b = 0;          break; // Yellow → Green
    case 2: r = 0;          g = 255;        b = step;       break; // Green → Cyan
    case 3: r = 0;          g = 255 - step; b = 255;        break; // Cyan → Blue
    case 4: r = step;       g = 0;          b = 255;        break; // Blue → Magenta
    default:r = 255;        g = 0;          b = 255 - step; break; // Magenta → Red
  }

  analogWrite(redPin,   r);
  analogWrite(greenPin, g);
  analogWrite(bluePin,  b);

  // ── Blink rate control ──────────────────────────────────────────────
  // Map pot → delay: 50 ms (fast) to 1000 ms (slow)
  int blinkDelay = map(potValue, 0, 1023, 50, 1000);

  digitalWrite(ledPin, HIGH);
  delay(blinkDelay);
  digitalWrite(ledPin, LOW);
  delay(blinkDelay);
}