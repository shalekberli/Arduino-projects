int ledler[6] = {3, 5, 6, 9, 10, 11};


void setup()
{
  for(int i = 0;i < 6;i++)
  pinMode(ledler[i], OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  for(int j = 0;j < 6;j++)
  {
    int brightness = 0;
   for (int i = -90; i < 270; i++) {                         // 360 degrees of an imaginary circle.
    float angle = radians(i);                             // Converts degrees to radians.
    brightness = (255 / 2) + (255 / 2) * sin(angle);      // Generates points on a sign wave.
    analogWrite(ledler[j], brightness); // Sends sine wave information to pin 9.
    Serial.println(brightness);                           // "Serial Monitor" or "Serial Plotter" information.
    delay(15);
     analogWrite(ledler[j], 0); // Sends sine wave information to pin 9.
    
     
    }
  }
  
}
