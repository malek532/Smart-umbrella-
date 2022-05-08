
#include <ESP8266WiFi.h>

#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

void reconnectmqttserver() {
while (!client.connected()) {
Serial.print("Attempting MQTT connection...");
String clientId = "ESP8266Client-";
 clientId += String(random(0xffff), HEX);
if (client.connect(clientId.c_str())) {
Serial.println("connected");
  client.subscribe("attia");
} else {
Serial.print("failed, rc=");
Serial.print(client.state());
Serial.println(" try again in 5 seconds");
delay(5000);
}
}
}

void callback(char* topic, byte* payload, unsigned int length) {
  String MQTT_DATA = "";
  for (int i=0;i<length;i++) {
   MQTT_DATA += (char)payload[i];}
  Serial.println("le mssage ");
  Serial.println(MQTT_DATA);
  if (MQTT_DATA == "ON") {
    digitalWrite(2,HIGH);

  }
  if (MQTT_DATA == "OFF") {
    digitalWrite(2,LOW);

  }

}

char msgmqtt[50];
void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("TOPNET_BC18","attia4070");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("..");

  }
  Serial.println("Connected");
  Serial.println("Your IP is");
  Serial.println((WiFi.localIP().toString()));
  client.setServer("test.mosquito.org", 1883);
  client.setCallback(callback);

pinMode(2, OUTPUT);
}


void loop()
{

    if (!client.connected()) {
    reconnectmqttserver();
    }
    client.loop();

  snprintf (msgmqtt, 50, "%d ");
  client.publish("attia", msgmqtt);

}
