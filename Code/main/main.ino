/** Encabezado:
 * @file main.ino
 * @brief Programa principal de la galeria de tiro automatizada controlada por arduino y android
 * @author [Victor Caro Pastor](https://github.com/Vicaro1)
 * @version  V2.1
 * @date  07-07-2016
*/

#include <LiquidCrystal.h> //libreria para la lcd

int estado=0; // variable para guardar el valor del bluetooth

int ldr1=0; //ldr1 (cabeza) asignada al pin analogico A0
int luz1=0; // variable para almacenar el valor de la ldr1
int n1=0; // variable para almacenar los puntos de la ldr1

int ldr2=1; //ldr2 (cabeza) asignada al pin analogico A1
int luz2=0;  // variable para almacenar el valor de la ldr2
int n2=0; // variable para almacenar los puntos de la ldr2

int ldr3=2; //ldr3 (cabeza) asignada al pin analogico A2
int luz3=0;  // variable para almacenar el valor de la ldr3
int n3=0; // variable para almacenar los puntos de la ldr3

int ldr4=3; //ldr4 (corazon) asignada al pin analogico A3
int luz4=0;  // variable para almacenar el valor de la ldr4
int n4=0; // variable para almacenar los puntos de la ldr4

int ldr7=4; //ldr7 (corazon) asignada al pin analogico A4
int luz7=0;  // variable para almacenar el valor de la ldr7
int n7=0; // variable para almacenar los puntos de la ldr7

int ldr6=5; //ldr6 (corazon) asignada al pin analogico A5
int luz6=0;  // variable para almacenar el valor de la ldr6
int n6=0;// variable para almacenar los puntos de la ldr6

int zumbacabeza=13; // apodo para el zumbador de las cabezas, pin digital 13
int zumbacorazon=2; // apodo para el zumbador de los corazones, pin digital 2

LiquidCrystal lcd(7,8,9,10,11,12); // establecemos los pines de la lcd todos ellos pines digitales

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ SETUP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// Esto lo hara al comienzo de cada "partida" solo una vez
void setup() 
{
 Serial.begin(9600); // iniciamos la comunicacion serial para el bluetooth y el movil

 pinMode(ldr1,INPUT); // indicamos que la ldr1 sera una ENTRADA
 pinMode(ldr2,INPUT); // indicamos que la ldr2 sera una ENTRADA
 pinMode(ldr3,INPUT); // indicamos que la ldr3 sera una ENTRADA
 pinMode(ldr4,INPUT); // indicamos que la ldr4 sera una ENTRADA
 pinMode(ldr7,INPUT); // indicamos que la ldr7 sera una ENTRADA
 pinMode(ldr6,INPUT); // indicamos que la ldr6 sera una ENTRADA
 
 pinMode(zumbacabeza,OUTPUT); // señalamos que el zumbacabeza es una SALIDA
 pinMode(zumbacorazon,OUTPUT); // señalamos que el zumbacorazon es una SALIDA
  
 lcd.begin(16,2); // concretamos que usaremos una lcd de 16 bit y 2 filas
 lcd.print("puntuacion"); // escribimos en la lcd: puntuacion
 delay(2000); // esperamos 2 segundos
 lcd.clear(); // borramos la pantalla
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOOP ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
// lo que repetira una y otra vez
void loop() 
{
 int ntotal=n1+n2+n3+n4+n7+n6; // creamos una variable que es la suma de los puntos de las ldrs
 
 lcd.setCursor(2,2); // establecemos la escritura en el segundo bit de la fila 2
 lcd.print(ntotal); // escribimos el total de puntos 
 lcd.print(" puntos"); // escribimos:  puntuacion
 delay(800); // esperamos 0'8 segundos
 lcd.clear(); // borramos la escritura
 
 luz1=analogRead(ldr1); // la variable luz1 tendra el valor de la lectura de la ldr1
 luz2=analogRead(ldr2); // la variable luz2 tendra el valor de la lectura de la ldr2
 luz3=analogRead(ldr3); // la variable luz3 tendra el valor de la lectura de la ldr3
 luz4=analogRead(ldr4); // la variable luz4 tendra el valor de la lectura de la ldr4
 luz7=analogRead(ldr7); // la variable luz7 tendra el valor de la lectura de la ldr7
 luz6=analogRead(ldr6); // la variable luz6 tendra el valor de la lectura de la ldr6

 if(estado=='1') // si estado igual a 1 (encender) entonces...
 {
   
 if(luz1>850 && luz1<1005) // si la luz1 esta entre 850-1005 entonces...
 {
   digitalWrite(zumbacabeza,HIGH); // ponemos en el pin zumbacabeza 5v
   delay(75); // esperamos 0'075 segundos
   digitalWrite(zumbacabeza,LOW); // ponemos en el pin zumbacabeza 0v 
   n1=n1+5; // en la variable n1 sumamos 5
   }
   
 if(luz2>850 && luz2<1005) // si la luz2 esta entre 850-1005 entonces...
 {
   digitalWrite(zumbacabeza,HIGH); // ponemos en el pin zumbacabeza 5v
   delay(75); // esperamos 0'075 segundos
   digitalWrite(zumbacabeza,LOW); // ponemos en el pin zumbacabeza 0v
   n2=n2+5; // en la variable n2 sumamos 5
   }
 
 if(luz3>850 && luz3<1005) // si la luz3 esta entre 850-1005 entonces...
 {
   digitalWrite(zumbacabeza,HIGH); // ponemos en el pin zumbacabeza 5v
   delay(75); // esperamos 0'075 segundos
   digitalWrite(zumbacabeza,LOW); // ponemos en el pin zumbacabeza 0v
   n3=n3+5; // en la variable n3 sumamos 5
   }  
 
 if(luz4>850 && luz4<1010) // si la luz4 esta entre 850-1010 entonces...
 {
   digitalWrite(zumbacorazon,HIGH); // ponemos en el pin zumbacorazon 5v
   delay(75); // esperamos 0'075 segundos
   digitalWrite(zumbacorazon,LOW); // ponemos en el pin zumbacorazon 0v
   n4=n4+10; // en la variable n4 sumamos 10
   }  
   
 if(luz7>850 && luz7<1010) // si la luz7 esta entre 850-1010 entonces...
 {
   digitalWrite(zumbacorazon,HIGH); // ponemos en el pin zumbacorazon 5v
   delay(75); // esperamos 0'075 segundos
   digitalWrite(zumbacorazon,LOW); // ponemos en el pin zumbacorazon 0v
   n7=n7+10; // en la variable n7 sumamos 10
   } 
   
 if(luz6>850 && luz6<1010) // si la luz6 esta entre 850-1010 entonces...
 {
   digitalWrite(zumbacorazon,HIGH); // ponemos en el pin zumbacorazon 5v
   delay(75); // esperamos 0'075 segundos
   digitalWrite(zumbacorazon,LOW); // ponemos en el pin zumbacorazon 0v
   n6=n6+10; // en la variable n6 sumamos 10
   } 
 }
 
 if(Serial.available()>0) // nos aseguramos que el puerto serial esta habilitado y tiene una variable minimo
 {
   estado=Serial.read(); // la valor de la variable estado sera la lectura serial  
   }
 
 if(estado=='3') // si estado igual a 3 (reset) entonces...
 {
   n1=0; // ponemos la variable n1 a 0 
   n2=0; // ponemos la variable n2 a 0 
   n3=0; // ponemos la variable n3 a 0 
   n4=0; // ponemos la variable n4 a 0 
   n7=0; // ponemos la variable n7 a 0 
   n6=0; // ponemos la variable n6 a 0 
   estado=0; // ponemos la variable estado a 0 para que no se repita la subrrutina
   }
}



