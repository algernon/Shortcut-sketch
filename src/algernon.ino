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

#include "KeyboardioFirmware.h"

#include "Akela-LangPack-Hungarian.h"

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

const Key keymaps[][ROWS][COLS] PROGMEM = {
  /* 0 - Base layer
   *
   *                   ,-----.                                                   ,-----.
   *             ,-----+  E  +-----------.                           ,-----------|  I  |-----.
   *       ,-----|  W  |-----|  R  |  T  |                           |  Y  |  U  |-----|  O  |-----.
   * ,-----|  A  |-----|  D  |-----+-----|                           |-----+-----|  K  |-----|  P  |-----.
   * |  Q  |-----|  S  |-----|  F  |  G  |                           |  H  |  J  |-----|  L  |-----| . > |
   * `-----|  Z  |-----|  C  |-----+-----'                           `-----+-----|  N  |-----| , < |-----'
   *       `-----|  X  |-----|  V  |       ,-------.       ,-------.       |  B  |-----|  M  |-----'
   *             `-----'     `-----'       |  ETY  |       |       |       `-----'     `-----'
   *                                       |       |       |  Tab  |
   *                            ,-------.  |  GAM  |       |       |  ,-------.
   *                            |S Ctl A|  `-------'       `-------'  |E AGr B|
   *                            |f     l|                             |n     s|
   *                            |t SYM t|                             |t SPC p|
   *                            `-------'                             `-------'
   */
  [_QTY] = KEYMAP
  (
                         Key_E                                                   ,Key_I
                 ,Key_W        ,Key_R ,Key_T                       ,Key_Y ,Key_U        ,Key_O
          ,Key_A        ,Key_D                                                   ,Key_K        ,Key_P
   ,Key_Q        ,Key_S        ,Key_F ,Key_G                       ,Key_H ,Key_J        ,Key_L            ,Key_Period
          ,Key_Z        ,Key_C                                                   ,Key_N        ,Key_Comma
                 ,Key_X        ,Key_V                                     ,Key_B        ,Key_M

                        ,MO(_ETY)                                   ,Key_Tab
           ,Key_NoKey                ,Key_NoKey            ,Key_Tab          ,Key_Tab
                        ,TG(_GAM)                                   ,Key_Tab

                 ,Key_LCtrl                                               ,Key_RAlt
     ,Key_LShift               ,Key_LAlt                       ,Key_Enter           ,Key_Backspace
                 ,MO(_SYM)                                                ,Key_Space
  ),

  /* 1 - Numbers, navigation & symbol layer
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

  /* 2 - Gaming layer
   *
   *                   ,-----.                                                   ,-----.
   *             ,-----+     +-----------.                           ,-----------|     |-----.
   *       ,-----|  W  |-----| Ent |     |                           | Alt |     |-----|     |-----.
   * ,-----|  A  |-----|  D  |-----+-----|                           |-----+-----| RCk |-----|     |-----.
   * | Esc |-----|  S  |-----| Spc |     |                           | Ctl | LCk |-----|     |-----|     |
   * `-----|     |-----|     |-----+-----'                           `-----+-----|     |-----| End |-----'
   *       `-----|     |-----| Sft |       ,-------.       ,-------.       |     |-----| Home|-----'
   *             `-----'     `-----'       |  ETY  |       |       |       `-----'     `-----'
   *                                       |       |       |       |
   *                            ,-------.  |  QTY  |       |       |  ,-------.
   *                            |M MA+ M|  `-------'       `-------'  |M MUp M|
   *                            |S     S|                             |L     R|
   *                            |+ MA- -|                             |t MDn g|
   *                            `-------'                             `-------'
   */
  [_GAM] = KEYMAP
  (
                         XXX                                                              ,XXX
                 ,Key_W        ,Key_Enter ,XXX                         ,Key_LAlt   ,XXX          ,XXX
          ,Key_A        ,Key_D                                                            ,Key_MBtnR    ,XXX
   ,Key_Esc      ,Key_S        ,Key_Space ,XXX                         ,Key_LCtrl  ,Key_MBtnL    ,XXX            ,XXX
          ,XXX          ,XXX                                                              ,XXX          ,Key_End
                 ,XXX          ,Key_LShift                                         ,XXX          ,Key_Home

                        ,___                                           ,XXX
           ,___                      ,___                     ,XXX               ,XXX
                        ,___                                           ,XXX

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
   ,XXX          ,XXX          ,XXX   ,XXX                         ,XXX   ,XXX          ,XXX              ,XXX
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

  Keyboardio.setup (KEYMAP_SIZE);
  Keyboardio.use (&Hungarian, NULL);

  algernon::MouseKeys::configure ();
  algernon::OneShot::configure ();
  algernon::MagicCombo::configure ();
  algernon::Macros::configure ();

  Layer.on (_GAM);
}

void loop () {
  Keyboardio.loop ();
}
