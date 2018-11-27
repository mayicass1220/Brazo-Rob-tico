#include <EEPROM.h>                     //Libreria de EEPROM usada para guardar los valores en memoria no volatil
#include <Servo.h>                      //libreria para usaar servos
Servo servo1;                           //Declaracion de servo hombro
Servo servo2;                           //Declaracion de servo Codo
Servo servo3;                           //Declaracion de servo Pinza
Servo servo4;                           //Declaracion de servo Base
int input;                              //Declaracion de variable que tomara el dato de java
int mServo1 = 90;                       //Declarfacion de variable para el movimiento de servo1
int mServo2 = 90;                       //Declarfacion de variable para el movimiento de servo2
int mServo3 = 90;                       //Declarfacion de variable para el movimiento de servo3
int mServo4 = 90;                       //Declarfacion de variable para el movimiento de servo4
int eepromEntrada;                      //Declaracion de variable para guardar el valor que tiene la variable input en la EEPROM
int eepromAngulo;                       //Declaracion de variable para guardar el valor que tiene la mServo input en la EEPROM
int boton = 7;                          //Declaracion de variable de boton de paro
int ledServo1 = 4;                      //Declaracion de varaible de led para servo1
int ledServo2 = 5;                      //Declaracion de varaible de led para servo2
int ledServo3 = 6;                      //Declaracion de varaible de led para servo3
int ledServo4 = 7;                      //Declaracion de varaible de led para servo4
int aut = 0;                            //Variable para activar/Desactivar el modo automatico

void setup() {
  pinMode (boton, INPUT);               //Declaracion de que la variable boton sera de entrada
  input = 0;                            //Valor de input para que no realice ni un movimiento
  Serial.begin(9600);                   //Accion para usar el serial
  servo1.attach(10);                    //Asignacion de puerto de uso para el servo1
  servo2.attach(9);                     //Asignacion de puerto de uso para el servo2
  servo3.attach(8);                     //Asignacion de puerto de uso para el servo3
  servo4.attach(11);                    //Asignacion de puerto de uso para el servo4
  pinMode(ledServo1, OUTPUT);           //Declaracion de que la variable ledServo1 sera de salida
  pinMode(ledServo2, OUTPUT);           //Declaracion de que la variable ledServo2 sera de salida
  pinMode(ledServo3, OUTPUT);           //Declaracion de que la variable ledServo3 sera de salida
  pinMode(ledServo4, OUTPUT);           //Declaracion de que la variable ledServo4 sera de salida
}

void loop() {

  eepromEntrada = EEPROM.read(1);       //Lee y signa el valor de la posicion 1 de la EEPROM a eepromEntrada
  eepromAngulo = EEPROM.read(2);        //Lee y signa el valor de la posicion 2 de la EEPROM a eepromAngulo


  //if para detectar si el el angulo del angulo del servo esta en un valor diferente de 0 y 180 con la finalodad si perdio corriente electrica
  //cuando la recupera continue con las acciones solicitadas
  if (eepromAngulo != 0 && eepromAngulo != 180) {
    input = eepromEntrada;              //Asignamos a input el valor de eepromEntrada
    if (input == '0') {                 //if para validar que input es 0

    }

    else if (input == '1') {            //if para validar que input es 1 Accion: Subir hombro
      aut = 0;                          //Variable para desactivar el automatico
      mServo1 = eepromAngulo;           //Asigna el valor de eepromAngulo a mServo1
      arriba(input);                    //Llama al metodo arriba y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '2') {            //if para validar que input es 2 Accion: bajar hombro
      aut = 0;                          //Variable para desactivar el automatico
      mServo1 = eepromAngulo;           //Asigna el valor de eepromAngulo a mServo1
      abajo(input);                     //Llama al metodo abajo y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '3') {            //if para validar que input es 3 Accion: Girar base Izquierda
      aut = 0;                          //Variable para desactivar el automatico
      mServo4 = eepromAngulo;           //Asigna el valor de eepromAngulo a mServo4
      arriba(input);                    //Llama al metodo arriba y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '4') {            //if para validar que input es 4 Accion: Girar base Derecha
      aut = 0;                          //Variable para desactivar el automatico
      mServo4 = eepromAngulo;           //Asigna el valor de eepromAngulo a mServo4
      abajo(input);                     //Llama al metodo abajo y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '5') {            //if para validar que input es 5 Accion: Subir Codo
      aut = 0;                          //Variable para desactivar el automatico
      mServo2 = eepromAngulo;           //Asigna el valor de eepromAngulo a mServo2
      arriba(input);                    //Llama al metodo arriba y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '6') {            //if para validar que input es 6 Accion: bajar Codo
      aut = 0;                          //Variable para desactivar el automatico
      mServo2 = eepromAngulo;           //Asigna el valor de eepromAngulo a mServo2
      abajo(input);                     //Llama al metodo abajo y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '7') {            //if para validar que input es 7 Accion: Abrir pinza
      aut = 0;                          //Variable para desactivar el automatico
      mServo3 = eepromAngulo;           //Asigna el valor de eepromAngulo a mServo3
      arriba(input);                    //Llama al metodo arriba y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '8') {            //if para validar que input es 7 Accion: Cerrar Pinza
      aut = 0;                          //Variable para desactivar el automatico
      mServo3 = eepromAngulo;           //Asigna el valor de eepromAngulo a mServo3
      abajo(input);                     //Llama al metodo abajo y lleva la varaible input para realizar el movimiento del servo correcto
    }
  }
  if (Serial.available() > 0) {         //Veridica si el serial esta conectado
    input = Serial.read();              //Recibe el valor del serial desde java
    if (input == '0') {                 //if para validar que input es 0 y no realizar ninguna accion

    } else if (input == '1') {          //if para validar que input es 1 Accion: Subir hombro
      aut = 0;                          //Variable para desactivar el automatico
      arriba(input);                    //Llama al metodo arriba y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '2') {             //if para validar que input es 2 Accion: Bajar hombro
      aut = 0;                           //Variable para desactivar el automatico
      abajo(input);                      //Llama al metodo abajo y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '3') {             //if para validar que input es 3 Accion: Girar base Izquierda
      aut = 0;                           //Variable para desactivar el automatico
      arriba(input);                     //Llama al metodo arriba y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '4') {             //if para validar que input es 4 Accion: Girar base Derecha
      aut = 0;                           //Variable para desactivar el automatico
      abajo(input);                      //Llama al metodo abajo y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '5') {             //if para validar que input es 5 Accion: Subir Codo
      aut = 0;                           //Variable para desactivar el automatico
      arriba(input);                     //Llama al metodo arriba y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '6') {             //if para validar que input es 6 Accion: Bajar Codo
      aut = 0;                           //Variable para desactivar el automatico
      abajo(input);                      //Llama al metodo abajo y lleva la varaible input para realizar el movimiento del servo correcto
    }

    else if (input == '7') {             //if para validar que input es 7 Accion: Abrir Pinzas
      aut = 0;                           //Variable para desactivar el automatico
      arriba(input);                     //Llama al metodo arriba y lleva la varaible input para realizar el movimiento del servo correcto

    }

    else if (input == '8') {             //if para validar que input es 7 Accion: Cerrar Pinzas
      aut = 0;                           //Variable para desactivar el automatico
      abajo(input);                      //Llama al metodo abajo y lleva la varaible input para realizar el movimiento del servo correcto

    }

    else if (input == '9') {             //if para validar que input es 7 Accion: Secuencia Seleccionada por el usuario
      servo1.write(90);                  //Coloca servo1 en 90 grados
      servo2.write(90);                  //Coloca servo2 en 90 grados
      servo3.write(90);                  //Coloca servo3 en 90 grados
      servo4.write(90);                  //Coloca servo4 en 90 grados
      digitalWrite(ledServo1, HIGH);     //Enciede el led servo1
      digitalWrite(ledServo2, HIGH);     //Enciede el led servo2
      digitalWrite(ledServo3, HIGH);     //Enciede el led servo3
      digitalWrite(ledServo4, HIGH);     //Enciede el led servo4
      delay(100);                        //Espera un tiempo de 100 milisegundos
      digitalWrite(ledServo1, LOW);      //Apaga el led servo1
      digitalWrite(ledServo2, LOW);      //Apaga el led servo2
      digitalWrite(ledServo3, LOW);      //Apaga el led servo3
      digitalWrite(ledServo4, LOW);      //Apaga el led servo4
      aut = 1;                           //Variable para activar el automatico
    }

    delay(2500);                         //Espera un tiempo de 2500 milisegundos para la siguiente instruccion

  } else {                               //Else sino detecta el serial conecatado
    aut = 1;                             //Variable para activar el automatico
    automatico();                        //Llama el metodo automatico
  }
}
void arriba(char entrada) {              //Metodo arriba para mover los servos
  //varaible entrada almacena el valor de input


  if (entrada == '1') {                  //if para validar que input es 1
    if (aut == 1) {                      //if para validar que movimiento automatico esta activado
      for (; mServo1 <= 130; mServo1++) { //for para mover el hombro hacia arriba hasta 130 grados
        servo1.write(mServo1);           //escribe el valor de mServo1 en servo1
        delay(10);                       //Tiempo de espera de 10 milisegundos para hacer el movimineto despacio
        digitalWrite(ledServo1, HIGH);   //Enciede el led servo1
        EEPROM.write(1, entrada);        //guarda el valor de entrada en la posicion 1 de la EEPROM
        EEPROM.write(2, mServo1);        //guarda el valor de mServo1 en la posicion 2 de la EEPROM

        if (boton == 1) {                //if si el boton de emergencia es presionado
          quieto1(mServo1);              //Lama el metodo quieto1 del servo1 y envia el angulo actual en el que se encuentra
        }
      }
    }


    else if (aut == 0) {                 //if para validar que movimiento automatico esta desactivado
      mServo1 += 10;                     //Incrementa la variable 10 grados mas a mServo1
      if (mServo1 <= 130) {              //if para validar maximo movimiento premitido de la articulacion
        servo1.write(mServo1);           //escribe el valor de mServo1 en servo1
        digitalWrite(ledServo1, HIGH);   //Enciede el led servo1
        input = 0;                       //asigna un 0 a la variable input para evitar que se cicle
      }

    }
    digitalWrite(ledServo1, LOW);        //Apaga el led servo1
  }


  if (entrada == '3') {                  //if para validar que input es 3
    if (aut == 1) {                      //if para validar que movimiento automatico esta activado
      for (; mServo4 >= 30; mServo4--) { //for para mover el codo hacia girar izquierda hasta 30 grados
        servo4.write(mServo4);           //escribe el valor de mServo4 en servo4
        delay(10);                       //Tiempo de espera de 10 milisegundos para hacer el movimineto despacio
        digitalWrite(ledServo4, HIGH);   //Enciede el led servo4
        EEPROM.write(1, entrada);        //guarda el valor de entrada en la posicion 1 de la EEPROM
        EEPROM.write(2, mServo4);        //guarda el valor de mServo4 en la posicion 2 de la EEPROM

        if (boton == 1) {                //if si el boton de emergencia es presionado
          quieto4(mServo4);              //Lama el metodo quieto4 del servo4 y envia el angulo actual en el que se encuentra
        }
      }
    }
  }


  else if (aut == 0) {                 //if para validar que movimiento automatico esta desactivado
    mServo4 -= 10;                     //Decrementa la variable 10 grados mas a mServo4
    if (mServo4 >= 30) {              //if para validar maximo movimiento premitido de la articulacion
      servo4.write(mServo4);           //escribe el valor de mServo4 en servo4
      digitalWrite(ledServo4, HIGH);   //Enciede el led servo4
      input = 0;                       //asigna un 0 a la variable input para evitar que se cicle
    }

    digitalWrite(ledServo4, LOW);        //Apaga el led servo4
  }


  if (entrada == '5') {                  //if para validar que input es 5
    if (aut == 1) {                      //if para validar que movimiento automatico esta activado
      for (; mServo2 <= 180; mServo2++) { //for para mover el codo hacia arriba hasta 180 grados
        servo2.write(mServo2);           //escribe el valor de mServo2 en servo2
        delay(10);                       //Tiempo de espera de 10 milisegundos para hacer el movimineto despacio
        digitalWrite(ledServo2, HIGH);   //Enciede el led servo2
        EEPROM.write(1, entrada);        //guarda el valor de entrada en la posicion 1 de la EEPROM
        EEPROM.write(2, mServo2);        //guarda el valor de mServo2 en la posicion 2 de la EEPROM

        if (boton == 1) {                //if si el boton de emergencia es presionado
          quieto2(mServo2);              //Lama el metodo quieto2 del servo2 y envia el angulo actual en el que se encuentra
        }
      }
    }

    else if (aut == 0) {                 //if para validar que movimiento automatico esta desactivado
      mServo2 += 10;                     //Incrementa la variable 10 grados mas a mServo2
      if (mServo2 <= 180) {              //if para validar maximo movimiento premitido de la articulacion
        servo2.write(mServo2);           //escribe el valor de mServo2 en servo2
        digitalWrite(ledServo2, HIGH);   //Enciede el led servo2
        input = 0;                       //asigna un 0 a la variable input para evitar que se cicle
      }
    }
    digitalWrite(ledServo2, LOW);         //Apaga el led servo2
  }


  if (entrada == '7') {                  //if para validar que input es 7
    for (; mServo3 >= 90; mServo3--) {   //for para abrir pinza
      servo3.write(mServo3);             //escribe el valor de mServo3 en servo3
      delay(10);                         //Tiempo de espera de 10 milisegundos para hacer el movimineto despacio
      digitalWrite(ledServo3, HIGH);     //Enciede el led servo3
      EEPROM.write(1, entrada);          //guarda el valor de entrada en la posicion 1 de la EEPROM
      EEPROM.write(2, mServo3);          //guarda el valor de mServo3 en la posicion 2 de la EEPROM

      if (boton == 1) {                  //if si el boton de emergencia es presionado
        quieto3(mServo3);                //Lama el metodo quieto3 del servo3 y envia el angulo actual en el que se encuentra
      }
    }
  }
  digitalWrite(ledServo3, LOW);          //Apaga el led servo3
}

void abajo(char entrada) {             //Metodo abajo para mover los servos
  //varaible entrada almacena el valor de input

  if (entrada == '2') {                  //if para validar que input es 2
    if (aut == 0) {                      //if para validar que movimiento automatico esta activado
      for (; mServo1 >= 60; mServo1--) { //for para mover el hombro hacia arriba hasta 60 grados
        servo1.write(mServo1);           //escribe el valor de mServo1 en servo1
        delay(10);                       //Tiempo de espera de 10 milisegundos para hacer el movimineto despacio
        digitalWrite(ledServo1, HIGH);   //Enciede el led servo1
        EEPROM.write(1, entrada);        //guarda el valor de entrada en la posicion 1 de la EEPROM
        EEPROM.write(2, mServo1);        //guarda el valor de mServo1 en la posicion 2 de la EEPROM

        if (boton == 1) {                //if si el boton de emergencia es presionado
          quieto1(mServo1);              //Lama el metodo quieto1 del servo1 y envia el angulo actual en el que se encuentra
        }
      }
    }
    else if (aut == 0) {                 //if para validar que movimiento automatico esta desactivado
      mServo1 -= 10;                     //Decrementa la variable 10 grados mas a mServo1
      if (mServo1 >= 60) {               //if para validar maximo movimiento premitido de la articulacion
        servo1.write(mServo1);           //escribe el valor de mServo1 en servo1
        digitalWrite(ledServo1, HIGH);   //Enciede el led servo1
        input = 0;                       //asigna un 0 a la variable input para evitar que se cicle
      }
    }
    digitalWrite(ledServo1, LOW);         //Apaga el led servo1
  }


  if (entrada == '4') {                   //if para validar que input es 2
    if (aut == 0) {                       //if para validar que movimiento automatico esta activado
      for (; mServo4 <= 140; mServo4++) { //for para mover el hombro hacia arriba hasta 140 grados
        servo4.write(mServo4);            //escribe el valor de mServo1 en servo4
        delay(10);                        //Tiempo de espera de 10 milisegundos para hacer el movimineto despacio
        digitalWrite(ledServo4, HIGH);    //Enciede el led servo1
        EEPROM.write(1, entrada);         //guarda el valor de entrada en la posicion 1 de la EEPROM
        EEPROM.write(2, mServo4);         //guarda el valor de mServo1 en la posicion 2 de la EEPROM

        if (boton == 1) {                 //if si el boton de emergencia es presionado
          quieto4(mServo4);               //Lama el metodo quieto4 del servo4 y envia el angulo actual en el que se encuentra
        }
      }
    }
    else if (aut == 0) {                 //if para validar que movimiento automatico esta desactivado
      mServo4 += 10;                     //Incrementa la variable 10 grados mas a mServo4
      if (mServo4 <= 140) {
        servo4.write(mServo4);           //escribe el valor de mServo4 en servo4
        digitalWrite(ledServo4, HIGH);   //Enciede el led servo4
        input = 0;                       //asigna un 0 a la variable input para evitar que se cicle
      }
      digitalWrite(ledServo4, LOW);      //Apaga el led servo1
    }
  }

  if (entrada == '6') {                //if para validar que input es 6
    if (aut == 0) {                    //if para validar que movimiento automatico esta activado
      for (; mServo2 >= 70; mServo2--) { //for para mover el hombro hacia arriba hasta 70 grados
        servo2.write(mServo2);         //escribe el valor de mServo1 en servo1
        delay(10);                     //Tiempo de espera de 10 milisegundos para hacer el movimineto despacio
        digitalWrite(ledServo2, HIGH); //Enciede el led servo2
        EEPROM.write(1, entrada);      //guarda el valor de entrada en la posicion 1 de la EEPROM
        EEPROM.write(2, mServo2);

        if (boton == 1) {              //if si el boton de emergencia es presionado
          quieto2(mServo2);            //Lama el metodo quieto2 del servo2 y envia el angulo actual en el que se encuentra
        }
      }
    }
    else if (aut == 0) {                 //if para validar que movimiento automatico esta desactivado
      mServo2 -= 10;                     //Decrementa la variable 10 grados mas a mServo1
      if (mServo2 >= 70) {               //if para validar maximo movimiento premitido de la articulacion
        servo2.write(mServo2);           //escribe el valor de mServo2 en servo2
        digitalWrite(ledServo2, HIGH);   //Enciede el led servo2
        input = 0;                       //asigna un 0 a la variable input para evitar que se cicle
      }
    }
    digitalWrite(ledServo2, LOW);        //Apaga el led servo2
  }
 
 
  if (entrada == '8') {                  //if para validar que input es 8
    for (; mServo3 <= 180; mServo3++) {  //for para mover el hombro hacia arriba hasta 180 grados
      servo3.write(mServo3);             //escribe el valor de mServo3 en servo3
      delay(10);                         //Tiempo de espera de 10 milisegundos para hacer el movimineto despacio
      digitalWrite(ledServo3, HIGH);     //Enciede el led servo3
      EEPROM.write(1, entrada);          //guarda el valor de entrada en la posicion 1 de la EEPROM
      EEPROM.write(2, mServo3);          //guarda el valor de mServo3 en la posicion 2 de la EEPROM
      
      if (boton == 1) {                  //if si el boton de emergencia es presionado
        quieto3(mServo3);               //Lama el metodo quieto1 del servo1 y envia el angulo actual en el que se encuentra
      }
    }
  }
  digitalWrite(ledServo3, LOW);         //Apaga el led servo3
}


void quieto1(int angulo) {             //Metodo quieto1 para cuando presionen boton de emergencia se quede esatico el movimiento en el hombro
  servo1.write(angulo);                //escribe el valor de angulo en servo1
}

void quieto2(int angulo) {             //Metodo quieto2 para cuando presionen boton de emergencia se quede esatico el movimiento en el codo
  servo2.write(angulo);                //escribe el valor de angulo en servo2
}

void quieto3(int angulo) {             //Metodo quieto3 para cuando presionen boton de emergencia se quede esatico el movimiento de la pinza
  servo3.write(angulo);                //escribe el valor de angulo en servo3   
}

void quieto4(int angulo) {             //Metodo quieto3 para cuando presionen boton de emergencia se quede esatico el movimiento de la pinza
  servo4.write(angulo);                //escribe el valor de angulo en servo4
}



void automatico() {                    //Metodo para hacer un movimiento en automatico dicatdo por los programadores
  abajo('4');//izquierda
  delay(2000);
  abajo('2');//abajo hombro
  delay(2000);
  abajo('6');//abajo codo
  delay(2000);
  arriba('7');//abrir pinza
  delay(2000);
  abajo('8');//cierra pinza
  delay(2000);
  arriba('1');//arriba hombro
  delay(2000);
  arriba('5');//arriba codo
  delay(2000);
  arriba('3');//derecha
  delay(2000);
  abajo('2');//abajo hombro
  delay(2000);
  abajo('6');//abajo codo
  delay(2000);
  arriba('7');//abrir pinza
  delay(2000);
  abajo('8');//cierra pinza
  delay(2000);
  arriba('1');//arriba hombro
  delay(2000);
  arriba('5');//arriba codo
}
