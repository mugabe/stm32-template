//
// Created by 12345 on 2019-03-22.
//

#include <ticks.hpp>
#include <libopencm3/stm32/gpio.h>
#include "LedBlinkingTask.h"

namespace tasks {

  LedBlinkingTask::LedBlinkingTask() :
    Thread("Led Blinking Task",
           configMINIMAL_STACK_SIZE,
           1)
  {
    this->Start();
  }

  void LedBlinkingTask::Run() {
    TickType_t delay_time = rtos::Ticks::MsToTicks(1000);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
      gpio_toggle(GPIOD, GPIO12);
      Thread::Delay(delay_time);
    }
#pragma clang diagnostic pop
  }

}