#include <Arduino.h>
#include <i2c_device.h>
#include "max98389.h"
#include <Audio.h>


// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=188,240
AudioEffectEnvelope      envelope1;      //xy=371,237
AudioInputI2S            i2s1;           //xy=155,369
AudioOutputI2S           i2s2;           //xy=565,241
AudioInputUSB            usb1;           //xy=157,294
AudioOutputUSB           usb2;           //xy=405,293

AudioConnection          patchCord1(waveform1, envelope1);
AudioConnection          patchCord2(envelope1, 0, i2s2, 0);
AudioConnection          patchCord3(envelope1, 0, i2s2, 1);
AudioConnection          patchCord4(i2s1, 0, usb2, 0);
AudioConnection          patchCord5(i2s1, 1, usb2, 1);
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

    AudioMemory(128);

    //waveform1.pulseWidth(0.5);
    waveform1.begin(0.1, 306, WAVEFORM_SINE);

    envelope1.attack(0);
    envelope1.decay(0);
    envelope1.release(0);

    envelope1.noteOn();
}

void loop() {

    float w;
    for (uint32_t i =1; i<20; i++) {
        w = i / 20.0;
        //waveform1.pulseWidth(w);
        
        /*digitalWrite(LED_BUILTIN, HIGH);
        delay(800);
        envelope1.noteOff();
        digitalWrite(LED_BUILTIN, LOW);
        delay(600);
        */
    }
}