const int led = 9;

void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  for(int i=50; i<=4000; i=i+500){
    Serial.println(i);
    digitalWrite(led, HIGH);
    delay(i);
    digitalWrite(led, LOW);
    delay(i);
  }
}
