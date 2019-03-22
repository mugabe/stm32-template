//
// Created by 12345 on 2019-03-22.
//


#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include <FreeRTOS.h>

#include <thread.hpp>
#include <critical.hpp>

#include "tasks/LedBlinkingTask.h"
#include "hw/System.hpp"

namespace rtos = cpp_freertos;
uint32_t SystemCoreClock = 168000000;

void* operator new(size_t sz) {
  return pvPortMalloc(sz);
}

void* operator new[](size_t sz) {
  return pvPortMalloc(sz);
}

void operator delete(void* p) {
  vPortFree(p);
}

void operator delete[](void* p) {
  vPortFree(p);
}

extern "C" {
  void* __dso_handle;
  void* _fini;
}

int main() {
  hw::system::clock_init();
  hw::system::systick_init();

  hw::system::irq_disable();

  auto led_blinking_task = new tasks::LedBlinkingTask();

  rtos::Thread::StartScheduler();
  while (true);
}


void vApplicationMallocFailedHook()
{
  rtos::CriticalSection::Enter();
  {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true)
    {
      portNOP();
    }
#pragma clang diagnostic pop
  }
  rtos::CriticalSection::Exit();
}

void vAssertCalled(const char* pcFile, unsigned long ulLine)
{
  rtos::CriticalSection::Enter();
  {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while(true)
    {
      portNOP();
    }
#pragma clang diagnostic pop
  }
  rtos::CriticalSection::Exit();
}
