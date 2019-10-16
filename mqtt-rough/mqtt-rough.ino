#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WIFI_SSID "your-wifi-ssid"
#define WIFI_PASS "your-wifi-password"

#define MQTT_SERV "io.adafruit.com"
#define MQTT_PORT 1883

//The MQTT_NAME and _PASS will be obtained when you create an account on adafruit

#define MQTT_NAME "your-mqtt-wprk"
#define MQTT_PASS "your-mqtt-password"
#define LED D7
#define bla D3

//Set up MQTT and WiFi clients
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, MQTT_SERV, MQTT_PORT, MQTT_NAME, MQTT_PASS);

//Set up the feed you're subscribing to
Adafruit_MQTT_Subscribe wheel = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/wheel");
Adafruit_MQTT_Subscribe fan = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/fan");



void setup()
{
  Serial.begin(9600);

  //Connect to WiFi
  Serial.print("\n\nConnecting Wifi... ");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  Serial.println("OK!");

  //Subscribe to the onoff feed
  mqtt.subscribe(&wheel);
  mqtt.subscribe(&fan);
  pinMode(bla,OUTPUT);
  pinMode(LED, OUTPUT);
  //digitalWrite(LED, HIGH);
}

void loop()
{
  MQTT_connect();
  
  //Read from our subscription queue until we run out, or
  //wait up to 5 seconds for subscription to update
  Adafruit_MQTT_Subscribe * subscription;
  while ((subscription = mqtt.readSubscription(5000)))
  {
    //If we're in here, a subscription updated...
    if (subscription == &wheel)
    {
      //Print the new value to the serial monitor
      Serial.print("wheel: ");
      Serial.println((char*) wheel.lastread);
      
      //If the new value is  "ON", turn the light on.
      //Otherwise, turn it off.
      uint16_t state= atoi((char *)wheel.lastread);
      digitalWrite(LED,state);
    }
    if (subscription == &fan)
    {
      //Print the new value to the serial monitor
      Serial.print("fan: ");
      Serial.println((char*) fan.lastread);
      
      //If the new value is  "ON", turn the light on.
      //Otherwise, turn it off.
      uint16_t state= atoi((char *)fan.lastread);
      digitalWrite(bla,state);
    }
  }

  // ping the server to keep the mqtt connection alive
  if (!mqtt.ping())
  {
    mqtt.disconnect();
  }
}




void MQTT_connect() 
{
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) 
  {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) 
  { 
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) 
       {
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}
