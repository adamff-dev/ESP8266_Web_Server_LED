# ESP8266 Web server (LED diodes control)
This is a simple IOT example for the NodeMCU or ESP8266. You can control some LED diodes from NodeMCU through an user-friendly web server.

<h2>Web server</h2>

<img width="225" height="385" src="https://raw.githubusercontent.com/BlueArduino20/ESP8266_Web_Server_LED/master/Screenshot_01.png" title="ESP8266 Web server">

<a href="https://www.buymeacoffee.com/rSiZtB3" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>

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
