//
// Created by 12345 on 2019-03-22.
//

#ifndef SKELETON_LEDBLINKINGTASK_H
#define SKELETON_LEDBLINKINGTASK_H

#include <thread.hpp>

namespace tasks {

  namespace rtos = cpp_freertos;

  class LedBlinkingTask final : rtos::Thread {
  public:
    LedBlinkingTask();
    ~LedBlinkingTask() = default;

  private:
    void Run();
  };

}


#endif //SKELETON_LEDBLINKINGTASK_H
