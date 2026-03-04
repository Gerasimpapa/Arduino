int potPin = A0;
int potValue = 0;
int LEDPin = 9;

void setup() {
  pinMode(potPin, INPUT);
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  potValue = analogRead(potPin);
  
  // 1. If it's above 1000, snap it to the max
  if (potValue > 1000) {
    potValue = 1023;
  }

  // 2. Shift the range so 30 becomes 0
  // Any value below 30 becomes 0
  float shiftedValue = max(0, potValue - 30);
  
  // 3. Apply the Square Root Transformation
  // We divide by 993.0 (which is 1023 - 30) to keep the scale correct
  int inputVal = sqrt(shiftedValue / 993.0) * 255;

  // Final Clamping (good practice for math stability)
  inputVal = constrain(inputVal, 0, 255);

  // Debugging
  Serial.print("Pot: "); Serial.print(potValue);
  Serial.print(" -> PWM: "); Serial.println(inputVal);

  analogWrite(LEDPin, inputVal);
  
  delay(15); 
}