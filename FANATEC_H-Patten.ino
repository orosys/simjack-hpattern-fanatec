/*
  DESCRIPTION
  ====================
  SIM JACK H-Pattern Shifter Interface for FANATEC Wheelbase
    Pin 1 - Ground
    Pin 2 - Select H-Pattern/Sequential
    Pin 3 - Detect Shifter
    Pin 4 - X-Axis - horizontal positioning potentiometer
    Pin 5 - Y-Axis - vertical positioning potentiometer
    Pin 6 - VCC, +3.3V
  ====================
*/

const int gearInput1Pin = A1; // GEAR 1
const int gearInput2Pin = A2; // GEAR 2
const int gearInput3Pin = A3; // GEAR 3
const int gearInput4Pin = A4; // GEAR 4
const int gearInput5Pin = A5; // GEAR 5
const int gearInput6Pin = A6; // GEAR 6
const int gearInputRPin = A0; // GEAR R

const int yOut1 = 2;
const int yOut2 = 3;
const int yOut3 = 4;
const int xOut1 = 5;
const int xOut2 = 6;
const int xOut3 = 7;
const int xOut4 = 8;
const int xOut5 = 9;

int lastGear = -1;

void setup() {
  Serial.begin(115200);
  
  // Gear Input
  pinMode(gearInput1Pin, INPUT);
  pinMode(gearInput2Pin, INPUT);
  pinMode(gearInput3Pin, INPUT);
  pinMode(gearInput4Pin, INPUT);
  pinMode(gearInput5Pin, INPUT);
  pinMode(gearInput6Pin, INPUT);
  pinMode(gearInputRPin, INPUT);

  // Gear Output
  pinMode(yOut1, OUTPUT);
  pinMode(yOut2, OUTPUT);
  pinMode(yOut3, OUTPUT);
  pinMode(xOut1, OUTPUT);
  pinMode(xOut2, OUTPUT);
  pinMode(xOut3, OUTPUT);
  pinMode(xOut4, OUTPUT);
  pinMode(xOut5, OUTPUT);
  
  outGearPosition(-1);
}

void loop() {
  int gear = readGearPosition();
  if (lastGear != gear) {
    lastGear = gear;
    Serial.println(gear);
    outGearPosition(gear);
  }
  delay(10);
}

int readGearPosition() {
  int offset = 100;
  int in = analogRead(gearInput1Pin);
  if (in < offset) { return 1; }
  in = analogRead(gearInput2Pin);
  if (in < offset) { return 2; }
  in = analogRead(gearInput3Pin);
  if (in < offset) { return 3; }
  in = analogRead(gearInput4Pin);
  if (in < offset) { return 4; }
  in = analogRead(gearInput5Pin);
  if (in < offset) { return 5; }
  in = analogRead(gearInput6Pin);
  if (in < offset) { return 6; }
  in = analogRead(gearInputRPin);
  if (in < offset) { return 0; }
  return -1;
}

void outGearPosition(int gear) {
  switch (gear) {
  case 0:
    digitalWrite(yOut1, HIGH);
    digitalWrite(yOut2, LOW);
    digitalWrite(yOut3, LOW);
    digitalWrite(xOut1, HIGH);
    digitalWrite(xOut2, LOW);
    digitalWrite(xOut3, LOW);
    digitalWrite(xOut4, LOW);
    digitalWrite(xOut5, LOW);
    break;
  case 1:
    digitalWrite(yOut1, HIGH);
    digitalWrite(yOut2, LOW);
    digitalWrite(yOut3, LOW);
    digitalWrite(xOut1, LOW);
    digitalWrite(xOut2, HIGH);
    digitalWrite(xOut3, LOW);
    digitalWrite(xOut4, LOW);
    digitalWrite(xOut5, LOW);
    break;
  case 2:
    digitalWrite(yOut1, LOW);
    digitalWrite(yOut2, LOW);
    digitalWrite(yOut3, HIGH);
    digitalWrite(xOut1, LOW);
    digitalWrite(xOut2, HIGH);
    digitalWrite(xOut3, LOW);
    digitalWrite(xOut4, LOW);
    digitalWrite(xOut5, LOW);
    break;
  case 3:
    digitalWrite(yOut1, HIGH);
    digitalWrite(yOut2, LOW);
    digitalWrite(yOut3, LOW);
    digitalWrite(xOut1, LOW);
    digitalWrite(xOut2, LOW);
    digitalWrite(xOut3, HIGH);
    digitalWrite(xOut4, LOW);
    digitalWrite(xOut5, LOW);
    break;
  case 4:
    digitalWrite(yOut1, LOW);
    digitalWrite(yOut2, LOW);
    digitalWrite(yOut3, HIGH);
    digitalWrite(xOut1, LOW);
    digitalWrite(xOut2, LOW);
    digitalWrite(xOut3, HIGH);
    digitalWrite(xOut4, LOW);
    digitalWrite(xOut5, LOW);
    break;
  case 5:
    digitalWrite(yOut1, HIGH);
    digitalWrite(yOut2, LOW);
    digitalWrite(yOut3, LOW);
    digitalWrite(xOut1, LOW);
    digitalWrite(xOut2, LOW);
    digitalWrite(xOut3, LOW);
    digitalWrite(xOut4, HIGH);
    digitalWrite(xOut5, LOW);
    break;
  case 6:
    digitalWrite(yOut1, LOW);
    digitalWrite(yOut2, LOW);
    digitalWrite(yOut3, HIGH);
    digitalWrite(xOut1, LOW);
    digitalWrite(xOut2, LOW);
    digitalWrite(xOut3, LOW);
    digitalWrite(xOut4, HIGH);
    digitalWrite(xOut5, LOW);
    break;
  case 7:
    digitalWrite(yOut1, HIGH);
    digitalWrite(yOut2, LOW);
    digitalWrite(yOut3, LOW);
    digitalWrite(xOut1, LOW);
    digitalWrite(xOut2, LOW);
    digitalWrite(xOut3, LOW);
    digitalWrite(xOut4, LOW);
    digitalWrite(xOut5, HIGH);
    break;
  default:
    digitalWrite(yOut1, LOW);
    digitalWrite(yOut2, HIGH);
    digitalWrite(yOut3, LOW);
    digitalWrite(xOut1, LOW);
    digitalWrite(xOut2, LOW);
    digitalWrite(xOut3, HIGH);
    digitalWrite(xOut4, LOW);
    digitalWrite(xOut5, LOW);
    break;
  }
}
