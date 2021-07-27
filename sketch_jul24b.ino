#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"


MPU6050 accelgyro;
int16_t ax, ay, az;
int16_t gx, gy, gz;

#define LED_PIN 13
bool blinkState = false;


void setup() {
  Serial.begin(9600);
  Serial.println("Initializing I2C devices...");
  Wire.begin();
  accelgyro.initialize();
  Serial.println("Testing device connections...");

  if (accelgyro.testConnection()){
    Serial.println("Mpu6050 connection succesful");
    }

    else {
      Serial.println("MPU6050 connection failed");
      while (1);
      }
      Serial.print("X.Y.Z offset :\t");
      Serial.print(accelgyro.getXAccelOffset());Serial.print("\t");
      Serial.print(accelgyro.getYAccelOffset());Serial.print("\t");
      Serial.print(accelgyro.getZAccelOffset());Serial.print("\n");
      pinMode(LED_PIN, OUTPUT);
      
}

void loop() {
  accelgyro. getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  Serial.print("a/g: \t");
  Serial.print(ax);Serial.print("\t");
  Serial.print(ay);Serial.print("\t");
  Serial.print(az);Serial.print("\t");
  Serial.print(gx);Serial.print("\t\t");
  Serial.print(gy);Serial.print("\t\t");
  Serial.println(gz);
  Serial.print("a/g:\t");
  Serial.print((float)ax / 16384); Serial.print("g\t");
  Serial.print((float)ay / 16384); Serial.print("g\t");
  Serial.print((float)az / 16384); Serial.print("g\t");
  Serial.print((float)gx / 131); Serial.print("d/s  \t");
  Serial.print((float)gy / 131); Serial.print("d/s  \t");
  Serial.print((float)gz / 131); Serial.print("d/s  \n");
  delay(300);
  blinkState = !blinkState;
  digitalWrite(LED_PIN, blinkState);
}
