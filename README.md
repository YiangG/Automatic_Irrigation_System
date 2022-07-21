# ESE516_Smart_Irrigation_System

![This is an image](/autoIrrigation/overall.png)

### Description: 
Built an automatic irrigation system for room plants so that I don’t have to check the soil moisture level and water it myself. This project is inherited from a class project, so I basically have all materials I need for this. I also want it to log the soil moisture level and room temperature. 

### Material: 
ESP8266 NodeMCU;
Adafruit Soil Moisture Sensor;
3.3V Generic Water Pump;
2N2222A BJT;
100 Ohms Resistor;
Some Jumpers and Connectors;

### Schematic:
![Schematic](/autoIrrigation/schematic.png)

### Explaination:
I used the ESP8266’s 3V3 pin to provide power for the water pump because it only takes 100mA current, which the 3V3 has a max rating of 250mA. So, it’s safe to do so only with small water pump like the one I used, and you don’t have other power-hungry peripheral devices in your system. 

I used the Adafruit IO to log the data and visualize it in dashboard. There is also a thermometer incorporated into the soil moisture sensor, so I take advantage of this feature and make this system also a room temperature monitor. 

The 100Ohms resistor is used to limit the current entering the 2N2222A NPN transistor so that the MCU won’t drive too much current at once. 

![dashboard](/autoIrrigation/dashboard.png)

### Code: 
The code part is developed in Arduino IDE to take advantage of the soil moisture library. It is using the Adafruit IO library and Adafruit Seesaw library. 

To flash the code to Node MCU, you need to select the correct board in Arduino IDE, which in my case it's "NodeMCU 1.0 (ESP-12E Module)".

### Assembly:
I tested out the system on a breadboard first and then solder it onto a perfboard. 
![top](/autoIrrigation/topView.png)

I found an empty chestnut jar and decided to use it as a water tank for the pump and also the base of the device. The pump is fully water proof so it can be emersed in water. 

![side](/autoIrrigation/sideView.png)

### Result: 
This device successfully satisfies my demands of watering plants. So far this device has kept my plants alive for more than 3 months. 
