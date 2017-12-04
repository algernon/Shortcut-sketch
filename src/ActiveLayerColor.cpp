/* -*- mode: c++ -*-
 * Shortcut-sketch -- algernon's Shortcut sketch
 * Copyright (C) 2016  Gergely Nagy
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

#include "ActiveLayerColor.h"
#include "Layers.h"

namespace algernon {
  namespace ActiveLayerColor {

    static const cRGB layerColorMap[LAYER_MAX] PROGMEM = {
      [_DVK] = CRGB(0, 0, 0),
      [_SYM] = CRGB(0xff, 0xff, 0x00),
    };

    void
    configure (void) {
      Kaleidoscope.use (&ActiveLayerColorEffect);
      ActiveLayerColorEffect.configure (layerColorMap);
    }
  };
};
