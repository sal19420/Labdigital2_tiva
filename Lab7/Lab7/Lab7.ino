//******librerias************
#include <SPI.h>
#include <SD.h>
//----Variables generales----
File root;
char opcion = '0';
uint8_t control = 0;
char inByte;
//----Prototipos-------
void printDirectory(File dir, int numTabs);
void readText(char dir);

void setup()
{
  // Iniciar comunicacion serial y esperar a que el puerto respoda:
  Serial.begin(115200);
  SPI.setModule(0); //esto indica que puertos se van a usar

  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(PA_3, OUTPUT);

  if (!SD.begin(PA_3)) {
    Serial.println("Falló");
    return;
  }
  Serial.println("Se acabó la inicializacion");

  Serial.println("Listo");
}

void loop()
{
  if (control == 0) {
    root = SD.open("/");
    printDirectory(root, 0);
    Serial.println("Escriba la posicion del archivo que desea ver: ");
    control++; //al aumentar el valor de control se asegura que el mensaje de menu no aparesca hasta que se halla seleccionado
  }             //una opcion.
  if (Serial.available()) {
    inByte = Serial.read();//se guarda el valor enviado por serial
  }
  if (inByte == '1') {//si el valor recibido es un 1
    opcion = '1'; //se coloca un 1 a la opcion 
    control--; //se coloca en 0 control para que se muestre el menu
  }
  if (inByte == '2') {//misma logica que cuando se recibe un 1
    opcion = '2';
    control--;
  }
  if (inByte == '3') {//misma logica que cuando se recibe un 1
    opcion = '3';
    control--;
  }
  readText(opcion);
  opcion = '0'; //se asegura que opcion siempre sea 0 para evitar que se muestre valores no deseados
}

void readText(char dir) {
  uint8_t seleccion;
  File archivo;
  switch (dir) {//Se abre el archivo dependiendo del valor que tenga la variable opcion 
    case '1':
      archivo = SD.open("mario.txt");
      seleccion = 1; //habilita la rutina de mostrar el contenido
      break;
    case '2':
      archivo = SD.open("toad.txt");
      seleccion = 1;
      break;
    case '3':
      archivo = SD.open("ironman.txt");
      seleccion = 1;
      break;
    default:
      seleccion = 0;//inhabilita la rutina de mostrar el contenido
      break;
  }
  if (seleccion == 1) {//rutina que sirve para mostrar la informacion guardada en el archivo seleccionado
    if (archivo) {
      Serial.println(archivo.name());

      // read from the file until there's nothing else in it:
      while (archivo.available()) {
        Serial.write(archivo.read());
      }
      // close the file:
      archivo.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("Error");
    }
  }
}

void printDirectory(File dir, int numTabs) {//en esta rutina se muestra el contenido guardado en la SD
  dir.rewindDirectory();
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}
