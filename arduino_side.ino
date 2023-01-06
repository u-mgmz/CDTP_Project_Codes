#include <SoftwareSerial.h>
SoftwareSerial HC06(0,1); //TX pin to 10, RX to 11
// Motor A connections
int enA = 10;
int in1 = 2;
int in2 = 3;
// Motor B connections
int enB = 9;
int in3 = 4;
int in4 = 5;

int LED = 13;

void setup() {
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);

  HC06.begin(9600);

}

void loop() {

  char readedData;


  if (HC06.available() > 0) {
    readedData=HC06.read();

    

    if(readedData=='1'){ //İLERİ, ASCII 1
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 120);//açı ayarlamak icin
      analogWrite(enB, 120);

        };
    if(readedData=='2'){//GERİ 2
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enA, 120);//açı ayarlamak icin(deneme yanılma degisitir)
      analogWrite(enB, 120);

        };
    if(readedData=='3'){//SOL 3
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 180);//açı ayarlamak icin
      analogWrite(enB, 120);
       delay(200);
      analogWrite(enA, 0);//dönüşü durdur
      analogWrite(enB, 0);
      
      };
    if(readedData=='4'){//SAG 4 //49
      digitalWrite(13, HIGH);
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 120);//açı ayarlamak icin
      analogWrite(enB, 180);
      delay(200);
      analogWrite(enA, 0);//dönüşü durdur
      analogWrite(enB, 0);
      

        };
       if(readedData=='5'){//dur 5
     
      analogWrite(enA, 0);
      analogWrite(enB, 0);
      
        };
        digitalWrite(13, LOW);
  }
}