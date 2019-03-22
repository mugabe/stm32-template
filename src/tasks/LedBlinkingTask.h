//
// Created by 12345 on 2019-03-22.
//

#ifndef SKELETON_LEDBLINKINGTASK_H
#define SKELETON_LEDBLINKINGTASK_H

#include <thread.hpp>
#include "../hw/Led.h"

namespace tasks {

  namespace rtos = cpp_freertos;

  class LedBlinkingTask final : rtos::Thread {
  public:
    LedBlinkingTask();
    ~LedBlinkingTask() = default;

  private:
    void Run() override;
    hw::Led m_led;
  };

}


#endif //SKELETON_LEDBLINKINGTASK_H
