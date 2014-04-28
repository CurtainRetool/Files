

int oldReading = 0;
int newReading = 0;
int mstep = 12;
int dir = 13;
int steps = 0;
int pulse = 2;
int spd = 10;

void setup()
{
  analogReference(DEFAULT);
  pinMode(mstep, OUTPUT);
  pinMode(dir, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  newReading = analogRead(0);
  newReading = map(newReading, 0, 1023, 0, 600);
  Serial.println(newReading);

  if(newReading>oldReading)
  {
    steps=newReading-oldReading;
    digitalWrite(dir, LOW);
    for(int i=0; i<steps; i++)
    {
      digitalWrite(12, HIGH);
      delay(pulse);
      digitalWrite(12, LOW);
      delay(spd); 
    }
    oldReading=newReading;
  }
  if(newReading<oldReading)
  {
    steps=oldReading-newReading;
    digitalWrite(dir, HIGH);
    for(int i=0; i<steps; i++)
    {
      digitalWrite(12, HIGH);
      delay(pulse);
      digitalWrite(12, LOW);
      delay(spd); 
    }
    oldReading=newReading;
  }



}


