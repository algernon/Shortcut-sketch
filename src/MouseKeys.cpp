/* -*- mode: c++ -*-
 * Shortcut-sketch -- algernon's Shortcut sketch
 * Copyright (C) 2017  Gergely Nagy
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

#include "MouseKeys.h"

namespace algernon {
  namespace MouseKeys {

    void
    configure (void) {
      Mouse.begin ();
      AbsoluteMouse.begin ();

      Kaleidoscope.use (&::MouseKeys, NULL);

      ::MouseKeys.speedDelay = 10;
      ::MouseKeys.speed = 1;
      ::MouseKeys.accelSpeed = 0;
    }

    void
    accelUp (void) {
      if (::MouseKeys.accelDelay > 10)
        ::MouseKeys.accelDelay -= 10;
      else if (::MouseKeys.accelDelay > 0)
        ::MouseKeys.accelDelay = 0;
      else if (::MouseKeys.accelSpeed < 255)
        ::MouseKeys.accelSpeed++;
    }

    void
    accelDown (void) {
      if (::MouseKeys.accelSpeed > 0)
        ::MouseKeys.accelSpeed--;
      else if (::MouseKeys.accelDelay < 1000)
        ::MouseKeys.accelDelay += 10;
    }

    void
    speedUp (void) {
      if (::MouseKeys.speedDelay > 10)
        ::MouseKeys.speedDelay -= 10;
      else if (::MouseKeys.speedDelay > 0)
        ::MouseKeys.speedDelay = 0;
      else if (::MouseKeys.speed < 255)
        ::MouseKeys.speed++;
    }

    void
    speedDown (void) {
      if (::MouseKeys.speed > 1)
        ::MouseKeys.speed--;
      else if (::MouseKeys.speedDelay < 1000)
        ::MouseKeys.speedDelay += 10;
    }
  };
};
