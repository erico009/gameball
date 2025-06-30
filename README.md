Mouse implementation
"rules.mk"

    SERIAL_DRIVER = vendor
    POINTING_DEVICE_ENABLE = yes
    POINTING_DEVICE_DRIVER = pmw3389

"mcuconf.h"

    #pragma once

    #include_next <mcuconf.h>
    #undef RP_SPI_USE_SPI0
    #define RP_SPI_USE_SPI0 TRUE

"config.h"

    #define SPI_DRIVER SPID0
    #define SPI_SCK_PIN GP2
    #define SPI_MOSI_PIN GP3
    #define SPI_MISO_PIN GP4
    #define PMW33XX_CS_PIN GP5

For split (first enable all split requirements) "config.h"
    
    #define SPLIT_POINTING_ENABLE
    #define POINTING_DEVICE_RIGHT
    #define SPLIT_HAND_PIN GP28
handedness pin should be connected to 3v3(left) and GND(right) with a resistor(?) 
    
Pi Pico pins
<picture>
![image](https://github.com/user-attachments/assets/d5c09dd5-5870-49c5-af64-c63cd70dd36a)
</picture>
Joystick pins

<picture>
<img src="https://github.com/user-attachments/assets/09c3ba0c-979f-4511-b104-186558ca0a61" width="300">
</picture>

Encoder pins(metal facing toward face)

![image](https://github.com/user-attachments/assets/fd7e67e2-0926-4ba7-866a-cd326067a23b)




