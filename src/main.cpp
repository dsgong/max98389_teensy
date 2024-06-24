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
}

void loop() {

    // Blink the LED
    digitalWrite(LED_BUILTIN, HIGH);
    delay(900);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
}