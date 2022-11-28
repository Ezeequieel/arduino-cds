#include<TimerOne.h>

// -----------------------Circuito de iluminación-----------------------
int LedPin = 9; 
int sensorPin = A5;
int sensorValor = 0; 
// -----------------------Circuito de barrera-----------------------
int estadoFC1=0;
int estadoFC2=0;
bool estado=0;
bool bandera=0;
int contador =0;
//-----------------------Pines-----------------------
int motor=8;
int ledBr = 10;
const int buzzer=2;
int fc2=11;
int fc1=12;

//-----------------------
void llaves (){
  estadoFC1 = digitalRead(fc1);
  estadoFC2 = digitalRead(fc2); 
    
}

void setup() {
  Serial.begin(9600);
  pinMode(LedPin, OUTPUT);
  pinMode(fc1, INPUT);
  pinMode(fc2, INPUT);
  pinMode(motor, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledBr,OUTPUT);
  Timer1.initialize(25000);
  Timer1.attachInterrupt(llaves);
}
void loop() {
//-----------------------Código de BARRERA-----------------------  
  if (estadoFC1 == HIGH) 
  {
    digitalWrite (buzzer,estado);
    digitalWrite (ledBr,estado);
    delay (300); 
    estado = !estado;  //! = negado || Si era LOW (0) pasa a ser HIGH (1)
    contador++;   //contador = contador+1 (Cada vez que se repite contador suma 1 (+1))
    if (contador>=6)
    {
      digitalWrite (motor,HIGH);
      digitalWrite (buzzer,HIGH);
      digitalWrite (ledBr,HIGH); 
      estado = 1;
      contador = 6;
    } 
  }
  if (estadoFC2==1)
  {
    bandera = 1;
    estado=0;
  }
              
  if ((bandera == 1) && (estadoFC2==0)){
      digitalWrite(motor,LOW);
      digitalWrite(buzzer,LOW);
      digitalWrite(ledBr,LOW);
      bandera=0;
      contador=0;
    }
//-----------------------Código para ILUMINACIÒN-----------------------
  sensorValor = analogRead(sensorPin); 

  if (sensorValor > 555)
  {
    digitalWrite(LedPin, LOW);
  }
  else 
  {
    digitalWrite(LedPin, HIGH);
  }
}
