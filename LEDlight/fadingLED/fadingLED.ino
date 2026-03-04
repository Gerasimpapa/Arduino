int potPin = A0;
int potValue = 0;
int LEDPin = 9;

void setup()
{
  pinMode (potPin, INPUT);
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);

}

void loop()
{
  potValue = analogRead(potPin);
  
  int inputVal = map(potValue, 0, 1023, 0, 255);
  Serial.print(inputVal);
  Serial.print(" ");
  Serial.println(potValue);
  analogWrite(LEDPin, inputVal);


}