#include "PlayerData.hpp"
#include <Geode/modify/LevelEditorLayer.hpp>


class $modify(LevelEditorLayer) {
    int lastType = 0;

    void postUpdate(float p0) {
        LevelEditorLayer::postUpdate(p0);

        PlayerObject* player2 = this->m_player2;
        if (player2->m_isShip) {

            if (lastType != 1) {
                if (player2->m_isPlatformer)
                    player2->updatePlayerJetpackFrame(PlayerData::player2Jetpack);
                else
                    player2->updatePlayerShipFrame(PlayerData::player2Ship);

                player2->updatePlayerFrame(PlayerData::player2Cube);
                lastType = 1;
            }

        } else if (player2->m_isBall) {
            
            if (lastType != 2) {
                player2->updatePlayerRollFrame(PlayerData::player2Roll);
                lastType = 2;
            }

        } else if (player2->m_isBird) {

            if (lastType != 3) {
                player2->updatePlayerBirdFrame(PlayerData::player2Bird);
                player2->updatePlayerFrame(PlayerData::player2Cube);
                lastType = 3;
            }

        } else if (player2->m_isDart) {

            if (lastType != 4) {
                player2->updatePlayerDartFrame(PlayerData::player2Dart);
                lastType = 4;
            }

        } else if (player2->m_isRobot) {

            if (lastType != 5) lastType = 5;

        } else if (player2->m_isSpider) {

            if (lastType != 6) lastType = 6;

        } else if (player2->m_isSwing) {

            if (lastType != 7) {
                player2->updatePlayerSwingFrame(PlayerData::player2Swing);
                lastType = 7;
            }

        } else {

            if (lastType != 0) {
                player2->updatePlayerFrame(PlayerData::player2Cube);
                lastType = 0;
            }

        }

    }

    void onPlaytest() {
        PlayerData::callPosStreak = 0;        
        LevelEditorLayer::onPlaytest();


        PlayerObject* player2 = this->m_player2;

        if (player2->m_isShip) {

            m_fields->lastType = 1;

        } else if (player2->m_isBall) {

            m_fields->lastType = 2;

        } else if (player2->m_isBird) {

            m_fields->lastType = 3;

        } else if (player2->m_isDart) {

            m_fields->lastType = 4;

        } else if (player2->m_isRobot) {

            m_fields->lastType = 5;

        } else if (player2->m_isSpider) {

            m_fields->lastType = 6;

        } else if (player2->m_isSwing) {

            m_fields->lastType = 7;

        } else {

            m_fields->lastType = 0;

        }

        // // required
        player2->updatePlayerRobotFrame(PlayerData::player2Robot);
        player2->updatePlayerSpiderFrame(PlayerData::player2Spider);


        player2->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
        player2->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
        
        if (PlayerData::player2Glow) {
            player2->m_hasGlow = true;
            player2->m_glowColor = GameManager::get()->colorForIdx(PlayerData::player2ColorGlow);
        } else {
            player2->m_hasGlow = false;
        }

        player2->updateGlowColor();
        player2->updatePlayerGlow();    
    }
};