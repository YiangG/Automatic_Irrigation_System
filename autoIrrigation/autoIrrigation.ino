#include "Adafruit_seesaw.h"
#include "config.h"

#define CONTROL_PIN D5

Adafruit_seesaw ss;
AdafruitIO_Feed *soil_moisture = io.feed("soil_moisture");
AdafruitIO_Feed *temperature = io.feed("temperature");

int capread = 0;
float tempC = 0;
int thresh = 1000;

void sendSensor(){
  capread = ss.touchRead(0);
  tempC = ss.getTemp();
  soil_moisture->save(capread);
  temperature->save(tempC);
}

void pump(){
  if(capread < thresh){
    digitalWrite(CONTROL_PIN, 1);
  }else{
    digitalWrite(CONTROL_PIN, 0);
  }
}

void setup() {
  pinMode(CONTROL_PIN, OUTPUT); 
  digitalWrite(CONTROL_PIN, 0);
  Serial.begin(115200);
  while(! Serial);
  
  Serial.println("seesaw Soil Sensor example!");
  if (!ss.begin(0x36)) {
    Serial.println("ERROR! seesaw not found");
    while(1) delay(1);
  } else {
    Serial.print("seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }

  Serial.print("Connecting to Adafruit IO");
  io.connect();
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {
  io.run();
  sendSensor();
  pump();
  
  Serial.print("Temperature: "); Serial.print(tempC); Serial.println("*C");
  Serial.print("Capacitive: "); Serial.println(capread);
  delay(5000);
}
