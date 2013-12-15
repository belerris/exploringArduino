const int MOTOR = 9;
const int POT = 2;

int val = 0;

void setup(){
    pinMode(MOTOR, OUTPUT);
    Serial.begin(9600);
}

void loop(){

    val = analogRead(POT);
    Serial.println(val);
    delay(1000);
    val = map(val, 0, 1023, 0, 255);
    analogWrite(MOTOR,  val);
    Serial.println(val);
}
