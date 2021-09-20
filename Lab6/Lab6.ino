
//Lab 6 TIVA C 
// Josue Salazar 
// Digital 2


const int buttonPin = PUSH2;     // the number of the pushbutton pin
const int led1 =  GREEN_LED;      // the number of the LED pin
const int led3 =  BLUE_LED;
const int led2 =  RED_LED;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int contador = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);          
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);     
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {     
    // turn LED on:    
    Serial.begin(4800);
    Serial.println(contador++);
    delay(1000);
    digitalWrite(led2, HIGH);
    digitalWrite(led1,LOW);
    digitalWrite(led3,LOW);
    delay(1000);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    //digitalWrite(led3,HIGH);
    delay(1000);
    digitalWrite(led2,LOW);
    digitalWrite(led1,HIGH);
    digitalWrite(led3,LOW);
    delay(1000);
      
  } 
  else {
    // turn LED off:
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
  }
}
