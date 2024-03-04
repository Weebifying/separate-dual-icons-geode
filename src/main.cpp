#include "PlayerData.hpp"
#include <Geode/loader/SettingEvent.hpp>

$on_mod(Loaded) {
    gd::string types[] = {"cube", "ship", "roll", "bird", "dart", "robot", "spider", "swing", "jetpack", "trail", "death", "shiptrail"};
    for (auto t : types) 
        if (!Mod::get()->getSavedValue<int64_t>(t)) 
            Mod::get()->setSavedValue<int64_t>(t, 1);

    gd::string colorTypes[] = {"color1", "color2", "colorglow"};
    for (auto t : types) 
        if (!Mod::get()->getSavedValue<int64_t>(t)) 
            Mod::get()->setSavedValue<int64_t>(t, 0);

    PlayerData::player2Cube = Mod::get()->getSavedValue<int64_t>("cube");
    PlayerData::player2Ship = Mod::get()->getSavedValue<int64_t>("ship");
    PlayerData::player2Roll = Mod::get()->getSavedValue<int64_t>("roll");
    PlayerData::player2Bird = Mod::get()->getSavedValue<int64_t>("bird");
    PlayerData::player2Dart = Mod::get()->getSavedValue<int64_t>("dart");
    PlayerData::player2Robot = Mod::get()->getSavedValue<int64_t>("robot");
    PlayerData::player2Spider = Mod::get()->getSavedValue<int64_t>("spider");
    PlayerData::player2Swing = Mod::get()->getSavedValue<int64_t>("swing");
    PlayerData::player2Jetpack = Mod::get()->getSavedValue<int64_t>("jetpack");

    PlayerData::player2Color1 = Mod::get()->getSavedValue<int64_t>("color1");
    PlayerData::player2Color2 = Mod::get()->getSavedValue<int64_t>("color2");
    PlayerData::player2ColorGlow = Mod::get()->getSavedValue<int64_t>("colorglow");
    PlayerData::player2Glow = Mod::get()->getSavedValue<bool>("glow");

    PlayerData::player2Trail = Mod::get()->getSavedValue<int64_t>("trail");
    PlayerData::player2Death = Mod::get()->getSavedValue<int64_t>("death");
    PlayerData::player2ShipTrail = Mod::get()->getSavedValue<int64_t>("shiptrail");
    PlayerData::lastType = Mod::get()->getSavedValue<int64_t>("lasttype");
}