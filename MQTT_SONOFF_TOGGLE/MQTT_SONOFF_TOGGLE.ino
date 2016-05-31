#include <Arduino.h>
#include <MqttConnector.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

MqttConnector *mqtt;

#define MQTT_HOST         "mqtt.espert.io"
#define MQTT_PORT         1883
#define MQTT_USERNAME     ""
#define MQTT_PASSWORD     ""
#define MQTT_CLIENT_ID    ""
#define MQTT_PREFIX       "/CMMC"
#define PUBLISH_EVERY     (1*1000)// every 10 seconds

/* DEVICE DATA & FREQUENCY */
#define DEVICE_NAME       "CNX-SONOFF-001"

/* WIFI INFO */
#ifndef WIFI_SSID   //"ESPERT-002"  "@ESPertAP-001" 
#define WIFI_SSID        "ESPERT-002"
#define WIFI_PASSWORD    "espertap"
#endif

#define BUTTON  0
#define RELAY 12
#define LED   13

#include "_publish.h"
#include "_receive.h"
#include "init_mqtt.h"

void init_hardware()
{
  Serial.begin(115200);
  delay(10);
  pinMode(BUTTON, INPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.println();
  Serial.println("Serial port initialized.");
}

void setup()
{
  init_hardware();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf ("Connecting to %s:%s\r\n", WIFI_SSID, WIFI_PASSWORD);
    delay(300);
  }

  Serial.println("WiFi Connected.");

  init_mqtt();
}

void loop()
{
  mqtt->loop();
}
