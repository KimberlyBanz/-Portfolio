int sensorValue;
//used in beginning to calibrate
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 3000)  {
      //for 5 seconds, wave hand over to calibrate
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh)  {
      sensorHigh = sensorValue;
    }

    if (sensorValue < sensorLow)    {
      sensorLow = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}
void loop() {
  // after calibration, tells piezo to make sound
sensorValue = analogRead(A0);
//create a new variable called pitch with 4 arguments
int pitch =
    map(sensorValue, sensorLow, sensorHigh, 1000, 3000);
    //arguments are which pin, which variable, and how long
    tone(8, pitch, 20);
    //give time to execute
    delay(10);
}
