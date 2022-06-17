#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;

int pos = 0;
int temp = 0;
int datos_in;
int A = 0;
int abrir = 8;
int led = 13;
int val = 0;

void setup() {
 Serial.begin(115200);
 servo1.attach(3);
 servo2.attach(5);
 servo3.attach(6);
 pinMode (abrir, INPUT);
 pinMode (led, OUTPUT);
}

void loop() {
  
  if (Serial.available()>0){
    datos_in = Serial.read();
    Serial.println((char)datos_in);
    if (datos_in == 'T'){
      A = 1 ;
    }else{
      A = 0;
    }
    delay(500);
  }else{
    Serial.write("No data");
    delay(500); 
  }

  if (A == 1){
      servo1.write(pos = 0);
      servo2.write(pos = 0);
      delay(15);
    }else{
      servo1.write(pos = 90);
      servo2.write(pos = 90);
      delay(15);
  }
  
  val = digitalRead(abrir);
  //digitalWrite(led, val);
  if (val == HIGH){
    digitalWrite(led, HIGH);
    servo3.write(pos = 90);
    delay(15);
  }else{
    digitalWrite(led, LOW);
    servo3.write(pos = 0);
    delay(15);
  }

 }
