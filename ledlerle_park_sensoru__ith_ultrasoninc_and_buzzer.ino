#define echoPin 6
#define trigPin 7
#define buzzerPin 8
#define qirmiziled 11
#define sariled 12
#define yasilled 13  



int maximumRange = 60;
int minimumRange = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(qirmiziled, OUTPUT);
  pinMode(sariled, OUTPUT);
  pinMode(yasilled, OUTPUT);
}


void loop()
{
  int olcum = mesafe(maximumRange, minimumRange);
  melodi(olcum*10);
}


int mesafe(int maxRange, int minRange)
{
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);


  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;

  if(distance >= 0 && distance < 10)
  {
    digitalWrite(yasilled, HIGH);
    digitalWrite(sariled, HIGH);
    digitalWrite(qirmiziled, HIGH);
  }
  if(distance >= 10 && distance < 30)
  {
    digitalWrite(sariled, HIGH);
    digitalWrite(yasilled, HIGH);
    digitalWrite(qirmiziled, LOW);
  }
  if(distance >= 30 && distance <= 60)
  {
    digitalWrite(yasilled, HIGH);
    digitalWrite(sariled, LOW);
    digitalWrite(qirmiziled, LOW);
  }
  if(distance > 60)
  {
    digitalWrite(yasilled, LOW);
    digitalWrite(sariled, LOW);
    digitalWrite(qirmiziled, LOW);
  }
  if(distance >= maxRange)
  return 0;
  return distance;
   
}

int melodi(int dly)
{
  tone(buzzerPin, 440);
  delay(dly);
  noTone(buzzerPin);
  delay(dly);
}
