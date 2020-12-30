//bu kodda www.temrinler.com dan yararlanılmıştır
#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

int data[2];// X ve Y düzlemi için dizi tanımlama

int in1 = 5;
int in2 = 6;
int in3 = 9;
int in4 = 10;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
radio.begin();
radio.openReadingPipe(1,1234);
radio.startListening();
}

void loop() {
  if (radio.available()) {
    
radio.read(data, sizeof(data));

    if(data[0] > 50)//sola gider sol göz yanar
    {
      digitalWrite(4, LOW);
      digitalWrite(3, HIGH);
      analogWrite(in1,data[0]);
      analogWrite(in2,0);
      analogWrite(in3,data[0]);
      analogWrite(in4,0);
    }
    if(data[0] < -50)//sağa gider sağ göz yanar
    {
      digitalWrite(4, HIGH);
      digitalWrite(3, LOW);
      analogWrite(in1,0);
      analogWrite(in2,-data[0]);
      analogWrite(in3,0);
      analogWrite(in4,-data[0]);
    }
  
      if(data[1] > 50)//ileriye gider iki gözde yanar
    {
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      analogWrite(in1,0);
      analogWrite(in2,data[1]);
      analogWrite(in3,data[1]);
      analogWrite(in4,0);
    }
      if(data[1] < -50)//geriye gider iki gözde yanar
    {
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      analogWrite(in1,-data[1]);
      analogWrite(in2,0);
      analogWrite(in3,0);
      analogWrite(in4,-data[1]);
    }
    if(data[0] > -50 && data[0] < 50 && data[1] > -50 && data[1] < 50)//durur ve gözler yanıp söner
    {
      digitalWrite(4, HIGH);
      digitalWrite(3, HIGH);
      delay(150);
      digitalWrite(4, LOW);
      digitalWrite(3, LOW);
      delay(150);
      analogWrite(in1,0);
      analogWrite(in2,0);
      analogWrite(in3,0);
      analogWrite(in4,0);
    }
    
  }
}
