// Copyright © 2019-2020 Richard Gemmell
// Released under the MIT License. See license.txt. (https://opensource.org/licenses/MIT)

// This example WILL NOT work unless you have an INA260
// current sensor connected to pins 18 and 19.
//
// Demonstrates use of the I2C Device class to represent a slave device.
// Creates an I2C master, configures a device and reads registers.

#include <Arduino.h>
#include <i2c_device.h>
#include "max98389.h"

bool configured = false;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

    // Enable the serial port for debugging
    Serial.begin(9600);
    Serial.println("Started");
    delay(100);
    max98389 max;

    // Check that we can see the sensor and configure it.
    configured = max.configure();
}

void loop() {
    if (configured) {

    } else {
        Serial.println("Not configured");
    }

    // Blink the LED
    digitalWrite(LED_BUILTIN, HIGH);
    delay(900);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}