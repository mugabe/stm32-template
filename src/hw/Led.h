/*
 * This file is part of the pastilda project.
 * hosted at http://github.com/thirdpin/pastilda
 *
 * Copyright (C) 2016  Third Pin LLC
 * www.thirdpin.ru
 * www.thirdpin.ru/en/
 *
 * Written by:
 *  Anastasiia Lazareva <a.lazareva@thirdpin.ru>
 *	Dmitrii Lisin 		<d.lisin@thirdpin.ru>
 *	Ilya Stolyarov 		<i.stolyarov@thirdpin.ru>
 *	Pavel Larionov      <p.larionov@thirdpin.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HW_LED_H_
#define HW_LED_H_

#include <libopencm3_cpp_extensions/gpio_ext.h>

namespace hw {

  class Led {

  public:
    ~Led() = default;

    Led(GPIO_CPP_Extension::Pinout p) :
      _pinout(p)
    {
      _pinout.mode_setup(GPIO_CPP_Extension::Mode::OUTPUT, GPIO_CPP_Extension::PullMode::NO_PULL);
    }

    void on() {
      _pinout.clear();
    }

    void off() {
      _pinout.set();
    }

    void toggle() {
      _pinout.toggle();
    }
  private:
    GPIO_CPP_Extension::GPIO_ext _pinout;
  };

} /* namespace hw */

#endif /* HW_LED_H_ */
