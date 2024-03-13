#include "PlayerData.hpp"
#include <Geode/modify/PlayerObject.hpp>


class $modify(PlayerObject) {

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

        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
        }
    }

    void setSecondColor(ccColor3B const &color) {
        PlayerObject::setSecondColor(color);

        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
        }
    }

    void updatePlayerFrame(int p0) {
        PlayerObject::updatePlayerFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerFrame(PlayerData::player2Cube);
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerFrame(PlayerData::player2Cube);
        }
    }
    
	void updatePlayerShipFrame(int p0) {
        PlayerObject::updatePlayerShipFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerShipFrame(PlayerData::player2Ship);
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerShipFrame(PlayerData::player2Ship);
        }
        
    }

    void updatePlayerRollFrame(int p0) {
        PlayerObject::updatePlayerRollFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerRollFrame(PlayerData::player2Roll);
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerRollFrame(PlayerData::player2Roll);
        }
        
    }

    void updatePlayerBirdFrame(int p0) {
        PlayerObject::updatePlayerBirdFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerBirdFrame(PlayerData::player2Bird);
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerBirdFrame(PlayerData::player2Bird);
        }
        
    }

    void updatePlayerDartFrame(int p0) {
        PlayerObject::updatePlayerDartFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerDartFrame(PlayerData::player2Dart);
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerDartFrame(PlayerData::player2Dart);
        }
        
    }

    void updatePlayerSwingFrame(int p0) {
        PlayerObject::updatePlayerSwingFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerSwingFrame(PlayerData::player2Swing);
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerSwingFrame(PlayerData::player2Swing);
        }

    }

    void updatePlayerJetpackFrame(int p0) {
        PlayerObject::updatePlayerJetpackFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerJetpackFrame(PlayerData::player2Jetpack);
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerJetpackFrame(PlayerData::player2Jetpack);
        }   

    }

    // void togglePlayerScale(bool p0, bool p1) {
    //     PlayerObject::togglePlayerScale(p0, p1);
        
    //     if (p0) {
    //         if (PlayLayer::get()) {
    //             if (this == PlayLayer::get()->m_player2) {
    //                 PlayerObject::updatePlayerFrame(0);
    //                 PlayerObject::updatePlayerRollFrame(0);
    //             }
    //         } else if (LevelEditorLayer::get()) {
    //             if (this == LevelEditorLayer::get()->m_player2)
    //                 PlayerObject::updatePlayerFrame(0);
    //                 PlayerObject::updatePlayerRollFrame(0);
    //         }   
    //     }
    // }
};