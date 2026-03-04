#include "Macros.hpp"
#include "../SDIHelper.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
    bool isPlayer2() {
        return isPlayer2(m_gameLayer);
    }

    bool isPlayer1() {
        return isPlayer1(m_gameLayer);
    }

    bool isPlayer2(GJBaseGameLayer* gameLayer) {
        return gameLayer && ((gameLayer->m_player1 && !gameLayer->m_player2 && this != gameLayer->m_player1) || this == gameLayer->m_player2);
    }

    bool isPlayer1(GJBaseGameLayer* gameLayer) {
        return gameLayer && ((gameLayer->m_player1 && !gameLayer->m_player2 && this == gameLayer->m_player1) || this == gameLayer->m_player1);
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
        PlayerObject::setColor(RESOLVE_VALUE(color, GameManager::get()->colorForIdx(SDIHelper::get()->getColor1(false)), GameManager::get()->colorForIdx(SDIHelper::get()->getColor1(true))));
    }

    void setSecondColor(ccColor3B const &color) {
        PlayerObject::setSecondColor(RESOLVE_VALUE(color, GameManager::get()->colorForIdx(SDIHelper::get()->getColor2(false)), GameManager::get()->colorForIdx(SDIHelper::get()->getColor2(true))));
    }

    void updatePlayerFrame(int frame) {
        PlayerObject::updatePlayerFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getCube(false), SDIHelper::get()->getCube(true)));
    }

    void updatePlayerShipFrame(int frame) {
        PlayerObject::updatePlayerShipFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getShip(false), SDIHelper::get()->getShip(true)));
    }

    void updatePlayerRollFrame(int frame) {
        PlayerObject::updatePlayerRollFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getBall(false), SDIHelper::get()->getBall(true)));
    }

    void updatePlayerBirdFrame(int frame) {
        PlayerObject::updatePlayerBirdFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getUFO(false), SDIHelper::get()->getUFO(true)));
    }

    void updatePlayerDartFrame(int frame) {
        PlayerObject::updatePlayerDartFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getWave(false), SDIHelper::get()->getWave(true)));
    }

    void createRobot(int frame) {
        PlayerObject::createRobot(RESOLVE_VALUE(frame, SDIHelper::get()->getRobot(false), SDIHelper::get()->getRobot(true)));
    }

    void toggleRobotMode(bool enable, bool noEffects) {
        int target = RESOLVE_VALUE(this->m_robotSprite->m_iconRequestID, SDIHelper::get()->getRobot(false), SDIHelper::get()->getRobot(true));
        if (this->m_robotSprite->m_iconRequestID != target) {
            this->createRobot(target);
            
            if (this->m_ghostType == GhostType::Enabled) {
                this->toggleGhostEffect(GhostType::Disabled);
            }
            this->toggleGhostEffect(this->m_ghostType);
            // TODO: recreate toggleGhostEffect because this doesnt work :)))))) (fucking pain)
            
            this->m_hasGlow = SDIHelper::get()->getGlow(this->isPlayer2());
            this->enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(this->isPlayer2())));
            this->updatePlayerGlow();
            this->updateGlowColor();
        }
        PlayerObject::toggleRobotMode(enable, noEffects);
    }

    void createSpider(int frame) {
        PlayerObject::createSpider(RESOLVE_VALUE(frame, SDIHelper::get()->getSpider(false), SDIHelper::get()->getSpider(true)));
    }

    void toggleSpiderMode(bool enable, bool noEffects) {
        int target = RESOLVE_VALUE(this->m_spiderSprite->m_iconRequestID, SDIHelper::get()->getSpider(false), SDIHelper::get()->getSpider(true));
        if (this->m_spiderSprite->m_iconRequestID != target) {
            this->createSpider(target);

            if (this->m_ghostType == GhostType::Enabled) {
                this->toggleGhostEffect(GhostType::Disabled);
            }
            this->toggleGhostEffect(this->m_ghostType);

            this->m_hasGlow = SDIHelper::get()->getGlow(this->isPlayer2());
            this->enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(this->isPlayer2())));
            this->updatePlayerGlow();
            this->updateGlowColor();
        }
        PlayerObject::toggleSpiderMode(enable, noEffects);
    }

    void updatePlayerSwingFrame(int frame) {
        PlayerObject::updatePlayerSwingFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getSwing(false), SDIHelper::get()->getSwing(true)));
    }

    void updatePlayerJetpackFrame(int frame) {
        PlayerObject::updatePlayerJetpackFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getJetpack(false), SDIHelper::get()->getJetpack(true)));
    }

    void updateGlowColor() {
        if (this->isPlayer2()) {
            enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(true)));
        }
        PlayerObject::updateGlowColor();
    }
};