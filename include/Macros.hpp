#pragma once

#define GDI_GET_VALUE(type, id, default) Mod::get()->getSavedValue<type>(id, default)
#define GDI_SET_VALUE(type, id, value) Mod::get()->setSavedValue<type>(id, value)