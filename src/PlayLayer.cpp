#include "PlayerData.hpp"
#include <Geode/modify/PlayLayer.hpp>


class $modify(PlayLayer) {
    bool init(GJGameLevel* p0, bool p1, bool p2) {
        PlayerData::callPosStreak = 0;        
        if (!PlayLayer::init(p0, p1, p2)) return false;


        PlayerObject* player2 = this->m_player2;
        if (player2->m_isShip) {

            if (this->m_level->isPlatformer())
                player2->updatePlayerJetpackFrame(PlayerData::player2Jetpack);
            else
                player2->updatePlayerShipFrame(PlayerData::player2Ship);

            player2->updatePlayerFrame(PlayerData::player2Cube);

        } else if (player2->m_isBall) {

            player2->updatePlayerRollFrame(PlayerData::player2Roll);

        } else if (player2->m_isBird) {

            player2->updatePlayerBirdFrame(PlayerData::player2Bird);
            player2->updatePlayerFrame(PlayerData::player2Cube);

        } else if (player2->m_isDart) {

            player2->updatePlayerDartFrame(PlayerData::player2Dart);

        } else if (player2->m_isSwing) {

            player2->updatePlayerSwingFrame(PlayerData::player2Swing);

        } else {

            player2->updatePlayerFrame(PlayerData::player2Cube);

        }

        // required
        player2->updatePlayerRobotFrame(PlayerData::player2Robot);
        player2->updatePlayerSpiderFrame(PlayerData::player2Spider);

        player2->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
        player2->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
        
        log::warn("{}", PlayerData::player2Glow);
        if (PlayerData::player2Glow) {
            player2->m_hasGlow = true;
            player2->m_glowColor = GameManager::get()->colorForIdx(PlayerData::player2ColorGlow);
        } else {
            player2->m_hasGlow = false;
        }
        log::warn("{}", PlayerData::player2ColorGlow);

        player2->updateGlowColor();
        player2->updatePlayerGlow();

        return true;
    }
};