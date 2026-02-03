#include "SDIHelper.hpp"

SDIHelper* SDIHelper::get() {
    static SDIHelper instance;
    return &instance;
}

void SDIHelper::reset() {
    auto GM = GameManager::get();    
    
    m_isP2Main = false;
    m_shouldSwap = true;
}

void SDIHelper::swapAll() {
    m_isP2Main = !m_isP2Main;
}

int SDIHelper::getCube(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "cube", 1)
        : GameManager::get()->getPlayerFrame();
}

int SDIHelper::getShip(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "ship", 1)
        : GameManager::get()->getPlayerShip();
}

int SDIHelper::getBall(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "roll", 1)
        : GameManager::get()->getPlayerBall();
}

int SDIHelper::getUFO(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "bird", 1)
        : GameManager::get()->getPlayerBird();
}

int SDIHelper::getWave(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "dart", 1)
        : GameManager::get()->getPlayerDart();
}

int SDIHelper::getRobot(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "robot", 1)
        : GameManager::get()->getPlayerRobot();
}

int SDIHelper::getSpider(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "spider", 1)
        : GameManager::get()->getPlayerSpider();
}

int SDIHelper::getSwing(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "swing", 1)
        : GameManager::get()->getPlayerSwing();
}

int SDIHelper::getJetpack(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "jetpack", 1)
        : GameManager::get()->getPlayerJetpack();
}

int SDIHelper::getTrail(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "trail", 1)
        : GameManager::get()->getPlayerStreak();
}

int SDIHelper::getShipTrail(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "shiptrail", 1)
        : GameManager::get()->getPlayerShipFire();
}

int SDIHelper::getDeathEffect(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "death", 1)
        : GameManager::get()->getPlayerDeathEffect();
}

bool SDIHelper::getDeathExplode(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(bool, "deathexplode", false)
        : GameManager::get()->getGameVariable("0153");
}

int SDIHelper::getColor1(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "color1", 0)
        : GameManager::get()->getPlayerColor();
}

int SDIHelper::getColor2(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "color2", 0)
        : GameManager::get()->getPlayerColor2();
}

bool SDIHelper::getGlow(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(bool, "glow", false)
        : GameManager::get()->getPlayerGlow();
}

int SDIHelper::getGlowColor(bool isP2) {
    return m_isP2Main != isP2
        ? GDI_GET_VALUE(int64_t, "colorglow", 0)
        : GameManager::get()->getPlayerGlowColor();
}

void SDIHelper::logAll() {
    log::info("isP2Main: {}", m_isP2Main);
}

$on_mod(Loaded) {
    SDIHelper::get()->reset();
};