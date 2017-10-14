#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <DNSServer.h> 
#include <ESP8266WebServer.h>

#define APSSID "ESP8266-IOT" // SSID & Title
#define APPASSWORD "" // Blank password = Open AP
#define SUBTITLE "Internet Of Things" // Cool subtitle

const byte HTTP_CODE = 200;
const byte TICK_TIMER = 1000;
IPAddress APIP(192, 168, 2, 1);

unsigned long bootTime=0, lastActivity=0, lastTick=0, tickCtr=0;
DNSServer dnsServer; ESP8266WebServer webServer(80);

String input(String argName) {
  String a=webServer.arg(argName);
  a.replace("<","&lt;");a.replace(">","&gt;");
  a.substring(0,200); return a; }

String footer() { return "<footer>"
  "<div class=\"footer\""
  " <p><b>Author:</b> BlueArduino20. <b>2017</b></p>"
  "</div>"
  "</footer>";
}

String header() {
  String a = String(APSSID);
  String CSS = "article { background: #f2f2f2; padding: 1.3em; }" 
  "body { color: #333; font-family: Century Gothic, sans-serif; font-size: 18px; line-height: 24px; margin: 0; padding: 0; }"
  "div { padding: 0.35em; }"
  "h1 { margin: 0.5em 0 0 0; padding: 0.5em; }"
  "input { border-radius: 0; border: 1px solid #555555; }"
  "label { color: #333; display: block; font-style: italic; font-weight: bold; }"
  "nav { background: #0066ff; color: #fff; display: block; font-size: 1.3em; padding: 1em; }"
  "nav b { display: block; font-size: 1.5em; margin-bottom: 0.5em; } "
  "textarea { width: 100%; }"
  ".button {"
  "background-color: #4CAF50;"
  "border: 1px solid black;"
  "border-radius: 6px;"
  "color: white;"
  "padding: 15px 32px;"
  "text-align: center;"
  "text-decoration: none;"
  "display: inline-block;"
  "font-size: 16px;"
  "margin: 4px 2px;"
  "cursor: pointer;"
  "}"
  ".buttonb { background-color: #555555; }"
  ".footer {"
  "position: fixed;"
  "left: 0;"
  "bottom: 0;"
  "width: 100%;"
  "background-color: #0066ff;"
  "color: white;"
  "text-align: center;"
  "font-family: \"Verdana\", Sans, serif;"
  "border-radius: 0px;"
  "height: 25px"
  "}";
  String h = "<!DOCTYPE html><html>"
    "<head><title>"+a+" :: "+SUBTITLE+"</title>"
    "<meta name=viewport content=\"width=device-width,initial-scale=1\">"
    "<style>"+CSS+"</style></head>"
    "<body><nav><b>"+a+"</b> "+SUBTITLE+"</nav><br>";
  return h; }

String index() {
  return header() +
  // 1st ONE:
  +"<center><table><tr><th><div><form action=/1ON method=post>"+
  +"<input type=submit class=\"button\" value=\"1 ON\"></form></center></th>"+
  +"<th><center><div><form action=/1OFF method=post>"+
  +"<input type=submit class=\"button buttonb\" value=\"1 OFF\"></form></center></th></tr>"+
  // 2nd ONE:
  + "<table><tr><th><center><div><form action=/2ON method=post>"+
  +"<input type=submit class=\"button\" value=\"2 ON\"></form></center></th>"+
  +"<th><center><div><form action=/2OFF method=post>"+
  +"<input type=submit class=\"button buttonb\" value=\"2 OFF\"></form></center></th></tr>"+
  // 3rd ONE:
  + "<table><tr><th><center><div><form action=/3ON method=post>"+
  +"<input type=submit class=\"button\" value=\"3 ON\"></form></center></th>"+
  +"<th><center><div><form action=/3OFF method=post>"+
  +"<input type=submit class=\"button buttonb\" value=\"3 OFF\"></form></th></tr></center>"+
  // 4th ONE:
  + "<table><tr><th><center><div><form action=/4ON method=post>"+
  +"<input type=submit class=\"button\" value=\"4 ON\"></form></center></th>"+
  +"<th><center><div><form action=/4OFF method=post>"+
  +"<input type=submit class=\"button buttonb\" value=\"4 OFF\"></form></th></tr></table></center><br>" + footer();
}


void setup() {
  
  bootTime = lastActivity = millis();
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(APIP, APIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(APSSID, APPASSWORD);

  webServer.on("/1ON",[]() { digitalWrite(13, HIGH); webServer.send(HTTP_CODE, "text/html", index()); });
  webServer.on("/2ON",[]() { digitalWrite(14, HIGH); webServer.send(HTTP_CODE, "text/html", index()); });
  webServer.on("/3ON",[]() { digitalWrite(12, HIGH); webServer.send(HTTP_CODE, "text/html", index()); });
  webServer.on("/4ON",[]() { digitalWrite(15, HIGH); webServer.send(HTTP_CODE, "text/html", index()); });
  webServer.on("/1OFF",[]() { digitalWrite(13, LOW); webServer.send(HTTP_CODE, "text/html", index()); });
  webServer.on("/2OFF",[]() { digitalWrite(14, LOW); webServer.send(HTTP_CODE, "text/html", index()); });
  webServer.on("/3OFF",[]() { digitalWrite(12, LOW); webServer.send(HTTP_CODE, "text/html", index()); });
  webServer.on("/4OFF",[]() { digitalWrite(15, LOW); webServer.send(HTTP_CODE, "text/html", index()); });
  webServer.onNotFound([]() { lastActivity=millis(); webServer.send(HTTP_CODE, "text/html", index()); });

  webServer.begin();
  pinMode(13, OUTPUT); // LED setup
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW); // The built-in led will notify us that the setup is finished.
  delay(1000);
  digitalWrite(16, HIGH);
}


void loop() { 
  if ((millis()-lastTick)>TICK_TIMER) {lastTick=millis();} 
dnsServer.processNextRequest(); webServer.handleClient(); }
