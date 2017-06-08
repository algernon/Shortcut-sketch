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

#include <Kaleidoscope-MagicCombo.h>

namespace algernon {
  namespace MagicCombo {

    enum {
      CsillaDvorak,
    };

    static const kaleidoscope::MagicCombo::combo_t magic_combos[] PROGMEM = {
      // _ETY + CS (Dvorak)
      [CsillaDvorak] = {R0C6,
                        R0C11 | R2C13},
      {0, 0},
    };

    void
    configure (void) {
      Kaleidoscope.use (&::MagicCombo, NULL);

      ::MagicCombo.magic_combos = magic_combos;
    }
  };
};

void magicComboActions (uint8_t comboIndex, uint32_t leftHand, uint32_t rightHand) {
  switch (comboIndex) {
  case algernon::MagicCombo::CsillaDvorak:
    algernon::Macros::Csilla ();
    break;
  }
}
