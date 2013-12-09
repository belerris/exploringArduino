const int red = 9;
const int blue = 8;
void setup(){
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    for(int i=0;i<=255; i++){
      analogWrite(red, i);
      analogWrite(red, 256-i);
      Serial.println(256-i);
      delay(10);
    }
    for(int i=255;i>=0; i--){
      analogWrite(red, i);
      analogWrite(blue,256-i);
      Serial.println(256-i);
      delay(10);
    }
}
