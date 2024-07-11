# Alarmify
## Introduction
An alarm system, integrated with your home. The aim of the project is turning on the lights, water heater or coffee maker (or any combination of choice) automatically when it's time for you to wake up. It is helpful for waking up and having a fresh morning start.

## Implementation
The appliances ar generally AC devices hence requires relays. 
Components used in prototype circuit board:
- ESP32 or ESP8266
- AC relays(5v trigger), one for every appliance, upto pin limit of ESP
- Shottkey diodes and resistors

The ESP device uses wifi to interface with the user. Wifi manager starts up a hotspot where user can connect and then choose to make the ESP connect to home network or keep the ESP wifi.
User can then set alarm using the web-app of ESP and set alarm accordingly.

## Conclusion
Alarmify is a simple implementation but useful project. It has potential to scale both vertically or horizontally. Integration with larger smart home system such Home-Assistant or using multiple alarmify nodes accross the house is possible. It is now only usable in local network. But through MQTT server hosting and internet connection, it is possible to upgrade the project so that it can be controlled from anywhere in the world via the internet. In that case additional security measures will also have to be implemented.
