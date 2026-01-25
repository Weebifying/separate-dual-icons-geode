#include "SDIHelper.hpp"

SDIHelper* SDIHelper::get() {
    static SDIHelper instance;
    return &instance;
}

void SDIHelper::reset() {
    auto GM = GameManager::get();    
    
    m_isP2Main = false;

    m_p1Cube = GM->getPlayerFrame();
    m_p1Ship = GM->getPlayerShip();
    m_p1Ball = GM->getPlayerBall();
    m_p1UFO = GM->getPlayerBird();
    m_p1Wave = GM->getPlayerDart();
    m_p1Robot = GM->getPlayerRobot();
    m_p1Spider = GM->getPlayerSpider();
    m_p1Swing = GM->getPlayerSwing();
    m_p1Jetpack = GM->getPlayerJetpack();
    m_p1Trail = GM->getPlayerStreak();
    m_p1ShipTrail = GM->getPlayerShipFire();
    m_p1DeathEffect = GM->getPlayerDeathEffect();
    m_p1DeathExplode = GM->getGameVariable("0153");
    m_p1Color1 = GM->getPlayerColor();
    m_p1Color2 = GM->getPlayerColor2();
    m_p1Glow = GM->getPlayerGlow();
    m_p1GlowColor = GM->getPlayerGlowColor();

    m_p2Cube = GDI_GET_VALUE(int64_t, "cube", 1);
    m_p2Ship = GDI_GET_VALUE(int64_t, "ship", 1);
    m_p2Ball = GDI_GET_VALUE(int64_t, "roll", 1);
    m_p2UFO = GDI_GET_VALUE(int64_t, "bird", 1);
    m_p2Wave = GDI_GET_VALUE(int64_t, "dart", 1);
    m_p2Robot = GDI_GET_VALUE(int64_t, "robot", 1);
    m_p2Spider = GDI_GET_VALUE(int64_t, "spider", 1);
    m_p2Swing = GDI_GET_VALUE(int64_t, "swing", 1);
    m_p2Jetpack = GDI_GET_VALUE(int64_t, "jetpack", 1);
    m_p2Trail = GDI_GET_VALUE(int64_t, "trail", 1);
    m_p2ShipTrail = GDI_GET_VALUE(int64_t, "shiptrail", 1);
    m_p2DeathEffect = GDI_GET_VALUE(int64_t, "death", 1);
    m_p2DeathExplode = GDI_GET_VALUE(bool, "deathexplode", false);
    m_p2Color1 = GDI_GET_VALUE(int64_t, "color1", 0);
    m_p2Color2 = GDI_GET_VALUE(int64_t, "color2", 0);
    m_p2Glow = GDI_GET_VALUE(bool, "glow", false);
    m_p2GlowColor = GDI_GET_VALUE(int64_t, "colorglow", 0);
}

void SDIHelper::swapAll() {
    int oldP1Cube = m_p1Cube;
    int oldP1Ship = m_p1Ship;
    int oldP1Ball = m_p1Ball;
    int oldP1UFO = m_p1UFO;
    int oldP1Wave = m_p1Wave;
    int oldP1Robot = m_p1Robot;
    int oldP1Spider = m_p1Spider;
    int oldP1Swing = m_p1Swing;
    int oldP1Jetpack = m_p1Jetpack;
    int oldP1Trail = m_p1Trail;
    int oldP1ShipTrail = m_p1ShipTrail;
    int oldP1DeathEffect = m_p1DeathEffect;
    bool oldP1DeathExplode = m_p1DeathExplode;
    int oldP1Color1 = m_p1Color1;
    int oldP1Color2 = m_p1Color2;
    bool oldP1Glow = m_p1Glow;
    int oldP1GlowColor = m_p1GlowColor;

    m_p1Cube = m_p2Cube;
    m_p1Ship = m_p2Ship;
    m_p1Ball = m_p2Ball;
    m_p1UFO = m_p2UFO;
    m_p1Wave = m_p2Wave;
    m_p1Robot = m_p2Robot;
    m_p1Spider = m_p2Spider;
    m_p1Swing = m_p2Swing;
    m_p1Jetpack = m_p2Jetpack;
    m_p1Trail = m_p2Trail;
    m_p1ShipTrail = m_p2ShipTrail;
    m_p1DeathEffect = m_p2DeathEffect;
    m_p1DeathExplode = m_p2DeathExplode;
    m_p1Color1 = m_p2Color1;
    m_p1Color2 = m_p2Color2;
    m_p1Glow = m_p2Glow;
    m_p1GlowColor = m_p2GlowColor;

    m_p2Cube = oldP1Cube;
    m_p2Ship = oldP1Ship;
    m_p2Ball = oldP1Ball;
    m_p2UFO = oldP1UFO;
    m_p2Wave = oldP1Wave;
    m_p2Robot = oldP1Robot;
    m_p2Spider = oldP1Spider;
    m_p2Swing = oldP1Swing;
    m_p2Jetpack = oldP1Jetpack;
    m_p2Trail = oldP1Trail;
    m_p2ShipTrail = oldP1ShipTrail;
    m_p2DeathEffect = oldP1DeathEffect;
    m_p2DeathExplode = oldP1DeathExplode;
    m_p2Color1 = oldP1Color1;
    m_p2Color2 = oldP1Color2;
    m_p2Glow = oldP1Glow;
    m_p2GlowColor = oldP1GlowColor;
}

int SDIHelper::getCube(bool isP2) { 
    return isP2 ? m_p2Cube : m_p1Cube;
}
int SDIHelper::getShip(bool isP2) {
    return isP2 ? m_p2Ship : m_p1Ship;
}
int SDIHelper::getBall(bool isP2) {
    return isP2 ? m_p2Ball : m_p1Ball;
}
int SDIHelper::getUFO(bool isP2) {
    return isP2 ? m_p2UFO : m_p1UFO;
}
int SDIHelper::getWave(bool isP2) {
    return isP2 ? m_p2Wave : m_p1Wave;
}
int SDIHelper::getRobot(bool isP2) {
    return isP2 ? m_p2Robot : m_p1Robot;
}
int SDIHelper::getSpider(bool isP2) {
    return isP2 ? m_p2Spider : m_p1Spider;
}
int SDIHelper::getSwing(bool isP2) {
    return isP2 ? m_p2Swing : m_p1Swing;
}
int SDIHelper::getJetpack(bool isP2) {
    return isP2 ? m_p2Jetpack : m_p1Jetpack;
}
int SDIHelper::getTrail(bool isP2) {
    return isP2 ? m_p2Trail : m_p1Trail;
}
int SDIHelper::getShipTrail(bool isP2) {
    return isP2 ? m_p2ShipTrail : m_p1ShipTrail;
}
int SDIHelper::getDeathEffect(bool isP2) {
    return isP2 ? m_p2DeathEffect : m_p1DeathEffect;
}
bool SDIHelper::getDeathExplode(bool isP2) {
    return isP2 ? m_p2DeathExplode : m_p1DeathExplode;
}
int SDIHelper::getColor1(bool isP2) {
    return isP2 ? m_p2Color1 : m_p1Color1;
}
int SDIHelper::getColor2(bool isP2) {
    return isP2 ? m_p2Color2 : m_p1Color2;
}
bool SDIHelper::getGlow(bool isP2) {
    return isP2 ? m_p2Glow : m_p1Glow;
}
int SDIHelper::getGlowColor(bool isP2) {
    return isP2 ? m_p2GlowColor : m_p1GlowColor;
}

void SDIHelper::logAll() {
    log::info("m_isP2Main: {}", m_isP2Main);
    log::info("m_p1Cube: {}", m_p1Cube);
    log::info("m_p1Ship: {}", m_p1Ship);
    log::info("m_p1Ball: {}", m_p1Ball);
    log::info("m_p1UFO: {}", m_p1UFO);
    log::info("m_p1Wave: {}", m_p1Wave);
    log::info("m_p1Robot: {}", m_p1Robot);
    log::info("m_p1Spider: {}", m_p1Spider);
    log::info("m_p1Swing: {}", m_p1Swing);
    log::info("m_p1Jetpack: {}", m_p1Jetpack);
    log::info("m_p1Trail: {}", m_p1Trail);
    log::info("m_p1ShipTrail: {}", m_p1ShipTrail);
    log::info("m_p1DeathEffect: {}", m_p1DeathEffect);
    log::info("m_p1DeathExplode: {}", m_p1DeathExplode);
    log::info("m_p1Color1: {}", m_p1Color1);
    log::info("m_p1Color2: {}", m_p1Color2);
    log::info("m_p1Glow: {}", m_p1Glow);
    log::info("m_p1GlowColor: {}", m_p1GlowColor);
    log::info("m_p2Cube: {}", m_p2Cube);
    log::info("m_p2Ship: {}", m_p2Ship);
    log::info("m_p2Ball: {}", m_p2Ball);
    log::info("m_p2UFO: {}", m_p2UFO);
    log::info("m_p2Wave: {}", m_p2Wave);
    log::info("m_p2Robot: {}", m_p2Robot);
    log::info("m_p2Spider: {}", m_p2Spider);
    log::info("m_p2Swing: {}", m_p2Swing);
    log::info("m_p2Jetpack: {}", m_p2Jetpack);
    log::info("m_p2Trail: {}", m_p2Trail);
    log::info("m_p2ShipTrail: {}", m_p2ShipTrail);
    log::info("m_p2DeathEffect: {}", m_p2DeathEffect);
    log::info("m_p2DeathExplode: {}", m_p2DeathExplode);
    log::info("m_p2Color1: {}", m_p2Color1);
    log::info("m_p2Color2: {}", m_p2Color2);
    log::info("m_p2Glow: {}", m_p2Glow);
    log::info("m_p2GlowColor: {}", m_p2GlowColor);
}

$on_mod(Loaded) {
    SDIHelper::get()->reset();
};