#include "Display.h"

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Display::Display(){

    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        while(1);
        // TODO: Turn on builtin led if fails
    }
    display.display();
    delay(2000);

    display.clearDisplay(); // Clear the display
    display.setTextSize(1); // Set text size
    display.setTextColor(WHITE); // Set text color
    display.setCursor(0, 0); // Set position to display
}

void Display::showIP(String ip){
    display.println(ip);
    display.display();
}