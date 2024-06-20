#include "max98389.h"
#include <i2c_device.h>

max98389::max98389(){
    master.begin(400 * 1000U);
}

bool max98389::configure(){
    uint8_t revisionId;
    // Check the revision ID and check for I2C errors
    if (amp.read(revision_id_register, &revisionId, false)) {
        if ( revisionId != expected_revision_id) {
            Serial.printf("ERROR: Manufacturer ID is 0x%X. Expected 0x%X.\n", revisionId, expected_revision_id);
            return false;
        }
    } else {
        report_error("ERROR: Failed to send manufacturer id register value");
        return false;
    }

    Serial.println("Configured sensor successfully.");
    return true;
    return true;
}

void max98389::report_error(const char* message) {
    Serial.print(message);
    Serial.print(" Error: ");
    Serial.println((int)master.error());
}