const int red = 9;
const int blue = 8;
const int green = 7;
const int button = 12;

void setup(){
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(button, INPUT);
    Serial.begin(9600);
}

void loop(){
      if(digitalRead(button) == HIGH)
      {
        digitalWrite(green, LOW);
        for(int i=0;i<=255; i++)
        {
        analogWrite(red, i);
        analogWrite(red, 256-i);
        delay(10);
        }
      for(int i=255;i>=0; i--)
        {
        analogWrite(red, i);
        analogWrite(blue,256-i);
        delay(10);
        }
      }
      else{
        digitalWrite(green, HIGH);
        digitalWrite(red, LOW);
        digitalWrite(blue, LOW);
      }
  
}
