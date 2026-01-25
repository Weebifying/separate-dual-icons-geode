#include "Macros.hpp"
#include "SDIHelper.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
    bool isPlayer2() {
        return isPlayer2(m_gameLayer);
    }

    bool isPlayer2(GJBaseGameLayer* gameLayer) {
        return gameLayer && ((gameLayer->m_player1 && !gameLayer->m_player2 && this != gameLayer->m_player1) || this == gameLayer->m_player2);
    }

    void setupStreak() {
        // thanks alphalaneous for the fucking genius code
        // theres no way i dont copy this
        auto GM = GameManager::get();
        auto SDI = SDIHelper::get();
        int origStreak = SDI->getTrail(false);
        int origShipStreak = SDI->getShipTrail(false);
        bool origGlow = SDI->getGlow(false);

        if (this->isPlayer2()) {
            GM->m_playerStreak = SDI->getTrail(true);
            GM->m_playerShipFire = SDI->getShipTrail(true);
            GM->m_playerGlow = SDI->getGlow(true);
        }

        PlayerObject::setupStreak();

        GM->m_playerStreak = origStreak;
        GM->m_playerShipFire = origShipStreak;
        GM->m_playerGlow = origGlow;
    }

    // void playDeathEffect() {
    //     auto GM = GameManager::get();
    //     auto SDI = SDIHelper::get();
    //     int origDeath = SDI->getDeathEffect(false);
    //     bool orgDeathExplode = SDI->getDeathExplode(false);

    //     if (this->isPlayer2()) {
    //         GM->m_playerDeathEffect = SDI->getDeathEffect(true);
    //         GM->setGameVariable("0153", SDI->getDeathExplode(true));
    //     }

    //     PlayerObject::playDeathEffect();

    //     queueInMainThread([GM, origDeath, orgDeathExplode]() {
    //         GM->m_playerDeathEffect = origDeath;
    //         GM->setGameVariable("0153", orgDeathExplode);
    //     });
    // }

    bool init(int player, int ship, GJBaseGameLayer* gameLayer, CCLayer* layer, bool playLayer) {
        log::info("PlayerObject::init({}, {}, {}, layer, {})", player, ship, gameLayer ? (int)std::addressof(gameLayer) : 0, playLayer);
        auto SDI = SDIHelper::get();
        return PlayerObject::init(
            this->isPlayer2(gameLayer) ? SDI->getCube(true): player,
            this->isPlayer2(gameLayer) ? SDI->getShip(true) : ship,
            gameLayer,
            layer,
            playLayer
        );
    }

    void setColor(ccColor3B const &color) {
        PlayerObject::setColor(!m_gameLayer ? color : this->isPlayer2() ? GameManager::get()->colorForIdx(SDIHelper::get()->getColor1(true)) : GameManager::get()->colorForIdx(SDIHelper::get()->getColor1(false)));
    }

    void setSecondColor(ccColor3B const &color) {
        PlayerObject::setSecondColor(!m_gameLayer ? color : this->isPlayer2() ? GameManager::get()->colorForIdx(SDIHelper::get()->getColor2(true)) : GameManager::get()->colorForIdx(SDIHelper::get()->getColor2(false)));
    }

    void updatePlayerFrame(int p0) {
        PlayerObject::updatePlayerFrame(!m_gameLayer ? p0 : p0 != 0 && this->isPlayer2() ? SDIHelper::get()->getCube(true): SDIHelper::get()->getCube(false));
    }

    void updatePlayerShipFrame(int p0) {
        PlayerObject::updatePlayerShipFrame(!m_gameLayer ? p0 : p0 != 0 && this->isPlayer2() ? SDIHelper::get()->getShip(true) : SDIHelper::get()->getShip(false));
    }

    void updatePlayerRollFrame(int p0) {
        PlayerObject::updatePlayerRollFrame(!m_gameLayer ? p0 : p0 != 0 && this->isPlayer2() ? SDIHelper::get()->getBall(true) : SDIHelper::get()->getBall(false));
    }

    void updatePlayerBirdFrame(int p0) {
        PlayerObject::updatePlayerBirdFrame(!m_gameLayer ? p0 : p0 != 0 && this->isPlayer2() ? SDIHelper::get()->getUFO(true) : SDIHelper::get()->getUFO(false));
    }

    void updatePlayerDartFrame(int p0) {
        PlayerObject::updatePlayerDartFrame(!m_gameLayer ? p0 : p0 != 0 && this->isPlayer2() ? SDIHelper::get()->getWave(true) : SDIHelper::get()->getWave(false));
    }

    void createRobot(int p0) {
        PlayerObject::createRobot(!m_gameLayer ? p0 : p0 != 0 && this->isPlayer2() ? SDIHelper::get()->getRobot(true) : SDIHelper::get()->getRobot(false));
    }

    void createSpider(int p0) {
        PlayerObject::createSpider(!m_gameLayer ? p0 : p0 != 0 && this->isPlayer2() ? SDIHelper::get()->getSpider(true) : SDIHelper::get()->getSpider(false));
    }

    void updatePlayerSwingFrame(int p0) {
        PlayerObject::updatePlayerSwingFrame(!m_gameLayer ? p0 : p0 != 0 && this->isPlayer2() ? SDIHelper::get()->getSwing(true) : SDIHelper::get()->getSwing(false));
    }

    void updatePlayerJetpackFrame(int p0) {
        PlayerObject::updatePlayerJetpackFrame(!m_gameLayer ? p0 : p0 != 0 && this->isPlayer2() ? SDIHelper::get()->getJetpack(true) : SDIHelper::get()->getJetpack(false));
    }

    void updateGlowColor() {
        if (this->isPlayer2()) {
            enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(true)));
        }
        PlayerObject::updateGlowColor();
    }
};