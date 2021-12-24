const int PHOTORESISTOR = A0;
const int R_LED = 9;
const int G_LED = 10;
const int B_LED = 11;
const int LASER = 2;
const int BUZZER = 3;
const int OFF_BUTTON = 4;
const int SET_BUTTON = 5;
bool ON = false;
int lightThreshold = 0;

void setRGB(int red, int green, int blue){
  analogWrite(R_LED, red);
  analogWrite(G_LED, green);
  analogWrite(B_LED, blue);
}

void wait(){
  Serial.println("WAIT");
  // Turn off laser and detection
  digitalWrite(BUZZER, HIGH);
  delay(60);
  digitalWrite(BUZZER, LOW);
  ON = false;
  setRGB(255,255,0);

  // Wait for SET button to be pressed
  while(!ON){
    if(digitalRead(SET_BUTTON) == HIGH){
      ON = true;
      }
    }

  // Turn back on
  delay(100);
  set();
}

void set(){
  Serial.println("SET");
  digitalWrite(BUZZER, HIGH);
  delay(60);
  digitalWrite(BUZZER, LOW);
  delay(60);
  digitalWrite(BUZZER, HIGH);
  delay(60);
  digitalWrite(BUZZER, LOW);
  lightThreshold = analogRead(PHOTORESISTOR)-50;
  setRGB(0,10,0);
  while(digitalRead(SET_BUTTON) == HIGH);
}

void trigger(){
  Serial.println("TRIGGER");
  ON = false;
  setRGB(255,0,0);
  digitalWrite(BUZZER, HIGH);
  bool led_on = true;
  unsigned long currTime = millis();
  unsigned long prevTime = millis();
  digitalWrite(LASER, LOW);
  while (!ON){
    if (digitalRead(SET_BUTTON) == HIGH) ON = true;
    currTime = millis();
    if (currTime-prevTime > 500){
      prevTime = currTime;
      if(led_on){
        setRGB(0,0,0);
        led_on = false;
        digitalWrite(BUZZER, LOW);
      } else {
        setRGB(255,0,0);
        led_on = true;
        digitalWrite(BUZZER, HIGH);
      }
    }
  }
  digitalWrite(LASER, HIGH);
  digitalWrite(BUZZER, LOW);
  delay(100);
  set();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PHOTORESISTOR, INPUT);
  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
  pinMode(LASER, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(OFF_BUTTON, INPUT);
  pinMode(SET_BUTTON, INPUT);
  Serial.println("SETUP");
  digitalWrite(LASER, HIGH);
  wait();
}

void loop() {
  // Check if laser is cut off
  if (analogRead(PHOTORESISTOR) < lightThreshold){
    trigger();
  }
  else if (digitalRead(SET_BUTTON) == HIGH){
    set();
  }
  else if (digitalRead(OFF_BUTTON) == HIGH){
    wait();
  }
}
