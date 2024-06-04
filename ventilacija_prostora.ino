const int thermistorPin = A0;  
const int motorPin = 9;        

void setup() {
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int tempValue = analogRead(thermistorPin);

  Serial.print("Vrednost termistorja: ");
  Serial.print(tempValue);

  int motorSpeed = map(tempValue, 545, 580, 0, 255); 
  motorSpeed = constrain(motorSpeed, 60, 255);
  analogWrite(motorPin, motorSpeed);

  delay(100);
}
