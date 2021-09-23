
//Lab 6 TIVA C 
// Josue Salazar 
// Digital 2


const int J1 = PUSH2;     // the number of the pushbutton pin
const int J2 = PUSH1;
const int led1 =  GREEN_LED;      // the number of the LED pin
const int led3 =  BLUE_LED;
const int led2 =  RED_LED;

// variables will change:
int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;
int contadorJ1 = 0;
int contadorJ2 = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);          
  // initialize the pushbutton pin as an input:
  pinMode(J1, INPUT_PULLUP);
  pinMode(J2, INPUT_PULLUP);
       
}

void loop(){
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(J1);
  buttonState2 = digitalRead(J2);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState1 == LOW || buttonState2 == LOW) {     
    // turn LED on:    
   // Serial.begin(4800);
    //Serial.println(contador++);
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
  if(buttonState1 = LOW){
    Serial.begin(4800);
    Serial.println(contadorJ1++);
    delay(200);
  }
  switch (buttonState1){
    case 0:
      Serial.println(contadorJ1);
    break;
    case 1:
      Serial.println(contadorJ1);
    break;
     case 2:
      Serial.println(contadorJ1);
    break;
     case 3:
      Serial.println(contadorJ1);
    break;
    case 4:
      Serial.println(contadorJ1);
    break;
    case 5:
      Serial.println(contadorJ1);
    break;
    case 6:
      Serial.println(contadorJ1);
    break;
    case 7:
      Serial.println(contadorJ1);
    break;
    case 8:
      Serial.println(contadorJ1);
      delay(1000);
      digitalWrite(led1,HIGH);
      delay(1000);
    break;
  }
  if(buttonState2 = LOW){
    Serial.begin(4800);
    Serial.println(contadorJ2++);
    delay(200);
  }
  switch (buttonState2){
    case 0:
      Serial.println(contadorJ2);
    break;
    case 1:
      Serial.println(contadorJ2);
    break;
     case 2:
      Serial.println(contadorJ2);
    break;
     case 3:
      Serial.println(contadorJ2);
    break;
    case 4:
      Serial.println(contadorJ2);
    break;
    case 5:
      Serial.println(contadorJ2);
    break;
    case 6:
      Serial.println(contadorJ2);
    break;
    case 7:
      Serial.println(contadorJ2);
    break;
    case 8:
      Serial.println(contadorJ2);
      delay(1000);
      digitalWrite(led1,LOW);
      digitalWrite(led3,HIGH);
      delay(1000);
    break;
  }
}
