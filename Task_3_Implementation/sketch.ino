#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const byte SENSOR1 = 2;
const byte SENSOR2 = 3;
const byte BUZZER  = 8;


const float DISTANCE = 10.0;        
const float SPEED_LIMIT = 60.0;    


unsigned long startTime = 0;
unsigned long endTime = 0;

bool measuring = false;
bool finished = false;

void setup() {

  pinMode(SENSOR1, INPUT_PULLUP);
  pinMode(SENSOR2, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  // Welcome 
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(10, 8);
  display.println("SMART");

  display.setCursor(10, 35);
  display.println("SPEED");

  display.display();

  delay(2000);

  showWaitingScreen();
}

void loop() {

  // Sensor 1 
  if (!measuring && digitalRead(SENSOR1) == LOW) {

    delay(30);

    if (digitalRead(SENSOR1) == LOW) {

      measuring = true;
      finished = false;

      startTime = millis();

      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(0,10);
      display.println("Vehicle");

      display.setCursor(0,35);
      display.println("Detected");

      display.display();

      while(digitalRead(SENSOR1)==LOW);

    }

  }

  // Sensor 2 
  if (measuring && !finished && digitalRead(SENSOR2)==LOW) {

    delay(30);

    if(digitalRead(SENSOR2)==LOW){

      endTime = millis();

      measuring = false;
      finished = true;

      while(digitalRead(SENSOR2)==LOW);

      calculateSpeed();

    }

  }

}

void calculateSpeed() {

  float timeSeconds = (endTime - startTime) / 1000.0;

  if(timeSeconds <= 0)
    return;

  float speedMS = DISTANCE / timeSeconds;

  float speedKMH = speedMS * 3.6;

  Serial.print("Speed: ");
  Serial.print(speedKMH,1);
  Serial.println(" km/h");

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Vehicle Speed");

  display.setTextSize(2);
  display.setCursor(0,18);
  display.print(speedKMH,1);
  display.println(" km/h");

  display.setTextSize(1);

  if(speedKMH > SPEED_LIMIT){

    display.setCursor(0,52);
    display.println("STATUS: OVER SPEED");

    tone(BUZZER,1000);

  }

  else{

    display.setCursor(20,52);
    display.println("STATUS: SAFE");

    noTone(BUZZER);

  }

  display.display();

  delay(3000);

  noTone(BUZZER);

  showWaitingScreen();

}

void showWaitingScreen() {

  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(5,5);
  display.println("SMART");

  display.setCursor(5,28);
  display.println("SPEED");

  display.setTextSize(1);
  display.setCursor(10,55);
  display.println("Waiting Vehicle");

  display.display();

}