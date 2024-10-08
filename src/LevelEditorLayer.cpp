#include "PlayerData.hpp"
#include "Macros.hpp"
#include <Geode/modify/LevelEditorLayer.hpp>


class $modify(LevelEditorLayer) {
    struct Fields {
        int lastType = 0;
    };

    void postUpdate(float p0) {
        LevelEditorLayer::postUpdate(p0);

        PlayerObject* player2 = this->m_player2;
        if (player2->m_isShip) {

            if (m_fields->lastType != 1) {
                if (player2->m_isPlatformer)
                    player2->updatePlayerJetpackFrame(GDI_GET_VALUE(int64_t, "jetpack", 1));
                else
                    player2->updatePlayerShipFrame(GDI_GET_VALUE(int64_t, "ship", 1));

                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1));
                m_fields->lastType = 1;
            }

        } else if (player2->m_isBall) {
            
            if (m_fields->lastType != 2) {
                player2->updatePlayerRollFrame(GDI_GET_VALUE(int64_t, "roll", 1));
                m_fields->lastType = 2;
            }

        } else if (player2->m_isBird) {

            if (m_fields->lastType != 3) {
                player2->updatePlayerBirdFrame(GDI_GET_VALUE(int64_t, "bird", 1));
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1));
                m_fields->lastType = 3;
            }

        } else if (player2->m_isDart) {

            if (m_fields->lastType != 4) {
                player2->updatePlayerDartFrame(GDI_GET_VALUE(int64_t, "dart", 1));
                m_fields->lastType = 4;
            }

        } else if (player2->m_isRobot) {

            if (m_fields->lastType != 5) m_fields->lastType = 5;

        } else if (player2->m_isSpider) {

            if (m_fields->lastType != 6) m_fields->lastType = 6;

        } else if (player2->m_isSwing) {

            if (m_fields->lastType != 7) {
                player2->updatePlayerSwingFrame(GDI_GET_VALUE(int64_t, "swing", 1));
                m_fields->lastType = 7;
            }

        } else {

            if (m_fields->lastType != 0) {
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1));
                m_fields->lastType = 0;
            }

        }

    }

    void onPlaytest() {
        PlayerData::callPosStreak = 0;        
        LevelEditorLayer::onPlaytest();


        PlayerObject* player2 = this->m_player2;

        if (player2->m_isShip) {
            if (player2->m_isPlatformer)
                player2->updatePlayerJetpackFrame(GDI_GET_VALUE(int64_t, "jetpack", 1));
            else
                player2->updatePlayerShipFrame(GDI_GET_VALUE(int64_t, "ship", 1));
            m_fields->lastType = 1;

        } else if (player2->m_isBall) {
            player2->updatePlayerRollFrame(GDI_GET_VALUE(int64_t, "roll", 1));
            m_fields->lastType = 2;

        } else if (player2->m_isBird) {
            player2->updatePlayerBirdFrame(GDI_GET_VALUE(int64_t, "bird", 1));
            m_fields->lastType = 3;

        } else if (player2->m_isDart) {
            player2->updatePlayerDartFrame(GDI_GET_VALUE(int64_t, "dart", 1));
            m_fields->lastType = 4;

        } else if (player2->m_isRobot) {

            m_fields->lastType = 5;

        } else if (player2->m_isSpider) {

            m_fields->lastType = 6;

        } else if (player2->m_isSwing) {
            player2->updatePlayerSwingFrame(GDI_GET_VALUE(int64_t, "swing", 1));
            m_fields->lastType = 7;

        } else {

            player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1));
            m_fields->lastType = 0;

        }

        // // required
        player2->updatePlayerRobotFrame(GDI_GET_VALUE(int64_t, "robot", 1));
        player2->updatePlayerSpiderFrame(GDI_GET_VALUE(int64_t, "spider", 1));


        player2->setColor(GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
        player2->setSecondColor(GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
        
        if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
            player2->m_hasGlow = true;
            player2->m_glowColor = GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0));
        } else {
            player2->m_hasGlow = false;
        }

        player2->updateGlowColor();
        player2->updatePlayerGlow();    
    }
};