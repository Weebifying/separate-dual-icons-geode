#include "PlayerData.hpp"
#include <Geode/loader/SettingEvent.hpp>

$on_mod(Loaded) {
    PlayerData::player2Cube = Mod::get()->getSavedValue<int64_t>("cube", 1);
    PlayerData::player2Ship = Mod::get()->getSavedValue<int64_t>("ship", 1);
    PlayerData::player2Roll = Mod::get()->getSavedValue<int64_t>("roll", 1);
    PlayerData::player2Bird = Mod::get()->getSavedValue<int64_t>("bird", 1);
    PlayerData::player2Dart = Mod::get()->getSavedValue<int64_t>("dart", 1);
    PlayerData::player2Robot = Mod::get()->getSavedValue<int64_t>("robot", 1);
    PlayerData::player2Spider = Mod::get()->getSavedValue<int64_t>("spider", 1);
    PlayerData::player2Swing = Mod::get()->getSavedValue<int64_t>("swing", 1);
    PlayerData::player2Jetpack = Mod::get()->getSavedValue<int64_t>("jetpack", 1);

    PlayerData::player2Color1 = Mod::get()->getSavedValue<int64_t>("color1", 0);
    PlayerData::player2Color2 = Mod::get()->getSavedValue<int64_t>("color2", 0);
    PlayerData::player2ColorGlow = Mod::get()->getSavedValue<int64_t>("colorglow", 0);
    PlayerData::player2Glow = Mod::get()->getSavedValue<bool>("glow", false);

    PlayerData::player2Trail = Mod::get()->getSavedValue<int64_t>("trail", 1);
    PlayerData::player2Death = Mod::get()->getSavedValue<int64_t>("death", 1);
    PlayerData::player2ShipTrail = Mod::get()->getSavedValue<int64_t>("shiptrail", 1);
    PlayerData::lastType = Mod::get()->getSavedValue<int64_t>("lasttype", 1);
}