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

#include "MagicCombo.h"
#include "Layers.h"
#include "Macros.h"

#include <Akela-MagicCombo.h>

namespace algernon {
  namespace MagicCombo {

    enum {
      CsillaQWERTY,
    };

    static const Akela::MagicCombo::dictionary_t dictionary[] PROGMEM = {
      // L2 + CS (Qwerty)
      [CsillaQWERTY] = {R0C6 | R2C2 | R1C1,
                        0},
      {0, 0},
    };

    void
    configure (void) {
      Keyboardio.use (&::MagicCombo, NULL);

      ::MagicCombo.configure (dictionary);
    }
  };
};

void magicComboActions (uint8_t comboIndex, uint32_t leftHand, uint32_t rightHand) {
  switch (comboIndex) {
  case algernon::MagicCombo::CsillaQWERTY:
    algernon::Macros::Csilla ();
    break;
  }
}
