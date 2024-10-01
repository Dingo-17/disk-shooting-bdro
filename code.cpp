#include <IRremote.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

Servo myservo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int LeftwheelPin1 = 3;
int LeftwheelPin2 = 6;
int RightwheelPin1 = 7;
int RightwheelPin2 = 8;
int IrPin = 12;
int LauncherSpeed = 150;
int EnableLauncher = 5;
int LauncherPin1 = 4;
int LauncherPin2 = 2;
int servoPin = 9;
int angle = 0;
bool keepSpining = false;
unsigned long timer; // stores long numbers
unsigned long currentTime;
int PullBackPin1 = 10;
int PullBackPin2 = 11;

void setup(){
  pinMode(LeftwheelPin1, OUTPUT);
  pinMode(LeftwheelPin2, OUTPUT);
  pinMode(RightwheelPin1, OUTPUT);
  pinMode(RightwheelPin2, OUTPUT);
  pinMode(EnableLauncher, OUTPUT);
  pinMode(LauncherPin1, OUTPUT);
  pinMode(LauncherPin2, OUTPUT);
  pinMode(PullBackPin1, OUTPUT);
  pinMode(PullBackPin2, OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(IrPin, ENABLE_LED_FEEDBACK);
  myservo.attach(servoPin);
  myservo.write(0);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(4,1);
  lcd.print("HELLO WORLD");
}

void loop(){
  if(IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);
    switch(IrReceiver.decodedIRData.decodedRawData){
      case 0xBF40FB04:
        rotateWheel(1,1);
        delay(500);
        rotateWheel(0,0);
        break;
      case 0xBE41FB04:
        rotateWheel(-1,-1);
        delay(500);
        rotateWheel(0,0);
        break;
      case 0xF906FB04:
        rotateWheel(1,-1);
        delay(100);
        rotateWheel(0,0);
        break;
      case 0xF807FB04:
        rotateWheel(-1,1);
        delay(100);
        rotateWheel(0,0);
        break;
      case 0xBB44FB04:
        rotateLauncher(LauncherSpeed);
        timer = millis();
        keepSpining = true;
        break;
      case 0xFD02FB04:
        angle = angle + 20;
        myservo.write(angle);
        break;
      case 0xFC03FB04:
        angle = angle - 20;
        myservo.write(angle);
        break;
      case 0xE11EFB04:
        myservo.write(95);
        delay(1000);
        myservo.write(0);
        break;
      case 0xFE01FB04:
        rotatePullBack(180);
        delay(2000);
        rotatePullBack(0);
        break;
      case 0xEE11FB04:
        LauncherSpeed = 80;
        break;
      case 0xED12FB04:
        LauncherSpeed = 130;
        break;
      
    }

    IrReceiver.resume();
  }

  currentTime = millis();
  if((keepSpining == true) && ((currentTime - timer) >= 2000)){
    rotateLauncher(0);
    keepSpining = false;
    LauncherSpeed = 180;
  }
}

void rotateWheel(int leftWheelDir, int rightWheelDir){
  if (leftWheelDir < 0) {
    digitalWrite(LeftwheelPin1, LOW);
    digitalWrite(LeftwheelPin2, HIGH);    
  } else if (leftWheelDir > 0) {
    digitalWrite(LeftwheelPin1, HIGH);
    digitalWrite(LeftwheelPin2, LOW);      
  } else {
    digitalWrite(LeftwheelPin1, LOW);
    digitalWrite(LeftwheelPin2, LOW);      
  }

  if (rightWheelDir < 0) {
    digitalWrite(RightwheelPin1, LOW);
    digitalWrite(RightwheelPin2, HIGH);    
  } else if (rightWheelDir > 0) {
    digitalWrite(RightwheelPin1, HIGH);
    digitalWrite(RightwheelPin2, LOW);      
  } else {
    digitalWrite(RightwheelPin1, LOW);
    digitalWrite(RightwheelPin2, LOW);      
  }
   
}

void rotateLauncher(int rightMotorSpeed){
  Serial.print("Speed: "); 
  Serial.println(abs(rightMotorSpeed));

  if (rightMotorSpeed < 0) {
    digitalWrite(LauncherPin1, LOW);
    digitalWrite(LauncherPin2, HIGH);    
  } else if (rightMotorSpeed > 0) {
    digitalWrite(LauncherPin1, HIGH);
    digitalWrite(LauncherPin2, LOW);      
  } else {
    digitalWrite(LauncherPin1, LOW);
    digitalWrite(LauncherPin2, LOW);      
  }

  analogWrite(EnableLauncher, abs(rightMotorSpeed));    
}


void rotatePullBack(int leftWheelDir){
  if (leftWheelDir > 0) {
    digitalWrite(PullBackPin1, HIGH);
    digitalWrite(PullBackPin2, LOW);      
  } else {
    digitalWrite(PullBackPin1, LOW);
    digitalWrite(PullBackPin2, LOW);      
  }
}
