#include<CayenneMQTTESP8266.h>
#include <dht11.h>
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#define DHT11PIN D8 //connect your DHT11 in pin8 on the board
dht11 DHT11;
char ssid[] = "wifissid";
char password[] = "wifipassword";

char username[] = "Mqtt username";
char mqtt_pass[] = "Mqtt pass";
char client_id[] = "client id";
void setup() {
  Cayenne.begin(username, mqtt_pass, client_id, ssid, password);

}
void loop() {
  Cayenne.loop();
  int chk = DHT11.read(DHT11PIN);
  float temp =(float)DHT11.temperature;
  float hum =(float)DHT11.humidity;
  
  Cayenne.virtualWrite(1, temp, TYPE_TEMPERATURE, UNIT_CELSIUS);
  Cayenne.virtualWrite(2, hum, TYPE_RELATIVE_HUMIDITY, UNIT_PERCENT);

}
