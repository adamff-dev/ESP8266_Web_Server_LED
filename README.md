# ESP8266 Web server (LED diodes control)
NodeMCU (ESP8266) + Web server + 4 LED diodes = Easy IOT example

<h2>Web server</h2>

<img width="225" height="385" src="https://raw.githubusercontent.com/BlueArduino20/ESP8266_Web_Server_LED/master/Screenshot.jpg" title="ESP8266 Web server">

<h2>Default settings</h2>

- **WiFi SSID:** ESP8266-IOT

- **Gateway:** 192.168.2.1

<h2>Connections</h2>
<table><tr><th>NodeMCU</th><th>LED</th></tr>
<tr><td align="center">D5 (GPIO14)</td><td align="center">1st anode</td></tr>
<tr><td align="center">D6 (GPIO12)</td><td align="center">2nd anode</td></tr>
<tr><td align="center">D7 (GPIO13)</td><td align="center">3rd anode</td></tr>
<tr><td align="center">D8 (GPIO15)</td><td align="center">4th anode</td></tr>
<tr><td align="center">GND</td><td align="center">All cathodes</td></tr></table>

**Advice!** You should add 330Ω resistors before every anode.
