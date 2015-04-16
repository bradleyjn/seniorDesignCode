// include the SPI library:
#include <SPI.h>


// set pin 10 as the slave select for the digital pot:
const int slaveSelectPin = 10;

void setup() {
  // set the slaveSelectPin as an output:
  pinMode (slaveSelectPin, OUTPUT);
  // initialize SPI:
  SPI.begin(); 
  Serial.begin(9600);
}

void loop() {
  // go through the six channels of the digital pot:
  
  //For 3 DPOTS
  for (int i = 0; i < 256; i++) { 
    // change the resistance on this channel from min to max:
      digitalPotWrite3(i, 0, 0);
      printValues3();
    // wait a second at the top:
    delay(50);
    // change the resistance on this channel from max to min:
  }
   for (int i = 0; i < 256; i++) { 
    // change the resistance on this channel from min to max:
      digitalPotWrite3(0, i, 0);
      printValues3();
    // wait a second at the top:
    delay(50);
    // change the resistance on this channel from max to min:
  }
   for (int i = 0; i < 256; i++) { 
    // change the resistance on this channel from min to max:
      digitalPotWrite3(0, 0, i);
      printValues3();
    // wait a second at the top:
    delay(50);
    // change the resistance on this channel from max to min:
  }
  
  
  /*
  //For one DPOT
for (int i = 0; i < 256; i++) { 
    // change the resistance on this channel from min to max:
      digitalPotWrite1(i);
      Serial.println(analogRead(0));
    // wait a second at the top:
    delay(50);
    // change the resistance on this channel from max to min:
  }
  */
  
  //For 2 DPOTS
  /*
  for (int i = 0; i < 256; i++) { 
    // change the resistance on this channel from min to max:
      digitalPotWrite2(i,0);
      printValues2();
    // wait a second at the top:
    delay(50);
    // change the resistance on this channel from max to min:
  }
    for (int i = 0; i < 256; i++) { 
    // change the resistance on this channel from min to max:
      digitalPotWrite2(0,i);
      printValues2();
    // wait a second at the top:
    delay(50);
    // change the resistance on this channel from max to min:
  }
  */
}

void digitalPotWrite3(int value1, int value2, int value3) {
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin,LOW);
  SPI.transfer(value3);
  SPI.transfer(value2);
  SPI.transfer(value1);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin,HIGH); 
}

void digitalPotWrite1(int value) {
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin,LOW);
  SPI.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin,HIGH); 
}

void digitalPotWrite2(int value1, int value2) {
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin,LOW);
  SPI.transfer(value2);
  SPI.transfer(value1);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin,HIGH); 
}

void printValues3(){
  Serial.print(analogRead(0));
  Serial.print("   ");
  Serial.print(analogRead(1));
  Serial.print("   ");
  Serial.println(analogRead(2)); 
}
void printValues2(){
  Serial.print(analogRead(0));
  Serial.print("   ");
  Serial.println(analogRead(1));
}
