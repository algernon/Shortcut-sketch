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

#include "Macros.h"
#include "MouseKeys.h"

#include <Kaleidoscope-LangPack-Hungarian.h>
#include <Kaleidoscope-MouseKeys.h>

using namespace kaleidoscope::language;
using namespace algernon::MouseKeys;

namespace algernon {
  namespace Macros {
    void
    Csilla () {
      ::Macros.play (MACRO (Tr(LSHIFT(Key_C)),
                            T(S),
                            T(I),
                            T(L),
                            T(L)));

      handleKeyswitchEvent ((Key){.raw = HUN_AA}, 255, 255, IS_PRESSED | INJECTED);

      ::Macros.play (MACRO (T(M),
                            T(A),
                            T(S),
                            T(S),
                            T(Z),
                            T(O),
                            T(N),
                            T(Y),
                            T(K)));

      handleKeyswitchEvent ((Key){.raw = HUN_AA}, 255, 255, IS_PRESSED | INJECTED);

      ::Macros.play (MACRO (T(M)));
    }

    void
    Gergo () {
      ::Macros.play (MACRO (Tr(LSHIFT(Key_G)),
                            T(E),
                            T(J),
                            T(G)));

      handleKeyswitchEvent ((Key){.raw = HUN_ODA}, 255, 255, IS_PRESSED | INJECTED);
      Keyboard.sendReport ();
      handleKeyswitchEvent ((Key){.raw = HUN_ODA}, 255, 255, IS_PRESSED | INJECTED);
      Keyboard.sendReport ();
      handleKeyswitchEvent ((Key){.raw = HUN_ODA}, 255, 255, IS_PRESSED | INJECTED);
    }

    void
    configure (void) {
      Kaleidoscope.use (&::Macros, NULL);
    }
  }
}

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  if (!keyIsPressed (keyState))
    return MACRO_NONE;

  return MACRO_NONE;
}
