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

#include "Kaleidoscope.h"
#include "Kaleidoscope-LangPack-Hungarian.h"

#include "ActiveLayerColor.h"
#include "Layers.h"
#include "OneShot.h"
#include "Macros.h"
#include "MagicCombo.h"
#include "MouseKeys.h"

#define Key_LSBrck Key_LSquareBracket
#define Key_RSBrck Key_RSquareBracket
#define Key_MBtnL  Key_mouseBtnL
#define Key_MBtnR  Key_mouseBtnR

#define TG(layer) (Key){ layer, KEY_FLAGS | SYNTHETIC | SWITCH_TO_KEYMAP }

using namespace algernon::MouseKeys;

const Key keymaps[][ROWS][COLS] PROGMEM = {
  /* Dvorak layer
   *
   *                   ,-----.                                                   ,-----.
   *             ,-----+  .  +-----------.                           ,-----------|  C  |-----.
   *       ,-----|  ,  |-----|  P  |  Y  |                           |  F  |  G  |-----|  R  |-----.
   * ,-----|  A  |-----|  E  |-----+-----|                           |-----+-----|  T  |-----|  L  |-----.
   * |  Z  |-----|  O  |-----|  U  |  I  |                           |  D  |  H  |-----|  N  |-----| S   |
   * `-----|  Q  |-----|  K  |-----+-----'                           `-----+-----|  M  |-----|  V  |-----'
   *       `-----|  J  |-----|  X  |       ,-------.       ,-------.       |  B  |-----|  W  |-----'
   *             `-----'     `-----'       |  ETY  |       |       |       `-----'     `-----'
   *                                       |       |       |  Tab  |
   *                            ,-------.  |  GAM  |       |       |  ,-------.
   *                            |S Ctl A|  `-------'       `-------'  |E AGr B|
   *                            |f     l|                             |n     s|
   *                            |t SYM t|                             |t SPC p|
   *                            `-------'                             `-------'
   */
  [_DVK] = KEYMAP
  (
                         Key_Period                                              ,Key_C
                 ,Key_Comma    ,Key_P ,Key_Y                       ,Key_F ,Key_G        ,Key_R
          ,Key_A        ,Key_E                                                   ,Key_T        ,Key_L
   ,Key_Z        ,Key_O        ,Key_U ,Key_I                       ,Key_D ,Key_H        ,Key_N        ,Key_S
          ,Key_Q        ,Key_K                                                   ,Key_M        ,Key_V
                 ,Key_J        ,Key_X                                     ,Key_B        ,Key_W

                        ,MO(_ETY)                                   ,Key_Tab
           ,Key_NoKey                ,Key_NoKey            ,Key_Tab          ,Key_Tab
                        ,TG(_GAM)                                   ,Key_Tab

                 ,Key_LCtrl                                               ,Key_RAlt
     ,Key_LShift               ,Key_LAlt                       ,Key_Enter           ,Key_Backspace
                 ,MO(_SYM)                                                ,Key_Space
  ),


  /* Numbers, navigation & symbol layer
   *
   *                   ,-----.                                                   ,-----.
   *             ,-----+  3  +-----------.                           ,-----------|  8  |-----.
   *       ,-----|  2  |-----|  4  |  5  |                           |  6  |  7  |-----|  9  |-----.
   * ,-----|  1  |-----|  '  |-----+-----|                           |-----+-----|  [  |-----|  0  |-----.
   * | Esc |-----|  `  |-----|  /  |  \  |                           |  =  |  -  |-----|  ]  |-----|     |
   * `-----| Lft |-----| Up  |-----+-----'                           `-----+-----|RClk |-----| End |-----'
   *       `-----| Dn  |-----| Rgt |       ,-------.       ,-------.       |LClk |-----| Home|-----'
   *             `-----'     `-----'       |  ETY  |       |M MUp M|       `-----'     `-----'
   *                                       |       |       |L     R|
   *                            ,-------.  |  GAM  |       |t MDn g|  ,-------.
   *                            |S Ctl A|  `-------'       `-------'  |S AGr D|
   *                            |f     l|                             |f     e|
   *                            |t QTY t|                             |t Cnt l|
   *                            `-------'                             `-------'
   */
  [_SYM] = KEYMAP
  (
                         Key_3                                                            ,Key_8
                 ,Key_2        ,Key_4     ,Key_5                       ,Key_6      ,Key_7        ,Key_9
          ,Key_1        ,Key_Quote                                                        ,Key_LSBrck   ,Key_0
   ,Key_Esc      ,Key_Backtick ,Key_Slash ,Key_Backslash               ,Key_Equals ,Key_Minus    ,Key_RSBrck       ,Key_NoKey
          ,Key_LArrow   ,Key_UpArrow                                                      ,Key_MBtnR    ,Key_End
                 ,Key_DnArrow  ,Key_RArrow                                         ,Key_MBtnL    ,Key_Home

                        ,___                                           ,Key_mouseUp
           ,___                      ,___                     ,Key_mouseL        ,Key_mouseR
                        ,___                                           ,Key_mouseDn

                 ,Key_LCtrl                                                  ,Key_RAlt
     ,Key_LShift               ,Key_LAlt                          ,Key_RShift          ,Key_Delete
                 ,___                                                        ,Key_RCtrl
  ),

  /* Gaming layer
   *
   *                   ,-----.                                                   ,-----.
   *             ,-----+     +-----------.                           ,-----------|     |-----.
   *       ,-----|  W  |-----| Esc |     |                           | Alt | RCk |-----|  U  |-----.
   * ,-----|  A  |-----|  D  |-----+-----|                           |-----+-----| Lft |-----| Rgt |-----.
   * |  1  |-----|  S  |-----| Ent |     |                           | Ctl | LCk |-----| Dwn |-----|     |
   * `-----|  2  |-----|  4  |-----+-----'                           `-----+-----| Hme |-----| End |-----'
   *       `-----|  3  |-----| Sft |       ,-------.       ,-------.       |     |-----|     |-----'
   *             `-----'     `-----'       |  ETY  |       |  Spc  |       `-----'     `-----'
   *                                       |       |       |Q     F|
   *                            ,-------.  |  QTY  |       |   E   |  ,-------.
   *                            |M MA+ M|  `-------'       `-------'  |M MUp M|
   *                            |S     S|                             |L     R|
   *                            |+ MA- -|                             |t MDn g|
   *                            `-------'                             `-------'
   */
  [_GAM] = KEYMAP
  (
                         XXX                                                              ,XXX
                 ,Key_W        ,Key_Esc   ,XXX                         ,Key_LAlt   ,Key_MBtnR    ,Key_UpArrow
          ,Key_A        ,Key_D                                                            ,Key_LArrow   ,Key_RArrow
   ,Key_1        ,Key_S        ,Key_Enter ,XXX                         ,Key_LCtrl  ,Key_MBtnL    ,Key_DnArrow    ,XXX
          ,Key_2        ,Key_4                                                            ,Key_Home     ,Key_End
                 ,Key_3        ,Key_LShift                                         ,XXX          ,XXX

                        ,___                                           ,Key_Space
           ,___                      ,___                     ,Key_Q             ,Key_F
                        ,___                                           ,Key_E

                 ,M(MAP)                                                     ,Key_mouseUp
     ,M(MSP)                   ,M(MSM)                            ,Key_mouseL          ,Key_mouseR
                 ,M(MAM)                                                     ,Key_mouseDn
  ),

  /* Empty layer
   *
   *                   ,-----.                                                   ,-----.
   *             ,-----+     +-----------.                           ,-----------|     |-----.
   *       ,-----|     |-----|     |     |                           |     |     |-----|     |-----.
   * ,-----|     |-----|     |-----+-----|                           |-----+-----|     |-----|     |-----.
   * |     |-----|     |-----|     |     |                           |     |     |-----|     |-----|     |
   * `-----|     |-----|     |-----+-----'                           `-----+-----|     |-----|     |-----'
   *       `-----|     |-----|     |       ,-------.       ,-------.       |     |-----|     |-----'
   *             `-----'     `-----'       |       |       |       |       `-----'     `-----'
   *                                       |       |       |       |
   *                            ,-------.  |       |       |       |  ,-------.
   *                            |       |  `-------'       `-------'  |       |
   *                            |       |                             |       |
   *                            |       |                             |       |
   *                            `-------'                             `-------'
   */
  [_ETY] = KEYMAP
  (
                         XXX                                                     ,XXX
                 ,XXX          ,XXX   ,XXX                         ,XXX   ,XXX          ,XXX
          ,XXX          ,XXX                                                     ,XXX          ,XXX
   ,XXX          ,XXX          ,XXX   ,XXX                         ,XXX   ,XXX          ,XXX          ,XXX
          ,XXX          ,XXX                                                     ,XXX          ,XXX
                 ,XXX          ,XXX                                       ,XXX          ,XXX

                        ,___                                        ,XXX
           ,XXX                      ,XXX                  ,XXX            ,XXX
                        ,XXX                                        ,XXX

                 ,XXX                                                     ,XXX
     ,XXX                      ,XXX                            ,XXX                 ,XXX
                 ,XXX                                                     ,XXX
  ),
};

void setup () {
  Serial.begin(9600);

  Kaleidoscope.setup (KEYMAP_SIZE);
  Kaleidoscope.use (&Hungarian, NULL);

  algernon::ActiveLayerColor::configure ();
  algernon::MouseKeys::configure ();
  algernon::OneShot::configure ();
  algernon::MagicCombo::configure ();
  algernon::Macros::configure ();

  Layer.on (_DVK);
}

void loop () {
  Kaleidoscope.loop ();
}
