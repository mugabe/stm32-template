//
// Created by 12345 on 2019-03-22.
//

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

int main() {
  rcc_periph_clock_enable(RCC_GPIOD);

  gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
  while (true) {
    gpio_toggle(GPIOD, GPIO12);
    for (int i = 0; i < 1000000; i++) {
      __asm__("nop");
    }
  }
#pragma clang diagnostic pop
}
