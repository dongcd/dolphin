// Copyright 2015 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <array>
#include <string>

#include "InputCommon/ControllerEmu.h"
#include "InputCommon/InputConfig.h"

enum Hotkey
{
  HK_OPEN,
  HK_CHANGE_DISC,
  HK_REFRESH_LIST,
  HK_PLAY_PAUSE,
  HK_STOP,
  HK_RESET,
  HK_FULLSCREEN,
  HK_SCREENSHOT,
  HK_EXIT,

  HK_VOLUME_DOWN,
  HK_VOLUME_UP,
  HK_VOLUME_TOGGLE_MUTE,

  HK_DECREASE_EMULATION_SPEED,
  HK_INCREASE_EMULATION_SPEED,
  HK_TOGGLE_THROTTLE,

  HK_FRAME_ADVANCE,
  HK_FRAME_ADVANCE_DECREASE_SPEED,
  HK_FRAME_ADVANCE_INCREASE_SPEED,
  HK_FRAME_ADVANCE_RESET_SPEED,

  HK_START_RECORDING,
  HK_PLAY_RECORDING,
  HK_EXPORT_RECORDING,
  HK_READ_ONLY_MODE,

  HK_TRIGGER_SYNC_BUTTON,
  HK_WIIMOTE1_CONNECT,
  HK_WIIMOTE2_CONNECT,
  HK_WIIMOTE3_CONNECT,
  HK_WIIMOTE4_CONNECT,
  HK_BALANCEBOARD_CONNECT,

  HK_TOGGLE_CROP,
  HK_TOGGLE_AR,
  HK_TOGGLE_EFBCOPIES,
  HK_TOGGLE_FOG,
  HK_TOGGLE_TEXTURES,

  HK_INCREASE_IR,
  HK_DECREASE_IR,

  HK_FREELOOK_DECREASE_SPEED,
  HK_FREELOOK_INCREASE_SPEED,
  HK_FREELOOK_RESET_SPEED,
  HK_FREELOOK_UP,
  HK_FREELOOK_DOWN,
  HK_FREELOOK_LEFT,
  HK_FREELOOK_RIGHT,
  HK_FREELOOK_ZOOM_IN,
  HK_FREELOOK_ZOOM_OUT,
  HK_FREELOOK_RESET,

  HK_TOGGLE_STEREO_SBS,
  HK_TOGGLE_STEREO_TAB,
  HK_TOGGLE_STEREO_ANAGLYPH,
  HK_TOGGLE_STEREO_3DVISION,

  HK_DECREASE_DEPTH,
  HK_INCREASE_DEPTH,
  HK_DECREASE_CONVERGENCE,
  HK_INCREASE_CONVERGENCE,

  HK_LOAD_STATE_SLOT_1,
  HK_LOAD_STATE_SLOT_2,
  HK_LOAD_STATE_SLOT_3,
  HK_LOAD_STATE_SLOT_4,
  HK_LOAD_STATE_SLOT_5,
  HK_LOAD_STATE_SLOT_6,
  HK_LOAD_STATE_SLOT_7,
  HK_LOAD_STATE_SLOT_8,
  HK_LOAD_STATE_SLOT_9,
  HK_LOAD_STATE_SLOT_10,
  HK_LOAD_STATE_SLOT_SELECTED,

  HK_SAVE_STATE_SLOT_1,
  HK_SAVE_STATE_SLOT_2,
  HK_SAVE_STATE_SLOT_3,
  HK_SAVE_STATE_SLOT_4,
  HK_SAVE_STATE_SLOT_5,
  HK_SAVE_STATE_SLOT_6,
  HK_SAVE_STATE_SLOT_7,
  HK_SAVE_STATE_SLOT_8,
  HK_SAVE_STATE_SLOT_9,
  HK_SAVE_STATE_SLOT_10,
  HK_SAVE_STATE_SLOT_SELECTED,

  HK_SELECT_STATE_SLOT_1,
  HK_SELECT_STATE_SLOT_2,
  HK_SELECT_STATE_SLOT_3,
  HK_SELECT_STATE_SLOT_4,
  HK_SELECT_STATE_SLOT_5,
  HK_SELECT_STATE_SLOT_6,
  HK_SELECT_STATE_SLOT_7,
  HK_SELECT_STATE_SLOT_8,
  HK_SELECT_STATE_SLOT_9,
  HK_SELECT_STATE_SLOT_10,

  HK_LOAD_LAST_STATE_1,
  HK_LOAD_LAST_STATE_2,
  HK_LOAD_LAST_STATE_3,
  HK_LOAD_LAST_STATE_4,
  HK_LOAD_LAST_STATE_5,
  HK_LOAD_LAST_STATE_6,
  HK_LOAD_LAST_STATE_7,
  HK_LOAD_LAST_STATE_8,
  HK_LOAD_LAST_STATE_9,
  HK_LOAD_LAST_STATE_10,

  HK_SAVE_FIRST_STATE,
  HK_UNDO_LOAD_STATE,
  HK_UNDO_SAVE_STATE,
  HK_SAVE_STATE_FILE,
  HK_LOAD_STATE_FILE,

  NUM_HOTKEYS,
};

enum HotkeyGroup : int
{
  HKGP_GENERAL,
  HKGP_VOLUME,
  HKGP_SPEED,
  HKGP_FRAME_ADVANCE,
  HKGP_MOVIE,
  HKGP_WII,
  HKGP_GRAPHICS_TOGGLES,
  HKGP_IR,
  HKGP_FREELOOK,
  HKGP_3D_TOGGLE,
  HKGP_3D_DEPTH,
  HKGP_LOAD_STATE,
  HKGP_SAVE_STATE,
  HKGP_SELECT_STATE,
  HKGP_LOAD_LAST_STATE,
  HKGP_STATE_MISC,

  NUM_HOTKEY_GROUPS,
};

struct HotkeyGroupInfo
{
  std::string name;
  Hotkey first;
  Hotkey last;
};

struct HotkeyStatus
{
  u32 button[NUM_HOTKEY_GROUPS];
  s8 err;
};

class HotkeyManager : public ControllerEmu
{
public:
  HotkeyManager();
  ~HotkeyManager();

  void GetInput(HotkeyStatus* const hk);
  std::string GetName() const override;
  ControlGroup* GetHotkeyGroup(HotkeyGroup group) const;
  ControlGroup* GetOptionsGroup() const;
  int FindGroupByID(int id) const;
  int GetIndexForGroup(int group, int id) const;
  void LoadDefaults(const ControllerInterface& ciface) override;

private:
  Buttons* m_keys[NUM_HOTKEY_GROUPS];
  std::array<ControlGroup*, NUM_HOTKEY_GROUPS> m_hotkey_groups;
  ControlGroup* m_options;
};

namespace HotkeyManagerEmu
{
void Initialize();
void Shutdown();
void LoadConfig();

InputConfig* GetConfig();
ControllerEmu::ControlGroup* GetHotkeyGroup(HotkeyGroup group);
ControllerEmu::ControlGroup* GetOptionsGroup();
void GetStatus();
bool IsEnabled();
void Enable(bool enable_toggle);
bool IsPressed(int Id, bool held);
}
