  
//Autoreverser 1.0 (2020-12-25)
// Created by | InvertLogic (https://www.youtube.com/c/InvertLogic)
// DCC Isolated Autoreversing Loop Circuit for Model railway
// A0 pin connected to the out pin of the ACS712 current sensor
//D8 pin connected to the base of the NPN transister. connect in series 10k ohm resistor.


#define acs712 A0 // define the analog input pin
#define Trigger_Pin 8 // pin connected to NPN transitor 

float vpp = 0.0048828125; // measure voltage on your arduino and divide it with 1024 to get this value
float sensitivity = 0.185;  //sensetivity of in mv

void setup() {
  // put your setup code here, to run once:
  pinMode(acs712, INPUT);
  pinMode(Trigger_Pin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
int counts = analogRead(acs712)+5; // read analog signal from current sensor
float voltage = counts * vpp; 
voltage -= 2.5; // remove offset

float ampere = voltage / sensitivity; // divide by sensor sensetivity 
  
  Serial.println("Amps: " + String (ampere)); 

if (ampere > 1.0){ 

digitalWrite(Trigger_Pin, !digitalRead(Trigger_Pin)); // toggle output
delay(500); // wait to avoid false triggers
  }
 }
