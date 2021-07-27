#include <Servo.h>   //servo kitabxana
Servo servo;     
int trigPin = 5;    
int echoPin = 6;   
int servoPin = 7;
int led = 10;
long duration, dist, average;   
long aver[3];   //ededi orta ucun massiv
long a = 0;

void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //qutunun elektrik gelende qapagini baglayir
    delay(100);
    servo.detach(); 
} 

void measure() {  
 digitalWrite(10,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //mesafe
}
void ac()
{
 servo.write(0);
 // acmaq 
 delay(500);
 a = 1; 
}
void bagla()
{
 servo.write(150); //baglamaq   
 delay(1000);
 a = 0; 
}
void loop() { 
  for (int i=0;i<=2;i++) {   //mesafenin ededi ortasi
    measure();               
   aver[i]=dist;            
    delay(10);              
  }
 dist=(aver[0]+aver[1]+aver[2])/3;    

if ( dist<10 ) {
//istediyniz kimi mesafeni qoyursunuz
 servo.attach(servoPin); //servonu enable
 ac(); // qutunu acdi
 servo.detach();  //servonu unable   
 delay(5000);
}
//gozle
servo.attach(servoPin); // servo enable
bagla();   // bagla agzini
servo.detach(); // servonu unable
Serial.print(dist);
}
