const int RLED=9;
const int GLED=10;
const int BLED=11;
const int TEMP = 0;

const int LOWER_BOUND=139;
const int UPPER_BOUND=147;

float temp_in_celsius = 0, temp_in_kelvin=0;
int val = 0;

void setup(){
    pinMode(BLED, OUTPUT);
    pinMode(RLED, OUTPUT);
    pinMode(GLED, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    val = analogRead(TEMP);
    delay(5);
    //Reads the input and converts it to Kelvin degrees
  temp_in_kelvin = analogRead(0) * 0.004882812 * 100;
  
  //Converts Kelvin to Celsius minus 2.5 degrees error
  temp_in_celsius = temp_in_kelvin - 2.5 - 273.15; 
  Serial.println(temp_in_celsius);

    if(val<LOWER_BOUND){
	digitalWrite(RLED, LOW);
	digitalWrite(GLED, LOW);
	digitalWrite(BLED, HIGH);
    }
    else if(val>UPPER_BOUND){
	digitalWrite(RLED, HIGH);
	digitalWrite(GLED, LOW);
	digitalWrite(BLED, LOW);
    }
    else{
	digitalWrite(RLED, LOW);
	digitalWrite(GLED, HIGH);
	digitalWrite(BLED, LOW);
    }


}
