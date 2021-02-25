int switchState = 0;
//declare this variable to be used in loop
void setup() {
  //tells pins on board what they do, input or output
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  switchState = digitalRead(2);
  //go to pin 2 and see what it's receiving

    if (switchState == LOW) {
      //button is not pressed
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    }

    else {  
      //button is pressed
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);

    delay(250); //wait quarter second
    //toggle the LEDs
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);   //wait another quarter second
      
    }

}//go back to beginning of loop
