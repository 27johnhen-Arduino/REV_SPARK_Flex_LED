/* notes:
255 = 0% brightness
0 = 100% brightness
red only goes from 127 to 0 (only from 50 to 100% brightness); 255-128 = 0% brightness

board: "Generic STM32G4 series"
part number: 473VEHx
upload method: STM32CubeProgrammer (DFU)

board does need to be in DFU mode (pressed button) when uploading
*/

const int red = 53;
const int green = 54;
const int blue = 55;
int i;
int d = 10;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  Serial.begin(9600);
  start();
}

void loop() {
}

void start() {
  analogWrite(red, 255);
  for (i = 0; i <= 255; i++) {
    analogWrite(blue, i);
    analogWrite(green, 255 - i);
    delay(d);
  }
  for (i = 0; i <= 255; i++) {
    analogWrite(green, i);
    analogWrite(blue, 255 - i);
    delay(d);
  }
  for (i = 0; i <= 255; i++) {
    analogWrite(blue, i);
    analogWrite(green, 255 - i);
    delay(d);
  }
  for (float j = 1000; j >= 50; j /= 1.3) {
    setGreen();
    delay(j);
    setOrange();
    delay(j);
  }
  for (i = 1; i < 10; i++) {
    for (int k = 1; k < i; k++) {
      analogWrite(red, random(0, 255));      // on
      analogWrite(green, random(0, 255));
      analogWrite(blue, random(0, 255));
      delay(75);
      analogWrite(red, 255);    // off
      analogWrite(green, 255);
      analogWrite(blue, 255);
      delay(75);
    }
    delay (200);
  }
  setOrange();
  delay(100);
  setGreen();
  delay(100);
  setOrange();
  delay(400);
  setGreen();
  delay(100);
  setOrange();
  delay(10000);
  setGreen();
  delay(100);
  setOrange();
  delay(123456);
  setGreen();
  delay(100);
  setOrange();
}

void setGreen() {
  analogWrite(red, 255);
  analogWrite(green, 0);
  analogWrite(blue, 240);
}

void setOrange() {
  analogWrite(red, 0);
  analogWrite(green, 200);
  analogWrite(blue, 255);
}