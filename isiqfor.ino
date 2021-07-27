int qirmiziled = 2; 
int sariled = 3;
int yasilled = 4;


void setup() {
  pinMode(qirmiziled, OUTPUT);
  pinMode(sariled, OUTPUT);
  pinMode(yasilled, OUTPUT);
}

void loop() {

   digitalWrite(qirmiziled, HIGH);
   delay(5000);
   digitalWrite(sariled, HIGH);
   delay(2500);
   digitalWrite(qirmiziled, LOW);
   delay(10);
   digitalWrite(sariled, LOW);
   delay(10);
   
   digitalWrite(yasilled, HIGH);
   delay(5000);
   digitalWrite(yasilled, LOW);
   delay(10);
   
}
