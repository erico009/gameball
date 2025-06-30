Mouse implementation requirements:
Serial enabled
in "rules.mk"

    SERIAL_DRIVER = vendor
    POINTING_DEVICE_ENABLE = yes
    POINTING_DEVICE_DRIVER = pmw3389

"mcuconf.h"

    #pragma once

    #include_next <mcuconf.h>
    #undef RP_SPI_USE_SPI0
    #define RP_SPI_USE_SPI0 TRUE
    
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




