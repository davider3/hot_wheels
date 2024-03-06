#ifndef CAMERA_H_
#define CAMERA_H_

#include <Arduino.h>
#include "esp_camera.h"
#include <WiFi.h>
#define CAMERA_MODEL_XIAO_ESP32S3 // Has PSRAM
#include "camera_pins.h"

class Camera{
private:
    IPAddress ip;

public:

    Camera(const char*, const char*);

    IPAddress getIP();

};


#endif