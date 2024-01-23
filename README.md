# Notes

I will be keeping track of my progess and files on [GitHub](https://github.com/davider3/hot_wheels)

## Mechanical

### Car

I bought a 1996 Ferrari F50 hot wheels car that is 1:64th scale. I chose this car because I had the same one when I was a kid and it was my favorite one. It will make this project a bit harder due to how slim it is but it will look cooler so... worth it.

### Wheels

The plan is to 3D print the rims and then use a small O-ring as the tire.

### Steering

The mechanics of the steering is what I expect to be the hardest part on the mechanical side. I am going to need to do more research on this part.

## Electrical

### Microcontrollers

I have choosen to use the [Xiao ESP32S3](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html) because it has built in wifi and BLE as well as a camera module all while being about the size of my thumb nail.
Because I don't want to solder headers on the the ESP32S3 I am using a [Xiao nRF52840](https://www.seeedstudio.com/Seeed-XIAO-BLE-nRF52840-p-5201.html) that I have on hand for some of the breadboard testing such as with the motors. It is very similar to the ESP32S3

### Motors

#### DC Motors

I plan to use a DC motor to run the drive train of the car. I have 3 small dc motors that I am going to run some tests on to see if there is a clear winner. I will be using a DRV883 motor driver to drive the motor.

* *AliExpress Motor*
  * Starts to spin when pwm set to 130
  * Doesn't seem to get going very fast
* *DC Motor from Servo*
  * TODO
* *Drones Motor*
  * TODO

#### Servo Motor

A linear servo motor will be used to control the steering. [This](https://www.aliexpress.us/item/3256803902617918.html?spm=a2g0o.order_list.order_list_main.25.11d91802HKlx2B&gatewayAdapt=glo2usa) is the one that I have ordered and am waiting for its arrival for testing.

### Wireless Comunication

#### Wifi

The ESP32S3 can host it's own site where it can stream the video that it is recording. I am expecting this to be one of the most difficult parts of this project because it is something that I have never attempting and do know much about.

#### Bluetooth

I have learned the the Xiao ESP32S3 can not use both BLE and wifi simultaneously so here are some possible options to get bluetooth working

* [nRF52832](https://www.adafruit.com/product/4077)
  * This one seems the most promising and I have ordered it
* [Adafruit](https://www.adafruit.com/product/2633?gad_source=1&gclid=CjwKCAiA5L2tBhBTEiwAdSxJX-DhtxsbeZsPt3To0yZa2fOcK93WYsXaxW21iXk-lTnZlqvUIBIB6hoCFlcQAvD_BwE)
* [EMB1061](https://www.digikey.com/en/products/detail/seeed-technology-co.,-ltd/113990637/9991618?utm_adgroup=&utm_source=google&utm_medium=cpc&utm_campaign=PMax%20Shopping_Product_Medium%20ROAS%20Categories&utm_term=&utm_content=&utm_id=go_cmp-20223376311_adg-_ad-__dev-c_ext-_prd-9991618_sig-CjwKCAiA5L2tBhBTEiwAdSxJXz18duXnDFGFxcSPZGcyd4cDNltrNpTvqeeqjhoR4t047QVLTzL3cRoCpKkQAvD_BwE&gad_source=1&gclid=CjwKCAiA5L2tBhBTEiwAdSxJXz18duXnDFGFxcSPZGcyd4cDNltrNpTvqeeqjhoR4t047QVLTzL3cRoCpKkQAvD_BwE)

### Other

One of the other things that I want to include is some headlights
Something else that I have thought about is that I might need to get rid of the original base of the car and replace it with a custom pcb to make everything fit.

## Software

I will be using the Platformio extension of VS Code to do the programming. I have already gone through all of the necessary setup so that I can create projects for both of the microcontrollers that I will be using and have successfully uploaded code to both micros. My plan is to have a sketch that can individually control each of the components before integrating them.
