/** Encabezado:
 * @file servos.ino
 * @brief Programa de los servos de la galeria de tiro automatizada controlada por arduino y android
 * @author [Victor Caro Pastor](https://github.com/Vicaro1)
 * @version  V2.1
 * @date  07-07-2016
*/
#include <Servo.h> // libreria para los servos 

int angulo1=0; // variable para guardar el valor del angulo1 del servo
int angulo2=0; // variable para guardar el valor del angulo2 del servo
int estado=0;  // variable para guardar el valor del bluetooth
int lado = 0;  // variable para guardar el valor del lado
int x=0;       // variable para guardar los grados de los servos

Servo servo1; // apodo para el servo 1
Servo servo2; // apodo para el servo 2

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETUP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Esto lo hara al comienzo de cada "partida" solo una vez
void setup() 
{
 Serial.begin(9600); // iniciamos la comunicacion serial para el bluetooth y el movil
 servo1.attach(9);   // indicamos el pin PWM del servo 1
 servo2.attach(10);  // indicamos el pin PWM del servo 2
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOOP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// lo que repetira una y otra vez
void loop() 
{
 if(Serial.available()>0) // nos aseguramos que el puerto serial esta habilitado y tiene una variable minimo
 {
 estado=Serial.read(); // la valor de la variable estado sera la lectura serial  
 }
  
 if(estado=='1') // si estado igual a 1 (encender) entonces...
 {
   if (lado ==0)
   {
    for (x=0; x<180; x+=4) // para un angulo igual a 40º y menor a 180º, suma 5º
    {
     angulo1 = map (x, 0, 180, 150, 60); // equivalencias para el servo y los angulos
     angulo2 = map (x, 0, 180, 55, 155); // equivalencias para el servo y los angulos
     servo1.write(angulo1);  // posicionamos el servo1 
     servo2.write(angulo2);  // posicionamos el servo2      
     delay(100);
    }
    lado = 1;
   }
   if (lado ==1)
   {
    for (x=0; x<180; x+=4) // para un angulo igual a 40º y menor a 180º, suma 5º
    {
     angulo2 = map (x, 0, 180, 150, 60); // equivalencias para el servo y los angulos
     angulo1 = map (x, 0, 180, 55, 155); // equivalencias para el servo y los angulos
     servo1.write(angulo1);  // posicionamos el servo1 
     servo2.write(angulo2);  // posicionamos el servo2             
     delay(100);
    }
    lado = 0;
  }
}
 if(estado=='2') // si estado igual a 2 (apagar) entonces...
 {  
  angulo1 = 98;
  angulo2 = 100;
  servo1.write(angulo1);  // posicionamos el servo1 
  servo2.write(angulo2);  // posicionamos el servo2           
  delay(100);  
 }
}
