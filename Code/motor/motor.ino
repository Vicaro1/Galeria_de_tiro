/*
Programa del motor superior de nuestro mayor proyecto: una galeria de tiro automatizada controlada por arduino y android
Realizado por Víctor Caro Pastor y Alba Navarro Moreno, estudiantes de 1º Bachicherato B en el IES ZOCO
*/

int fc1=10; // el final de carrera 1 esta conectado al pin 10
int fc2=11; // el final de carrera 2 esta conectado al pin 11

int IN3=5; // la salida IN3 del regulador l298n va al pin 7
int IN4=4; // la salida IN4 del regulador l298n va al pin 8

int fc=0; // variable para el cambio de sentido del motor
int estado=0; // variable para guardar el valor del bluetooth

void setup() // cada vez que inicemos la "partida" se ejecutara una vez
{

Serial.begin(9600); // iniciamos la comunicacion serial para el bluetooth y el movil

pinMode(fc1,INPUT); // establecemos fc1 como una ENTRADA
pinMode(fc2,INPUT); // establecemos fc2 como una ENTRADA

pinMode(IN3,OUTPUT); // establecemos IN3 como una SALIDA
pinMode(IN4,OUTPUT); // establecemos IN4 como una SALIDA 
}

void loop() // esto se repetira una y otra vez
{
  
if(Serial.available()>0) // nos aseguramos que el puerto serial esta habilitado y tiene una variable minimo
{
  estado=Serial.read(); // la valor de la variable estado sera la lectura serial  
  }
  
if (estado=='1') // si la variable estado = 1 entonces...
{
  
if(digitalRead(fc1)==HIGH && fc==0) // si el fc1 SI esta pulsado y la variable a 0 
{
digitalWrite(IN3,LOW); // pin IN3 a 0v
digitalWrite(IN4,HIGH); // pin IN4 a 5v
fc=1; // variable fc a 1
}

if(digitalRead(fc1)==HIGH && fc==1) // si el fc1 SI esta pulsado y la variable a 1
{
digitalWrite(IN3,LOW); // pin IN3 a 0v
digitalWrite(IN4,HIGH); // pin IN4 a 5v
}

if(digitalRead(fc1)==LOW && fc==1) // si el fc1 NO esta pulsado y la variable a 1
{
digitalWrite(IN3,LOW); // pin IN3 a 0v
digitalWrite(IN4,HIGH); // pin IN4 a 5v
}

if(digitalRead(fc2)==HIGH && fc==1) // si el fc2 SI esta pulsado y la variable a 1
{
digitalWrite(IN3,HIGH); // pin IN3 a 5v
digitalWrite(IN4,LOW);  // pin IN4 a 0v
fc=0; // variable fc a 0
}

if(digitalRead(fc2)==HIGH && fc==0) // si el fc2 SI esta pulsado y la variable a 0
{
digitalWrite(IN3,HIGH); // pin IN3 a 5v
digitalWrite(IN4,LOW); // pin IN4 a 0v
}

if(digitalRead(fc2)==LOW && fc==0) // si el fc2 NO esta pulsado y la variable a 0
{
digitalWrite(IN3,HIGH); // pin IN3 a 5v
digitalWrite(IN4,LOW); // pin IN4 a 0v
}

}

if (estado=='2') // si la variable estado = 2 entonces...
{
digitalWrite(IN3,LOW); // pin IN3 a 0v
digitalWrite(IN4,LOW); // pin IN4 a 0v
estado = 0; // variable estado = 0 para que no se repita la subrutina
}

}
