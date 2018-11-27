## TECNOLÓGICO NACIONAL DE MÉXICO
### INSTITUTO TECNOLÓGICO DE LEÓN
INGENIERÍA EN SISTEMAS COMPUTACIONALES
#### MATERIA:
Sistemas Programables
#### Brazo Robotico
Realizar un brazo en arduino para la materia de Sistemas Programables. 
#### PRESENTA:
Casillas Manrique Mariela Abigail

González Hernández Ivonne Lizbeth
#### PROFESOR:
Ing. Levy Rojas Carlos Rafael
#### HORARIO:
Martes & Jueves 8:45 - 10-25 am


Este proyecto fue realizado con fines educativos. 

###Introducción

El objetivo de está práctica es realizar un brazo que sea controlado con arduino y un lenguaje de programación, este caso el lenguaje de programación que se estableció el lenguaje de Java. El brazo recibirá una serie de instrucciones, el brazo realizará la secuencia.

###Requisitos

Se necesita una máquina con 2GB en RAM. 
Tenemos que tener instalado el siguiente software NeatBeans, Java y Arduino IDE. 
Tenemos que tener instalada la librería (nombre de la librería) en NeatBeans. 

###Instalación 

El brazo robotico tenía 4 servomotores que controlan cada articulación del mismo. Cada brazo será conectado al arduino de acuerdo al código realizado en arduino. 
Para utilizar en la protoboard necesitamos lo siguiente: 
  Protoboard
  Cables macho-macho 
  Push Button 
  Leds 
En la instalacion en la protoboard colocamos el cable de datos del servomotor en algún punto de la protoboard y desde la proto al pin arduino correspondiente, repetimos este paso con los demás servomotores. 
El boton lo conectamos al pin (número de pin), después conectamos a 5V y GND, respectivamente. 
Conectaremos los 4 leds a la protoboard y conectamos la una parte del led a GND y otra a 5V, repetimos con los demás leds. 
Los leds irán conectados a los pines (7,6,5,4). Esto será  de ayuda para saber cuuál es el servo que se está ejecutando.

###Analisis de pruebas:

Mientras el desarrollo de este software nos encontramos con el problema de mover algún servomotor, la conexión de Java a Arduino. 
Utilizamos la memoria EEPROM y fue un conflicto utilizarla. 

![1 2](https://user-images.githubusercontent.com/43210622/49092687-26e5ad00-f228-11e8-8def-fd3461c69c6b.jpeg)
![2](https://user-images.githubusercontent.com/43210622/49092694-29e09d80-f228-11e8-8871-73a3afda1786.jpeg)
![3](https://user-images.githubusercontent.com/43210622/49092695-29e09d80-f228-11e8-8d4f-be5433ba972e.jpeg)
![4](https://user-images.githubusercontent.com/43210622/49092698-2a793400-f228-11e8-971c-e92fe879eb4d.jpeg)
![5](https://user-images.githubusercontent.com/43210622/49092699-2a793400-f228-11e8-9840-a3a7aeadb4fa.jpeg)
