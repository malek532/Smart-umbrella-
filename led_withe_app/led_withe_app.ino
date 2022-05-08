
#include <ESP8266WiFi.h>

String  ClientRequest;
WiFiServer server(80);

void setup()
{
  ClientRequest = "";

Serial.begin(9600);
pinMode(2, OUTPUT);
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
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    ClientRequest = (client.readStringUntil('\r'));
    ClientRequest.remove(0, 5);
    ClientRequest.remove(ClientRequest.length()-9,9);
    Serial.println("message :");
    Serial.println(ClientRequest);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println(ClientRequest);
    client.println("</html>");

    delay(1);
    if (ClientRequest == "on") {
      digitalWrite(2,HIGH);

    }
    if (ClientRequest == "off") {
      digitalWrite(2,LOW);

    }
    client.flush();

}
