/*
 *    AUTOR:   Wesley Mar.
 *    LINK:    
 *    COMPRE:  
 *    SKETCH:  Arduino - teste modulo bluetooth
 *    DATA:    29/03/2023
*/


#include <SoftwareSerial.h> // Biblioteca que permite usar outros pinos como porta TR, RX

SoftwareSerial bt_serial1(10, 11); // (RX, TX) - esses são os novos pino 

// definindo portas
int led = 7;
int bip = 5;
int M1 = 4;
int M2 = 3;
int i = 0;


void Leds(){ // Função apra piscar led
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(100);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(100);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(100);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(led,LOW);
  delay(100); 
  }

void Bip() { // Função para buzinar
    digitalWrite(bip, HIGH);
    delay(300);
    digitalWrite(bip, LOW);
    delay(300);
    digitalWrite(bip, HIGH);
    delay(300);
    digitalWrite(bip, LOW);
    delay(300);
     digitalWrite(bip, HIGH);
    delay(300);
    digitalWrite(bip, LOW);
    delay(300);
    digitalWrite(bip, HIGH);
    delay(300);
    digitalWrite(bip, LOW);
    delay(300);
  }

void Frente (){ //Função que vai pra frente
  digitalWrite(M1, HIGH);
  digitalWrite(M2, LOW);
  //analogWrite(MdireitoF4, VelocidadeME - 3);
  }
void Tras (){ //Função que vai pra tras
  digitalWrite(M2, HIGH);
  digitalWrite(M1, LOW);
  //analogWrite(MdireitoT3, VelocidadeME);
  } 
void Para(){ //Função que faz o carro para
  digitalWrite(M2, LOW);
  digitalWrite(M1, LOW);
}  

void setup() { // definindo entradas e saidas
  // put your setup code here, to run once:
pinMode (led, OUTPUT);
pinMode (bip, OUTPUT);
pinMode (M1, OUTPUT);
pinMode (M2, OUTPUT);
bt_serial1.begin(9600); // ativando novas portas seriais
Serial.begin(9600);
}


void loop() { // Loop do codigo
  // put your main code here, to run repeatedly:
  int C = bt_serial1.read(); // um C inteiro recebe a leitura serial

  if(C == 49 ) {digitalWrite(led, HIGH);}
  if (C == 50 ){digitalWrite(led, LOW);}
  if (C == 51 ){
    Bip();
    Para();}
  if (C == 52 ){Leds();}
  if (C == 53 ){Frente();}
  if (C == 54 ){Tras();}

  
  Serial.println(bt_serial1.read()); // monitor serial da leitira
  Serial.println(C); // monitor serial do bluetooth
  delay(100);
}
