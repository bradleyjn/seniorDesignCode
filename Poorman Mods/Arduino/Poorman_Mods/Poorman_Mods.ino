#define ANALOG_IN 5
#define buttonPin 5
#define LEDSinPin 10
#define LEDSqPin 9
#define LEDTriPin 4

int state = 0;
int btnState;
int done = 0;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(LEDSinPin, OUTPUT);
  pinMode(LEDSqPin, OUTPUT);
  pinMode(LEDTriPin, OUTPUT);
  digitalWrite(LEDSinPin, HIGH);
  Serial.begin(115200); 
}

void loop() {
  int val = analogRead(ANALOG_IN);
  Serial.write( 0xff);
  Serial.write( (val >> 2) & 0xff);
  checkButton();
}

void checkButton(){
  btnState = digitalRead(buttonPin);
  if((btnState == 1) && (done == 0)){
     switch(state){
      case 0:
        digitalWrite(LEDSinPin, LOW);
        digitalWrite(LEDSqPin, HIGH);
        digitalWrite(LEDTriPin, LOW);
        state = 1;
      break; 
      case 1:
        digitalWrite(LEDSinPin, LOW);
        digitalWrite(LEDSqPin, LOW);
        digitalWrite(LEDTriPin, HIGH);
        state = 2;
      break; 
      case 2:
        digitalWrite(LEDSinPin, HIGH);
        digitalWrite(LEDSqPin, LOW);
        digitalWrite(LEDTriPin, LOW);
        state = 0;
      break; 
     }
    done = 1;
  }
  if((done == 1) && (btnState == 0)){
   done = 0; 
  }
}
