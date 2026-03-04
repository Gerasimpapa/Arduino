void setup() {
  // put your setup code here, to run once:
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12,HIGH);
  digitalWrite(8,LOW);
  delay(1000);
  digitalWrite(12,LOW);
  digitalWrite(8,HIGH);
  delay(1000);
}
