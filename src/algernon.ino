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

#include "00-config.h"

#include "Kaleidoscope.h"
#include "Kaleidoscope-Focus.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"

#include "ActiveLayerColor.h"
#include "Layers.h"
#include "OneShot.h"

#define Key_LSBrck Key_LeftBracket
#define Key_RSBrck Key_RightBracket
#define Key_MBtnL  Key_mouseBtnL
#define Key_MBtnR  Key_mouseBtnR

#define Key_LShift Key_LeftShift
#define Key_LArrow Key_LeftArrow
#define Key_RArrow Key_RightArrow
#define Key_DnArrow Key_DownArrow
#define Key_LCtrl Key_LeftControl
#define Key_LAlt Key_LeftAlt
#define Key_Space Key_Spacebar
#define Key_RShift Key_RightShift
#define Key_RAlt Key_RightAlt
#define Key_Esc Key_Escape
#define Key_RCtrl Key_RightControl

#define TG(layer) (Key){ layer, KEY_FLAGS | SYNTHETIC | SWITCH_TO_KEYMAP }

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
   *             `-----'     `-----'       |M MUp M|       |L     R|       `-----'     `-----'
   *                                       |L     R|       |C Tab C|
   *                            ,-------.  |t Mdn t|       |k     k|  ,-------.
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

                        ,Key_mouseUp                                ,Key_Tab
           ,Key_mouseL               ,Key_mouseR           ,Key_mouseBtnL    ,Key_mouseBtnR
                        ,Key_mouseDn                                ,Key_Tab

                 ,OSM(LCtrl)                                              ,OSM(RAlt)
    ,OSM(LShift)             ,OSM(LAlt)                        ,Key_Enter            ,Key_Backspace
                 ,OSL(_SYM)                                               ,Key_Space
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
   *             `-----'     `-----'       |L MUp R|       |M MUp M|       `-----'     `-----'
   *                                       |C     C|       |L     R|
   *                            ,-------.  |k Mdn k|       |t MDn g|  ,-------.
   *                            |S Ctl A|  `-------'       `-------'  |S AGr D|
   *                            |f     l|                             |f     e|
   *                            |t DVK t|                             |t Cnt l|
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

                 ,___                                                        ,OSM(RAlt)
     ,___                     ,___                               ,Key_RShift          ,Key_Delete
                 ,___                                                        ,OSM(RCtrl)
   ),
};

void setup () {
  Serial.begin(9600);

  Kaleidoscope.setup ();
  Kaleidoscope.use (&EEPROMSettings, &EEPROMKeymap,
                    &LEDControl, &MouseKeys);

  EEPROMKeymap.max_layers (LAYER_MAX);

  algernon::ActiveLayerColor::configure ();
  algernon::OneShot::configure ();

  Layer.on (_DVK);

  Layer.getKey = EEPROMKeymap.getKeyOverride;

  LEDControl.syncDelay = 64;

  Kaleidoscope.use (&Focus);

  Focus.addHook (FOCUS_HOOK_HELP);
  Focus.addHook (FOCUS_HOOK_VERSION);
  Focus.addHook (FOCUS_HOOK_KEYMAP);
  Focus.addHook (FOCUS_HOOK_KEYMAP_TRANSFER);
  Focus.addHook (FOCUS_HOOK_EEPROM);
  Focus.addHook (FOCUS_HOOK_KALEIDOSCOPE);
  Focus.addHook (FOCUS_HOOK_LEDCONTROL);
  Focus.addHook (FOCUS_HOOK_SETTINGS);

  EEPROMSettings.seal ();

  if (!EEPROMSettings.isValid ()) {
    EEPROMSettings.version (0);
    EEPROMSettings.update ();
  }
}

#if WITH_CYCLE_REPORT
static unsigned long avgLoopTime = 0;
static unsigned long nextReport = millis() + 1000;
#endif

void loop () {
#if WITH_CYCLE_REPORT
  unsigned long loopStart = micros ();
#endif

  Kaleidoscope.loop();

#if WITH_CYCLE_REPORT
  unsigned long loopTime = micros () - loopStart;

  if (avgLoopTime)
    avgLoopTime = (avgLoopTime + loopTime) / 2;
  else
    avgLoopTime = loopTime;

  if (millis () >= nextReport) {
    Serial.print (F("avgLoopTime: "));
    Serial.println (avgLoopTime);
    nextReport = millis() + 1000;
  }
#endif
}
