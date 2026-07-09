#include "Macros.hpp"
#include "../SDIHelper.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
    bool isPlayer2SDI() {
        return isPlayer2SDI(m_gameLayer);
    }

    bool isPlayer2SDI(GJBaseGameLayer* gameLayer) {
        return gameLayer && ((gameLayer->m_player1 && !gameLayer->m_player2 && this != gameLayer->m_player1) || this == gameLayer->m_player2);
    }

    void setupStreak() {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::setupStreak();
        auto GM = GameManager::get();
        auto SDI = SDIHelper::get();
    
        int orgStreak = GM->getPlayerStreak();
        int orgShipFire = GM->getPlayerShipFire();
        GM->m_playerStreak = SDI->getTrail(this->isPlayer2SDI());
        GM->m_playerShipFire = SDI->getShipTrail(this->isPlayer2SDI());

        PlayerObject::setupStreak();

        GM->m_playerStreak = orgStreak;
        GM->m_playerShipFire = orgShipFire;

        if (SDI->m_isP2Main != this->isPlayer2SDI()) { // just this->isPlayer2SDI() works but for the sake of consistency
            SDI->m_p2ShipFire = this->m_shipStreak;
        } else {
            SDI->m_p1ShipFire = this->m_shipStreak;
        }
    }

    void playDeathEffect() {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::playDeathEffect();
        auto GM = GameManager::get();
        auto SDI = SDIHelper::get();
        
        int orgDeathEffect = GM->getPlayerDeathEffect();
        bool orgDeathExplode = GM->getGameVariable("0153");
        GM->m_playerDeathEffect = SDI->getDeathEffect(this->isPlayer2SDI());
        GM->setGameVariable("0153", SDI->getDeathExplode(this->isPlayer2SDI()));
        
        PlayerObject::playDeathEffect();

        GM->m_playerDeathEffect = orgDeathEffect;
        GM->setGameVariable("0153", orgDeathExplode);
    }

    void update(float delta) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::update(delta);
        ShipStreak orgShipStreak = this->m_shipStreakType;
        this->m_shipStreakType = static_cast<ShipStreak>(SDIHelper::get()->getShipTrail(this->isPlayer2SDI()));

        PlayerObject::update(delta);

        this->m_shipStreakType = orgShipStreak;
    }

    bool init(int player, int ship, GJBaseGameLayer* gameLayer, CCLayer* layer, bool playLayer) {
        auto SDI = SDIHelper::get();
        if (!SDI->m_insideCreatePlayer) return PlayerObject::init(player, ship, gameLayer, layer, playLayer);
        return PlayerObject::init(
            this->isPlayer2SDI(gameLayer) ? SDI->getCube(true): player,
            this->isPlayer2SDI(gameLayer) ? SDI->getShip(true) : ship,
            gameLayer,
            layer,
            playLayer
        );
    }

    void setColor(ccColor3B const &color) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::setColor(color);
        PlayerObject::setColor(RESOLVE_VALUE(color, GameManager::get()->colorForIdx(SDIHelper::get()->getColor1(false)), GameManager::get()->colorForIdx(SDIHelper::get()->getColor1(true))));
    }

    void setSecondColor(ccColor3B const &color) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::setSecondColor(color);
        PlayerObject::setSecondColor(RESOLVE_VALUE(color, GameManager::get()->colorForIdx(SDIHelper::get()->getColor2(false)), GameManager::get()->colorForIdx(SDIHelper::get()->getColor2(true))));
    }

    void updatePlayerFrame(int frame) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::updatePlayerFrame(frame);
        PlayerObject::updatePlayerFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getCube(false), SDIHelper::get()->getCube(true)));
    }

    void updatePlayerShipFrame(int frame) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::updatePlayerShipFrame(frame);
        PlayerObject::updatePlayerShipFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getShip(false), SDIHelper::get()->getShip(true)));
    }

    void updatePlayerRollFrame(int frame) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::updatePlayerRollFrame(frame);
        PlayerObject::updatePlayerRollFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getBall(false), SDIHelper::get()->getBall(true)));
    }

    void updatePlayerBirdFrame(int frame) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::updatePlayerBirdFrame(frame);
        PlayerObject::updatePlayerBirdFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getUFO(false), SDIHelper::get()->getUFO(true)));
    }

    void updatePlayerDartFrame(int frame) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::updatePlayerDartFrame(frame);
        PlayerObject::updatePlayerDartFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getWave(false), SDIHelper::get()->getWave(true)));
    }

    void createRobot(int frame) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::createRobot(frame);
        PlayerObject::createRobot(RESOLVE_VALUE(frame, SDIHelper::get()->getRobot(false), SDIHelper::get()->getRobot(true)));
    }

    void toggleRobotMode(bool enable, bool noEffects) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::toggleRobotMode(enable, noEffects);
        int target = RESOLVE_VALUE(this->m_robotSprite->m_iconRequestID, SDIHelper::get()->getRobot(false), SDIHelper::get()->getRobot(true));
        if (this->m_robotSprite->m_iconRequestID != target) {
            this->createRobot(target);
            
            if (this->m_ghostType == GhostType::Enabled) {
                this->toggleGhostEffect(GhostType::Disabled);
            }
            this->toggleGhostEffect(this->m_ghostType);
            // TODO: recreate toggleGhostEffect because this doesnt work :)))))) (fucking pain)
            
            this->m_hasGlow = SDIHelper::get()->getGlow(this->isPlayer2SDI());
            this->enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(this->isPlayer2SDI())));
            this->updatePlayerGlow();
            this->updateGlowColor();
        }
        PlayerObject::toggleRobotMode(enable, noEffects);
    }

    void createSpider(int frame) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::createSpider(frame);
        PlayerObject::createSpider(RESOLVE_VALUE(frame, SDIHelper::get()->getSpider(false), SDIHelper::get()->getSpider(true)));
    }

    void toggleSpiderMode(bool enable, bool noEffects) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::toggleSpiderMode(enable, noEffects);
        int target = RESOLVE_VALUE(this->m_spiderSprite->m_iconRequestID, SDIHelper::get()->getSpider(false), SDIHelper::get()->getSpider(true));
        if (this->m_spiderSprite->m_iconRequestID != target) {
            this->createSpider(target);

            if (this->m_ghostType == GhostType::Enabled) {
                this->toggleGhostEffect(GhostType::Disabled);
            }
            this->toggleGhostEffect(this->m_ghostType);

            this->m_hasGlow = SDIHelper::get()->getGlow(this->isPlayer2SDI());
            this->enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(this->isPlayer2SDI())));
            this->updatePlayerGlow();
            this->updateGlowColor();
        }
        PlayerObject::toggleSpiderMode(enable, noEffects);
    }

    void updatePlayerSwingFrame(int frame) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::updatePlayerSwingFrame(frame);
        PlayerObject::updatePlayerSwingFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getSwing(false), SDIHelper::get()->getSwing(true)));
    }

    void updatePlayerJetpackFrame(int frame) {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::updatePlayerJetpackFrame(frame);
        PlayerObject::updatePlayerJetpackFrame(RESOLVE_VALUE(frame, SDIHelper::get()->getJetpack(false), SDIHelper::get()->getJetpack(true)));
    }

    void updateGlowColor() {
        if (!PlayerObject::isVanillaPlayer()) return PlayerObject::updateGlowColor();
        if (this->isPlayer2SDI()) {
            enableCustomGlowColor(GameManager::get()->colorForIdx(SDIHelper::get()->getGlowColor(true)));
        }
        PlayerObject::updateGlowColor();
    }
};