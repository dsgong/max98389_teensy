# Teensy 4.0/4.1 Driver for Max98389 Amplifier 

## Instructions
1. Install VSCode
2. Install the PlatformIO extension on VSCode
3. Git clone this repo
4. Open this repo as a project from PlatformIO home.
5. Build. (Checkmark on the bottom left)
6. Connect Teensy via USB and upload. (Arrow on the bottom left)
7. Select Teensy as the USB Audio device.

Audio played from computer will be passed through to the speaker. On recording audio from computer, left channel is voltage and right channel is current measurement. 

After uploading to teensy, you can read outputs from the terminal. From Windows, use PuTTY or some serial monitor. For Mac, use the screen command from terminal.

To use the driver in another PlatformIO project, copy the .h and .cpp files of include, lib, and source.
To use the driver with Teensy 4.1, modify platform.ini. 
