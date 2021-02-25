const int sensorPin = A0;
const float baselineTemp = 26.0;

//create constants to be used

void setup() {
  Serial.begin(9600); //open a serial port

//n.b. automates some of the writing
for(int pinNumber = 2; pinNumber<5; pinNumber++){
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
        //the three prong temp guage
  Serial.print("Sensor Value:    ");
  Serial.print(sensorVal);

  //convert the Analog to Digital Converter reading to voltage
  float voltage = (sensorVal/1024.0)* 5.0;

  Serial.print(", Volts:  ");
  Serial.print(voltage);
  Serial.print(", degrees C:  ");
  //this converts voltage to room temperature, obtained from datasheet
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  if(temperature < baselineTemp + 2){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+2 &&
    temperature < baselineTemp + 3) {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      }
   else if(temperature >= baselineTemp+4 &&
    temperature < baselineTemp+6) {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      }
  else if(temperature >= baselineTemp + 5){

      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
  }
//code above makes another LED light up for every 2 degrees
    delay(2000); //makes it less erratic

  }
