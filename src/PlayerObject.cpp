#include "Macros.hpp"
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
    void setupStreak() {
        // thanks alphalaneous for the fucking genius code
        // theres no way i dont copy this
        auto GM = GameManager::get();
        int origStreak = GM->m_playerStreak;
        int origShipStreak = GM->m_playerShipFire;
        bool origGlow = GM->m_playerGlow;

        if (this->isPlayer2()) {
            GM->m_playerStreak = GDI_GET_VALUE(int64_t, "trail", 1);
            GM->m_playerShipFire = GDI_GET_VALUE(int64_t, "shiptrail", 1);
            GM->m_playerGlow = GDI_GET_VALUE(bool, "glow", false);
        }

        PlayerObject::setupStreak();

        GM->m_playerStreak = origStreak;
        GM->m_playerShipFire = origShipStreak;
        GM->m_playerGlow = origGlow;
    }

    bool isPlayer2() {
        return isPlayer2(m_gameLayer);
    }

    bool isPlayer2(GJBaseGameLayer* gameLayer) {
        return gameLayer && ((gameLayer->m_player1 && !gameLayer->m_player2 && this != gameLayer->m_player1) || this == gameLayer->m_player2);
    }

    void playDeathEffect() {
        auto GM = GameManager::get();
        int origDeath = GM->m_playerDeathEffect;
        bool orgDeathExplode = GM->getGameVariable("0153");

        if (this->isPlayer2()) {
            GM->m_playerDeathEffect = GDI_GET_VALUE(int64_t, "death", 1);
            GM->setGameVariable("0153", GDI_GET_VALUE(bool, "deathexplode", false));
        }

        PlayerObject::playDeathEffect();

        GM->m_playerDeathEffect = origDeath;
        GM->setGameVariable("0153", orgDeathExplode);
    }

    bool init(int player, int ship, GJBaseGameLayer* gameLayer, CCLayer* layer, bool playLayer) {
        return PlayerObject::init(
            this->isPlayer2(gameLayer) ? GDI_GET_VALUE(int64_t, "cube", 1) : player,
            this->isPlayer2(gameLayer) ? GDI_GET_VALUE(int64_t, "ship", 1) : ship,
            gameLayer,
            layer,
            playLayer
        );
    }

    void setColor(ccColor3B const &color) {
        PlayerObject::setColor(this->isPlayer2() ? GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)) : color);
    }

    void setSecondColor(ccColor3B const &color) {
        PlayerObject::setSecondColor(this->isPlayer2() ? GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)) : color);
    }

    void updatePlayerFrame(int p0) {
        PlayerObject::updatePlayerFrame(p0 != 0 && this->isPlayer2() ? GDI_GET_VALUE(int64_t, "cube", 1) : p0);
    }

    void updatePlayerShipFrame(int p0) {
        PlayerObject::updatePlayerShipFrame(p0 != 0 && this->isPlayer2() ? GDI_GET_VALUE(int64_t, "ship", 1) : p0);
    }

    void updatePlayerRollFrame(int p0) {
        PlayerObject::updatePlayerRollFrame(p0 != 0 && this->isPlayer2() ? GDI_GET_VALUE(int64_t, "roll", 1) : p0);
    }

    void updatePlayerBirdFrame(int p0) {
        PlayerObject::updatePlayerBirdFrame(p0 != 0 && this->isPlayer2() ? GDI_GET_VALUE(int64_t, "bird", 1) : p0);
    }

    void updatePlayerDartFrame(int p0) {
        PlayerObject::updatePlayerDartFrame(p0 != 0 && this->isPlayer2() ? GDI_GET_VALUE(int64_t, "dart", 1) : p0);
    }

    void createRobot(int p0) {
        PlayerObject::createRobot(p0 != 0 && this->isPlayer2() ? GDI_GET_VALUE(int64_t, "robot", 1) : p0);
    }

    void createSpider(int p0) {
        PlayerObject::createSpider(p0 != 0 && this->isPlayer2() ? GDI_GET_VALUE(int64_t, "spider", 1) : p0);
    }

    void updatePlayerSwingFrame(int p0) {
        PlayerObject::updatePlayerSwingFrame(p0 != 0 && this->isPlayer2() ? GDI_GET_VALUE(int64_t, "swing", 1) : p0);
    }

    void updatePlayerJetpackFrame(int p0) {
        PlayerObject::updatePlayerJetpackFrame(p0 != 0 && this->isPlayer2() ? GDI_GET_VALUE(int64_t, "jetpack", 1) : p0);
    }

    void updateGlowColor() {
        if (this->isPlayer2()) {
            enableCustomGlowColor(GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
        }
        PlayerObject::updateGlowColor();
    }
};