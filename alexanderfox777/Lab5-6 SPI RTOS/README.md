# Labs #5, 6: SPI, OLED display and FreeRTOS 

## About

In this project chipKIT Basic I/O Shield is used for displaying text on OLED screen.
Program has two diffrent tasks, all of which output output text to the display, 
and uses FreeRTOS (https://www.freertos.org) to switch between them.
The project was tested on `PIC32MZ2048ECG100` and `PIC32MZ2048EFG100`.

Project is documented with doxygen. Reference manual in pdf can be generated using ```make pdf``` command.