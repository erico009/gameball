# Pi Pico split keyboard with encoder, trackball and joystick.
![28AA07EF-C69F-4516-BC5A-CE71703BDD2E](https://github.com/user-attachments/assets/e670d900-998b-4d72-ad4c-23169abe6367)
## Design choice

### Keycaps(and key spacing)

The keycaps are KLP Lame saddle, except vertically challenged. Vertical width of the keycaps are 85% of the original, with reduced spacing between the switches to match. This reduces the travel between switches(small hands). Columnar stagger would be more ergonomic reducing the movement of wrists when trying to hit pinky keys for touch typers, however the goal of the keyboard was to be able to use it for traditional WASD gaming as well as with the joystick. Depending on how aggresive the stagger it can range from WASD gaming being unplayable to mildly annoying. Also why there are no key wells.

### Trackball

Its a trackball. The mouse sensor is located to the right of the ball. There is a -20 degree tilt set in the firmware allowing a more natural movement of the thumb. The actual ball is a baoding ball, about the cheapest thing I could find. Extremely rough tracking and has a bell inside that jingles everytime the mouse is used, replacing with smooth white balls. Ball size is 1.5 inches, because it was the biggest one that wouldn't get in the way.

### Joystick

A Nintendo switch style joystick was used to reduce the profile while maintaining the traditional movement of a joystick, unlike a psp1000 sliding joystick. There is a -20 degree tilt here as well to allow for more natural movement of the thumb. A TMR joystick used to prevent stick drift in the future. This particular joystick has very light springs so its easier to move without sliding the keyboard around.

### No thumb cluster????

I can hardly reach past the thumb key on the right side(small hands). If needed the joystick can be rebound as a thumb cluster, adding a fn key to enable arrow keys on trackball.

### Encoder

It doesn't spin... yet.

## Keymap (so far)

### Combos

Combos are used to implement the mouse keys, left click is "j" and "k", right click is "k" and "l", middle mouse button is "j" and "l".

### Joystick

Using the F13(permantly temporary) key bound to the key 7 to the right and 4 down on the left side of the keyboard. The joystick can cycle through WASD, arrow keys, and controller output.

### Encoder

Used for regular scrolling so that the mouse functionallity can be used one handed (without using a function key to enable scrolling on the trackball).

## Technical Stuff

Maybe helpful. RP2040 specific.

### Split implementation 

"config.h"
    
    #define SPLIT_HAND_PIN GP28

    #define SERIAL_USART_FULL_DUPLEX
    #define SERIAL_USART_TX_PIN GP0
    #define SERIAL_USART_RX_PIN GP1

"rules.mk"

    SERIAL_DRIVER = vendor
    SPLIT_KEYBOARD = yes
    
### Mouse implementation
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

### Encoder implementation 

refer to QMK docs

### Joystick implementation 

refer to QMK docs. 

Note ADC signal only reports on master(?) In this keyboard the ADC signal is sent through USB 4.0 CC and SBU pins so that each side can use the signal from the joystick when acting as master. In theory if only the left side is ever connected the same USB 4.0 CC and SBU pins can be used to have 1 joystick on each side of the split without custom transport code.

### Split Matrix

For a split keyboard the matrix will have double the columns. The first half will account for one side of the split keyboard. For this keyboard with mirrored wiring, row number counts from in reverse for each column of the other half. Example below shows first row of each half(numbers in square brackets).
                
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
    
## Hardware Stuff

Pi Pico pins
<picture>
![image](https://github.com/user-attachments/assets/d5c09dd5-5870-49c5-af64-c63cd70dd36a)
</picture>
Joystick pins

<picture>
<img src="https://github.com/user-attachments/assets/09c3ba0c-979f-4511-b104-186558ca0a61" width="300">
</picture>

Encoder pins(metal facing toward you)

![image](https://github.com/user-attachments/assets/fd7e67e2-0926-4ba7-866a-cd326067a23b)




