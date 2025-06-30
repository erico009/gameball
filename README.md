Pi Pico split keyboard with encoder, trackball and joystick.

Split implementation "config.h"
    
    #define SPLIT_HAND_PIN GP28

    #define SERIAL_USART_FULL_DUPLEX
    #define SERIAL_USART_TX_PIN GP0
    #define SERIAL_USART_RX_PIN GP1

"rules.mk"

    SERIAL_DRIVER = vendor
    SPLIT_KEYBOARD = yes
    
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

"POINTING_DEVICE_LEFT" if mouse sensor is on left

For a split keyboard the matrix will have double the columns. The first half will account for one side of the split keyboard. For this keyboard with mirrored wiring, row number counts from max to lowest for each column of the other half. Example below shows first row of each half.
                
    {"matrix": [0, 0], "x": 0, "y": 0.375},
    {"matrix": [0, 1], "x": 1, "y": 0.375},
    {"matrix": [0, 2], "x": 2, "y": 0.125},
    {"matrix": [0, 3], "x": 3, "y": 0},
    {"matrix": [0, 4], "x": 4, "y": 0.125},
    {"matrix": [0, 5], "x": 5, "y": 0.25},
    {"matrix": [0, 6], "x": 6, "y": 0.75},

    {"matrix": [5, 6], "x": 11.5, "y": 0.75},
    {"matrix": [5, 5], "x": 12.5, "y": 0.25},
    {"matrix": [5, 4], "x": 13.5, "y": 0.125},
    {"matrix": [5, 3], "x": 14.5, "y": 0},
    {"matrix": [5, 2], "x": 15.5, "y": 0.125},
    {"matrix": [5, 1], "x": 16.5, "y": 0.375},
    {"matrix": [5, 0], "x": 17.5, "y": 0.375},

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




