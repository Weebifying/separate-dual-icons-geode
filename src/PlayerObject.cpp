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
        auto GM = GameManager::get();
        auto SDI = SDIHelper::get();
    
        int orgStreak = GM->getPlayerStreak();
        int orgShipFire = GM->getPlayerShipFire();
        GM->m_playerStreak = SDI->getTrail(this->isPlayer2());
        GM->m_playerShipFire = SDI->getShipTrail(this->isPlayer2());

        PlayerObject::setupStreak();

        GM->m_playerStreak = orgStreak;
        GM->m_playerShipFire = orgShipFire;

        if (SDI->m_isP2Main != this->isPlayer2()) { // just this->isPlayer2() works but for the sake of consistency
            SDI->m_p2ShipFire = this->m_shipStreak;
        } else {
            SDI->m_p1ShipFire = this->m_shipStreak;
        }
    }

    void playDeathEffect() {
        auto GM = GameManager::get();
        auto SDI = SDIHelper::get();
        
        int orgDeathEffect = GM->getPlayerDeathEffect();
        bool orgDeathExplode = GM->getGameVariable("0153");
        GM->m_playerDeathEffect = SDI->getDeathEffect(this->isPlayer2());
        GM->setGameVariable("0153", SDI->getDeathExplode(this->isPlayer2()));
        
        PlayerObject::playDeathEffect();

        GM->m_playerDeathEffect = orgDeathEffect;
        GM->setGameVariable("0153", orgDeathExplode);
    }

    void update(float delta) {
        ShipStreak orgShipStreak = this->m_shipStreakType;
        this->m_shipStreakType = static_cast<ShipStreak>(SDIHelper::get()->getShipTrail(this->isPlayer2()));

        PlayerObject::update(delta);

        this->m_shipStreakType = orgShipStreak;
    }

    bool init(int player, int ship, GJBaseGameLayer* gameLayer, CCLayer* layer, bool playLayer) {
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

    void updatePlayerFrame(int frame) {
        PlayerObject::updatePlayerFrame(!m_gameLayer ? frame : frame != 0 && this->isPlayer2() ? SDIHelper::get()->getCube(true): SDIHelper::get()->getCube(false));
    }

    void updatePlayerShipFrame(int frame) {
        PlayerObject::updatePlayerShipFrame(!m_gameLayer ? frame : frame != 0 && this->isPlayer2() ? SDIHelper::get()->getShip(true) : SDIHelper::get()->getShip(false));
    }

    void updatePlayerRollFrame(int frame) {
        PlayerObject::updatePlayerRollFrame(!m_gameLayer ? frame : frame != 0 && this->isPlayer2() ? SDIHelper::get()->getBall(true) : SDIHelper::get()->getBall(false));
    }

    void updatePlayerBirdFrame(int frame) {
        PlayerObject::updatePlayerBirdFrame(!m_gameLayer ? frame : frame != 0 && this->isPlayer2() ? SDIHelper::get()->getUFO(true) : SDIHelper::get()->getUFO(false));
    }

    void updatePlayerDartFrame(int frame) {
        PlayerObject::updatePlayerDartFrame(!m_gameLayer ? frame : frame != 0 && this->isPlayer2() ? SDIHelper::get()->getWave(true) : SDIHelper::get()->getWave(false));
    }

    void createRobot(int frame) {
        PlayerObject::createRobot(!m_gameLayer ? frame : frame != 0 && this->isPlayer2() ? SDIHelper::get()->getRobot(true) : SDIHelper::get()->getRobot(false));
    }

    void toggleRobotMode(bool enable, bool noEffects) {
        int target = !m_gameLayer ? this->m_robotSprite->m_iconRequestID : this->m_robotSprite->m_iconRequestID != 0 && this->isPlayer2() ? SDIHelper::get()->getRobot(true) : SDIHelper::get()->getRobot(false);
        if (this->m_robotSprite->m_iconRequestID != target) {
            this->createRobot(target);
            this->toggleGhostEffect(this->m_ghostType);
            this->m_hasGlow = SDIHelper::get()->getGlow(this->isPlayer2());
            this->enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(this->isPlayer2())));
            this->updatePlayerGlow();
            this->updateGlowColor();
        }
        PlayerObject::toggleRobotMode(enable, noEffects);
    }

    void createSpider(int frame) {
        PlayerObject::createSpider(!m_gameLayer ? frame : frame != 0 && this->isPlayer2() ? SDIHelper::get()->getSpider(true) : SDIHelper::get()->getSpider(false));
    }

    void toggleSpiderMode(bool enable, bool noEffects) {
        int target = !m_gameLayer ? this->m_spiderSprite->m_iconRequestID : this->m_spiderSprite->m_iconRequestID != 0 && this->isPlayer2() ? SDIHelper::get()->getSpider(true) : SDIHelper::get()->getSpider(false);
        if (this->m_spiderSprite->m_iconRequestID != target) {
            this->createSpider(target);
            this->toggleGhostEffect(this->m_ghostType);
            this->m_hasGlow = SDIHelper::get()->getGlow(this->isPlayer2());
            this->enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(this->isPlayer2())));
            this->updatePlayerGlow();
            this->updateGlowColor();
        }
        PlayerObject::toggleSpiderMode(enable, noEffects);
    }

    void updatePlayerSwingFrame(int frame) {
        PlayerObject::updatePlayerSwingFrame(!m_gameLayer ? frame : frame != 0 && this->isPlayer2() ? SDIHelper::get()->getSwing(true) : SDIHelper::get()->getSwing(false));
    }

    void updatePlayerJetpackFrame(int frame) {
        PlayerObject::updatePlayerJetpackFrame(!m_gameLayer ? frame : frame != 0 && this->isPlayer2() ? SDIHelper::get()->getJetpack(true) : SDIHelper::get()->getJetpack(false));
    }

    void updateGlowColor() {
        if (this->isPlayer2()) {
            enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(true)));
        }
        PlayerObject::updateGlowColor();
    }
};