//bu kodda www.temrinler.com dan yararlanılmıştır 
#include <SPI.h>
#include <RF24.h>
#include <Wire.h>
#include <MPU6050.h> //Mpu6050 kütüphanesi 

MPU6050 ivme_sensor; 
int x, y, z; //ivme tanımlama

RF24 radio(7, 8); // CE, CSN
int data[2]; // X ve Y düzlemi için dizi tanımlama

void setup() 
{
Wire.begin();
ivme_sensor.initialize();

radio.begin();
radio.openWritingPipe(1234); //alıcı verici aynı frenkas kanalında olmasına dikkat et

}

void loop() 
{

ivme_sensor.getAcceleration(&x, &y, &z); // ivme ve gyro değerlerini okuma burada açısal ivmeyi buluyor förmülleri kullanmıyoruz çünkü formüller bu kodum (mpu6050 kütüphanesinin) içine gömülü
    
data[0] = map(x, -17000, 17000, -255, 255 ); //X düzleminin verisi (ileri-geri)
data[1] = map(y, -17000, 17000, -255, 255); //Y düzeleminin verisi (sağ-sol)
radio.write(data, sizeof(data));
}
