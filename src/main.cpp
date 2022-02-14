#include <Arduino.h>
#include <Wire.h>


const int ledPin = 1 ;      //broche de LED
int recieveData = 0 ;       //variable de recevoir de données de uC Master (analog)
int blinkVal = 0;           //variable pour convertir le valeur analog en numerique avec map();


//fonction pour detecter s'il y'a un envoi de données
void receiveEvent(int a){

  recieveData = Wire.read();   //mettre la valeur recue dans la variable recieveData
  
}

//configuration
void setup() {

  
  pinMode(ledPin, OUTPUT);
  Wire.begin(9);                  //adresse de recevoir de données
  Wire.onReceive(receiveEvent);
  
}




void loop() {
  blinkVal = map(recieveData, 0, 1023, 0, 255 );   //convertir la valeur de variable recieveDATE
  analogWrite(ledPin, blinkVal);                   //allumer la led selon blinkVal
}