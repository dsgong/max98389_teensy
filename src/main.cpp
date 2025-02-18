#include <Arduino.h>
#include <i2c_device.h>
#include "max98389.h"
#include <Audio.h>


// GUItool: begin automatically generated code
AudioInputI2SQuad        i2s_quad1;      //xy=301,598
AudioOutputI2S           i2s2;           //xy=565,241
AudioInputUSB            usb1;           //xy=157,294
AudioOutputUSB           usb2;           //xy=405,293

AudioConnection          patchCord2(usb1, 0, i2s2, 0);
AudioConnection          patchCord3(usb1, 1, i2s2, 1);
AudioConnection          patchCord4(i2s_quad1, 2, usb2, 0);
AudioConnection          patchCord5(i2s_quad1, 3, usb2, 1);
bool configured = false;

void setup() {
    // Enable the serial port for debugging
    Serial.begin(9600);
    Serial.println("Started");
    max98389 max;
    max.master.set_internal_pullups(InternalPullup::disabled);
    max.begin(400 * 1000U);
    // Check that we can see the sensor and configure it.
    configured = max.configure();
    if (configured) {
        Serial.println("Configured");
    } else {
        Serial.println("Not configured");
    }
    AudioMemory(128);
}

void loop() {

}