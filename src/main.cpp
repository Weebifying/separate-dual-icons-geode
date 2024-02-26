#include "PlayerData.hpp"
#include <Geode/loader/SettingEvent.hpp>

$on_mod(Loaded) {
    PlayerData::player2Cube = Mod::get()->getSettingValue<int64_t>("cube");
    PlayerData::player2Ship = Mod::get()->getSettingValue<int64_t>("ship");
    PlayerData::player2Roll = Mod::get()->getSettingValue<int64_t>("roll");
    PlayerData::player2Bird = Mod::get()->getSettingValue<int64_t>("bird");
    PlayerData::player2Dart = Mod::get()->getSettingValue<int64_t>("dart");
    PlayerData::player2Robot = Mod::get()->getSettingValue<int64_t>("robot");
    PlayerData::player2Spider = Mod::get()->getSettingValue<int64_t>("spider");
    PlayerData::player2Swing = Mod::get()->getSettingValue<int64_t>("swing");
    PlayerData::player2Jetpack = Mod::get()->getSettingValue<int64_t>("jetpack");

    PlayerData::player2Color1 = Mod::get()->getSettingValue<int64_t>("color1");
    PlayerData::player2Color2 = Mod::get()->getSettingValue<int64_t>("color2");
    PlayerData::player2ColorGlow = Mod::get()->getSettingValue<int64_t>("colorglow");
    PlayerData::player2Glow = Mod::get()->getSettingValue<bool>("glow");

    PlayerData::player2Trail = Mod::get()->getSettingValue<int64_t>("trail");
    PlayerData::player2Death = Mod::get()->getSettingValue<int64_t>("death");
    PlayerData::player2ShipTrail = Mod::get()->getSettingValue<int64_t>("shiptrail");
}

$execute {
    listenForSettingChanges("cube", +[](int64_t value) { PlayerData::player2Cube = value; });
    listenForSettingChanges("ship", +[](int64_t value) { PlayerData::player2Ship = value; });
    listenForSettingChanges("roll", +[](int64_t value) { PlayerData::player2Roll = value; });
    listenForSettingChanges("bird", +[](int64_t value) { PlayerData::player2Bird = value; });
    listenForSettingChanges("dart", +[](int64_t value) { PlayerData::player2Dart = value; });
    listenForSettingChanges("robot", +[](int64_t value) { PlayerData::player2Robot = value; });
    listenForSettingChanges("spider", +[](int64_t value) { PlayerData::player2Spider = value; });
    listenForSettingChanges("swing", +[](int64_t value) { PlayerData::player2Swing = value; });
    listenForSettingChanges("jetpack", +[](int64_t value) { PlayerData::player2Jetpack = value; });
    
    listenForSettingChanges("color1", +[](int64_t value) { PlayerData::player2Color1 = value; });
    listenForSettingChanges("color2", +[](int64_t value) { PlayerData::player2Color2 = value; });
    listenForSettingChanges("colorglow", +[](int64_t value) { PlayerData::player2ColorGlow = value; });
    listenForSettingChanges("glow", +[](bool value) { PlayerData::player2Glow = value; });

    listenForSettingChanges("trail", +[](int64_t value) { PlayerData::player2Trail = value; });
    listenForSettingChanges("death", +[](int64_t value) { PlayerData::player2Death = value; });
    listenForSettingChanges("shiptrail", +[](int64_t value) { PlayerData::player2ShipTrail = value; });
}