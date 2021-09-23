#define LED0 RED_LED  
#define LED1 GREEN_LED
const int buttonPin1 = PUSH1;     // numero de pin de pushbutton 
const int buttonPin2 = PUSH2;     // numero de pin de pushbutton 

int J1_1 = 3;
int J1_2 = 4;
int J1_3 = 5;
int J1_4 = 6;
int J1_5 = 7;
int J1_6 = 8;
int J1_7 = 9;
int J1_8 = 10;

int J2_1 = 2;
int J2_2 = 23;
int J2_3 = 24;
int J2_4 = 25;
int J2_5 = 26;
int J2_6 = 27;
int J2_7 = 28;
int J2_8 = 29;

// variables will change:
int buttonState1 = 0;         // variable para leer el estado del boton 1
int buttonState2 = 0;         // variable para leer el estado del boton 2
int presionado = 0;
int carrera = 0;
int contador1 = 0;
int contador2 = 0;
int flag1 = 0;
int flag2 = 0;
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);  
  pinMode(buttonPin1, INPUT_PULLUP); 
  pinMode(buttonPin2, INPUT_PULLUP); 

  pinMode(J1_1, OUTPUT);
  pinMode(J1_2, OUTPUT);
  pinMode(J1_3, OUTPUT);
  pinMode(J1_4, OUTPUT);
  pinMode(J1_5, OUTPUT);
  pinMode(J1_6, OUTPUT);
  pinMode(J1_7, OUTPUT);
  pinMode(J1_8, OUTPUT);

  pinMode(J2_1, OUTPUT);
  pinMode(J2_2, OUTPUT);
  pinMode(J2_3, OUTPUT);
  pinMode(J2_4, OUTPUT);
  pinMode(J2_5, OUTPUT);
  pinMode(J2_6, OUTPUT);
  pinMode(J2_7, OUTPUT);
  pinMode(J2_8, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  
  if (carrera == 0){
//    if (buttonState1 == LOW or buttonState2 == LOW){
//      presionado = 1; //vairable cambia de valor
//    }
      if (buttonState1 == LOW or buttonState2 == LOW){ //este es el antirebote
      digitalWrite(LED0, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000);               // wait for a second
      digitalWrite(LED1, HIGH);    // turn the LED off by making the voltage LOW
      delay(1000);               // wait for a second
      digitalWrite(LED0, LOW);   //wakit for a second
      delay(1000);
      digitalWrite(LED1, LOW);  //se apaga el led verde
      presionado = 0;
      carrera = 1;   
    }
    else {
      digitalWrite(LED0, LOW);   //se apaga el RGB
      digitalWrite(LED1, LOW);   
      
      digitalWrite(J1_1, LOW);
      digitalWrite(J1_2, LOW);
      digitalWrite(J1_3, LOW);
      digitalWrite(J1_4, LOW);
      digitalWrite(J1_5, LOW);
      digitalWrite(J1_6, LOW);
      digitalWrite(J1_7, LOW);
      digitalWrite(J1_8, LOW);

      digitalWrite(J2_1, LOW);
      digitalWrite(J2_2, LOW);
      digitalWrite(J2_3, LOW);
      digitalWrite(J2_4, LOW);
      digitalWrite(J2_5, LOW);
      digitalWrite(J2_6, LOW);
      digitalWrite(J2_7, LOW);
      digitalWrite(J2_8, LOW);

      contador1 = 0;
      contador2 = 0;
    }
  }

  else {
    if (buttonState1 == LOW){
      flag1 = 1;
    }
    if (buttonState2 == LOW){
      flag2 = 1;
    }
   
    if (buttonState1 == HIGH&&flag1 == 1){
      contador1++;
      flag1 = 0;
      
    }
    if (buttonState2 == HIGH&&flag2 == 1){
      contador2++;
      flag2 = 0;
    }
    switch (contador1) {
      case 1: 
        digitalWrite(J1_1, HIGH); 
        break;
      case 2:
        digitalWrite(J1_1, LOW);
        digitalWrite(J1_2, HIGH); 
        break;
      case 3:
        digitalWrite(J1_2, LOW);
        digitalWrite(J1_3, HIGH); 
        break;
      case 4:
        digitalWrite(J1_3, LOW);
        digitalWrite(J1_4, HIGH); 
        break;
      case 5:
        digitalWrite(J1_4, LOW);
        digitalWrite(J1_5, HIGH); 
        break;
      case 6:
        digitalWrite(J1_5, LOW);
        digitalWrite(J1_6, HIGH); 
        break;
      case 7:
        digitalWrite(J1_6, LOW);
        digitalWrite(J1_7, HIGH); 
        break;
      case 8:
        digitalWrite(J1_7, LOW);
        digitalWrite(J1_8, HIGH);
        contador1 = contador1 + 1; 
        break;
      case 9:
        digitalWrite(J1_8, LOW);
        digitalWrite(LED0, HIGH); 
        carrera = 0;
        contador1 = 0;
        delay(1000);
        break;
    }

    switch (contador2) {
      case 1: 
        digitalWrite(J2_1, HIGH); 
        break;
      case 2:
        digitalWrite(J2_1, LOW);
        digitalWrite(J2_2, HIGH); 
        break;
      case 3:
        digitalWrite(J2_2, LOW);
        digitalWrite(J2_3, HIGH); 
        break;
      case 4:
        digitalWrite(J2_3, LOW);
        digitalWrite(J2_4, HIGH); 
        break;
      case 5:
        digitalWrite(J2_4, LOW);
        digitalWrite(J2_5, HIGH); 
        break;
      case 6:
        digitalWrite(J2_5, LOW);
        digitalWrite(J2_6, HIGH); 
        break;
      case 7:
        digitalWrite(J2_6, LOW);
        digitalWrite(J2_7, HIGH); 
        break;
      case 8:
        digitalWrite(J2_7, LOW);
        digitalWrite(J2_8, HIGH);
        contador2 = contador2 + 1; 
        break;
      case 9:
        digitalWrite(J2_8, LOW);
        digitalWrite(LED1, HIGH); 
        carrera = 0;
        contador2 = 0;
        delay(1000);
        break;
    }        
  }
}
