int ledler[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int a = 0, b = 11;
void effekt1()
{
  for(int i = 0;i < 12;i++)
  {
    digitalWrite(ledler[i], HIGH);
    delay(500);
  }
  for(int i = 11;i >= 0;i--)
  {
    digitalWrite(ledler[i], LOW);
    delay(500);
  }
}
void effekt2()
{
  for(int i = 11;i >= 0;i--)
  {
    digitalWrite(ledler[i], HIGH);
    delay(500);
  }
  for(int i = 0;i < 12;i++)
  {
    digitalWrite(ledler[i], LOW);
    delay(500);
  }
}
void effekt3()
{
  for(int i = 0;i < 6;i++)
  {
    digitalWrite(ledler[a], HIGH);
    digitalWrite(ledler[b], HIGH);
    delay(500);
    a++;
    b--;
  }
  for(int i = 0;i < 7;i++)
  {
    digitalWrite(ledler[a], LOW);
    digitalWrite(ledler[b], LOW);
    delay(500);
    a--;
    b++;
  }
}
void effekt4()
{
  for(int i = 0;i < 12;i++)
  {
    if(i % 2 != 0)
    {
      digitalWrite(ledler[i], HIGH);
      delay(500);
    }
  }
  for(int i = 0;i < 12;i++)
  {
    if(i % 2 != 0)
    {
      digitalWrite(ledler[i], LOW);
      delay(500);
    }
  }
  for(int i = 0;i < 12;i++)
  {
    if(i % 2 == 0)
    {
      digitalWrite(ledler[i], HIGH);
      delay(500);
    }
  }
  for(int i = 0;i < 12;i++)
  {
    if(i % 2 == 0)
    {
      digitalWrite(ledler[i], LOW);
      delay(500);
    }
  }
}
void goyler()
{
  digitalWrite(ledler[0], HIGH);
  delay(500);
  digitalWrite(ledler[3], HIGH);
  delay(500);
  digitalWrite(ledler[6], HIGH);
  delay(500);
  digitalWrite(ledler[9], HIGH);
  delay(500);
  digitalWrite(ledler[9], LOW);
  delay(500);
  digitalWrite(ledler[6], LOW);
  delay(500);
  digitalWrite(ledler[3], LOW);
  delay(500);
  digitalWrite(ledler[0], LOW);
  delay(500);
}
void yasillar()
{
  digitalWrite(ledler[1], HIGH);
  delay(500);
  digitalWrite(ledler[4], HIGH);
  delay(500);
  digitalWrite(ledler[7], HIGH);
  delay(500);
  digitalWrite(ledler[10], HIGH);
  delay(500);
  digitalWrite(ledler[10], LOW);
  delay(500);
  digitalWrite(ledler[7], LOW);
  delay(500);
  digitalWrite(ledler[4], LOW);
  delay(500);
  digitalWrite(ledler[1], LOW);
  delay(500);
}
void aglar()
{
  digitalWrite(ledler[2], HIGH);
  delay(500);
  digitalWrite(ledler[5], HIGH);
  delay(500);
  digitalWrite(ledler[8], HIGH);
  delay(500);
  digitalWrite(ledler[11], HIGH);
  delay(500);
  digitalWrite(ledler[11], LOW);
  delay(500);
  digitalWrite(ledler[8], LOW);
  delay(500);
  digitalWrite(ledler[5], LOW);
  delay(500);
  digitalWrite(ledler[2], LOW);
  delay(500);
}
void setup()
{
  for(int i = 0;i < 12;i++)
  pinMode(ledler[i], OUTPUT);
}

void loop()
{
  effekt1();
  effekt2();
  effekt3();
  effekt4();
  goyler();
  yasillar();
  aglar();
}
