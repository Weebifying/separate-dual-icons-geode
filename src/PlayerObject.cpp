#include "PlayerData.hpp"
#include <Geode/modify/PlayerObject.hpp>


class $modify(PlayerObject) {
    // static void onModify(auto& self) {
    //     self.setHookPriority("PlayerObject::setColor", INT_MIN);
    //     self.setHookPriority("PlayerObject::setSecondColor", INT_MIN);
    // }

    // bool init(int p0, int p1, GJBaseGameLayer* p2, CCLayer* p3, bool p4) {
    //     if (!PlayerObject::init(p0, p1, p2, p3, p4)) return false;

    //     if (PlayLayer::get()) {
    //         if (this == PlayLayer::get()->m_player2) {
    //             if (PlayerData::player2Glow) {
    //                 this->m_iconGlow->setVisible(true);
    //                 this->m_vehicleGlow->setVisible(true);
    //             } else {
    //                 this->m_iconGlow->setVisible(false);
    //                 this->m_vehicleGlow->setVisible(false);
    //             }
    //         }
    //     }

    //     return true;
    // }

    #ifndef GEODE_IS_ANDROID
    void playDeathEffect() {
        int orgDeath = GameManager::sharedState()->getPlayerDeathEffect();

        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2) {
                GameManager::sharedState()->setPlayerDeathEffect(PlayerData::player2Death); // culprit
            }
        }

        PlayerObject::playDeathEffect();

        GameManager::sharedState()->setPlayerDeathEffect(orgDeath);
    }
    #endif

    void setupStreak() {
        // thanks alphalaneous for the fucking genius code
        // theres no way i dont copy this
        int origStreak = GameManager::sharedState()->getPlayerStreak();
        int origShipStreak = GameManager::sharedState()->getPlayerShipFire();

        if (PlayLayer::get()) {
            if (PlayerData::callPosStreak == 1) {
                GameManager::sharedState()->setPlayerStreak(PlayerData::player2Trail);
                GameManager::sharedState()->setPlayerShipStreak(PlayerData::player2ShipTrail);
            }

            PlayerData::callPosStreak++;
            if (PlayerData::callPosStreak == 2) PlayerData::callPosStreak = 0;
        }

        PlayerObject::setupStreak();

        GameManager::sharedState()->setPlayerStreak(origStreak);
        GameManager::sharedState()->setPlayerShipStreak(origShipStreak);
    }

    void setColor(ccColor3B const &color) {
        PlayerObject::setColor(color);

        if (PlayLayer::get()) 
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
                // log::warn("PlayerObject::setColor({} = ({}, {}, {})) called!", PlayerData::player2Color1, GameManager::get()->colorForIdx(PlayerData::player2Color1).r, GameManager::get()->colorForIdx(PlayerData::player2Color1).g, GameManager::get()->colorForIdx(PlayerData::player2Color1).b);
    }

    void setSecondColor(ccColor3B const &color) {
        PlayerObject::setSecondColor(color);

        if (PlayLayer::get()) 
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
                // log::warn("PlayerObject::setSecondColor({} = ({}, {}, {})) called!", PlayerData::player2Color2, GameManager::get()->colorForIdx(PlayerData::player2Color2).r, GameManager::get()->colorForIdx(PlayerData::player2Color2).g, GameManager::get()->colorForIdx(PlayerData::player2Color2).b);
    }

    void updatePlayerFrame(int p0) {
        PlayerObject::updatePlayerFrame(p0);
        
        
        if (PlayLayer::get()) 
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerFrame(PlayerData::player2Cube);   
    }
    
	void updatePlayerShipFrame(int p0) {
        PlayerObject::updatePlayerShipFrame(p0);
        
        
        if (PlayLayer::get()) 
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerShipFrame(PlayerData::player2Ship);   
    }

    void updatePlayerRollFrame(int p0) {
        PlayerObject::updatePlayerRollFrame(p0);
        
        
        if (PlayLayer::get()) 
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerRollFrame(PlayerData::player2Roll);
        
    }

    void updatePlayerBirdFrame(int p0) {
        PlayerObject::updatePlayerBirdFrame(p0);
        
        
        if (PlayLayer::get()) 
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerBirdFrame(PlayerData::player2Bird);
        
    }

    void updatePlayerDartFrame(int p0) {
        PlayerObject::updatePlayerDartFrame(p0);
        
        
        if (PlayLayer::get()) 
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerDartFrame(PlayerData::player2Dart);
        
    }

    void updatePlayerSwingFrame(int p0) {
        PlayerObject::updatePlayerSwingFrame(p0);
        
        
        if (PlayLayer::get()) 
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerSwingFrame(PlayerData::player2Swing);

    }

    void updatePlayerJetpackFrame(int p0) {
        PlayerObject::updatePlayerJetpackFrame(p0);
        
        
        if (PlayLayer::get()) 
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerJetpackFrame(PlayerData::player2Jetpack);

    }
};

