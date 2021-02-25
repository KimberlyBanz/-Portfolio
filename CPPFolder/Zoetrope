const int controlPin1 = 2;
const int controlPin2 =3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;

//create previous states to be able to compare
int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

//keep track of which direction and speed
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  // set direction of output and input pin
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  digitalWrite(enablePin, LOW);
}

void loop() {
  // read the state and store it in variable
  onOffSwitchState =
      digitalRead(onOffSwitchStateSwitchPin);
  delay(1);

  directionSwitchState = 
      digitalRead(directionSwitchPin);
      //turn the knob on pot
  motorSpeed =analogRead(potPin)/4;

  if(onOffSwitchState != previousOnOffSwitchState)  {

      if(onOffSwitchState ==HIGH) {
        motorEnabled = !motorEnabled;
      }
  }

//check to see if the direction switch has changed, if so, change motor
  if (directionSwitchState !=
        previousDirectionSwitchState) {
            if (directionSwitchState == HIGH) {
              motorDirection = !motorDirection;
            }
        }

  if (motorDirection == 1) {

    digitalWrite(controlPin1, HIGH);
  }

  if(onOffSwitchState != previousOnOffSwitchState) {
      if(onOffSwitchState == HIGH) {
        motorEnabled = !motorEnabled;
      }
  }

if (directionSwitchState !=
      previousDirectionSwitchState) {
        if (directionSwitchState == HIGH) {
          motorDirection = !motorDirection;
        }
      }

if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
}

else {
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
      }
//next part is pulse width modulation
if (motorEnabled == 1)  {
      analogWrite(enablePin, motorSpeed);
}

else {

      analogWrite(enablePin, 0);
}

previousDirectionSwitchState =
      directionSwitchState;

previousOnOffSwitchState = onOffSwitchState;

}
