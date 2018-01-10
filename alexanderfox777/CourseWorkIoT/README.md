# CourseWorkIoT

## Content

* [About](#about)
* [Build](#build)

## About

Signaling device using IoT. Manage your device using Bluetooth and Android, which is created in MIT Appinventor. 
When the smartphone is connected to the device, you can turn the alarm on and off. 
Opening the door is simulated with a button. After pressing the button, the siren is activated. Disconnect the siren only from Android.
Programm is using state-machine.
- '1' - turn security ON
- '0' - turn security OFF
## Build

The project is compiled using the **Makefile**. But Makefile included in this project does not know the location of the compiler on the hard disk. So all these files need to be added to the already created and configured project in the [~~normal~~](http://www.vim.org/ "God's gift
") [MPLAB](http://www.microchip.com/mplab/mplab-x-ide "The wiles of the devil") IDE. Also on hard disk needs to be installed [XC32](http://www.microchip.com/mplab/compilers) compiler.

After compilation, the intermediate object files will be in the `build/` folder, and the firmware file in the `dist/` folder.
