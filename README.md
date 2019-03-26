# STM32 C++ Template.

**STM32 C++** project template with **FreeRTOS** and **libopencm3**. No HAL, no LL, no other standard libraries.

Project preconfigured for **STM32F4**.

## Prerequisites

### Toolchain

[arm-none-eabi-gcc](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads) is used to build the code.

### Libraries

Download/clone libraries to `libs` directory.

1. [libopencm3](https://github.com/libopencm3/libopencm3) - clone to `libs/libopencm3` and build (just `make`).
2. [libopencm3_cpp_extensions](https://github.com/thirdpin/libopencm3_cpp_extensions) - clone to `libs/libopencm3_cpp_extensions`.
3. [FreeRTOS](https://www.freertos.org/a00104.html) - extract `FreeRTOS/Source` to `libs/freertos`.
4. [freertos-addons](https://github.com/michaelbecker/freertos-addons) - clone to `libs/freertos-addons`.


## Special thanks!

This template based on [Pastilda](https://bitbucket.org/thirdpin_team/pastilda) source code. As new embed developer I found it very usefull for my first C++ STM32 projects.
