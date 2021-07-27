#include <Servo.h>
Servo motor;
int deyer;
int derece;
void setup() 
{
  motor.attach(3);
}

void loop() 
{
  deyer = analogRead(A0);
  derece = map(deyer, 0, 1000, 0, 180);
  motor.write(derece);
}
