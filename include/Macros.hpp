#pragma once

#define SDI_GET_VALUE(type, id, default) Mod::get()->getSavedValue<type>(id, default)
#define SDI_SET_VALUE(type, id, value) Mod::get()->setSavedValue<type>(id, value)

#define RESOLVE_VALUE(org, val1, val2) !m_gameLayer ? org : isPlayer1() ? val1 : isPlayer2() ? val2 : org