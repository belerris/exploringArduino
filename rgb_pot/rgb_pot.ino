const int RLED = 9;
const int GLED = 10;
const int BLED = 11;
const int button = 12;
const int POT = 1;

boolean lastButton = LOW;
boolean currentButton = HIGH;

int ledMode = 0;

void setup(){
  pinMode(RLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

boolean debounce(boolean last){
  boolean current = digitalRead(button);
  if (last != current){
    delay(5);
    current = digitalRead(button);
  }
  return current;
}

void setMode(int mode)
{
  int val = analogRead(POT)/4;
  //RED
  if (mode == 1)
  {
    analogWrite(RLED, val);
    analogWrite(GLED, 0);
    analogWrite(BLED, 0);
  }
  //GREEN
  else if (mode == 2)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, val);
    analogWrite(BLED, 0);
  }
  //BLUE
  else if (mode == 3)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 0);
    analogWrite(BLED, val);
  }
  //PURPLE (RED+BLUE)
  else if (mode == 4)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 0);
    analogWrite(BLED, 127);
  }
  //TEAL (BLUE+GREEN)
  else if (mode == 5)
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  }
  //ORANGE (GREEN+RED)
  else if (mode == 6)
  {
    analogWrite(RLED, 127);
    analogWrite(GLED, 127);
    analogWrite(BLED, 0);
  }
  //WHITE (GREEN+RED+BLUE)
  else if (mode == 7)
  {
    analogWrite(RLED, 85);
    analogWrite(GLED, 85);
    analogWrite(BLED, 85);
  }
  //OFF (mode = 0)
  else
  {
    analogWrite(RLED, 0);
    analogWrite(GLED, 0);
    analogWrite(BLED, 0);
  }
}

void loop()
{
  currentButton = debounce(lastButton);           //read debounced state
  if (lastButton == LOW && currentButton == HIGH) //if it was pressed...
  {
    ledMode++;                                    //increment the LED value
  }
  lastButton = currentButton;                     //reset button value
  Serial.println(lastButton);
  //if you’ve cycled through the different options, reset the counter to 0
  if (ledMode == 8) ledMode = 0;
  setMode(ledMode);                              //change the LED state
}


  

