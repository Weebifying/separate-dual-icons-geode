#include "PlayerData.hpp"
#include <Geode/modify/PlayLayer.hpp>


class $modify(PlayLayer) {
    bool init(GJGameLevel* p0, bool p1, bool p2) {
        PlayerData::callPosStreak = 0;
        if (!PlayLayer::init(p0, p1, p2)) return false;
        GameManager::get()->loadDeathEffect(Mod::get()->getSavedValue<int64_t>("death", 1));

        PlayerObject* player2 = this->m_player2;
        if (!player2) return true;
        if (player2->m_isShip) {

            if (this->m_level->isPlatformer())
                player2->updatePlayerJetpackFrame(Mod::get()->getSavedValue<int64_t>("jetpack", 1));
            else
                player2->updatePlayerShipFrame(Mod::get()->getSavedValue<int64_t>("ship", 1));

            player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("cube", 1));

        } else if (player2->m_isBall) {

            player2->updatePlayerRollFrame(Mod::get()->getSavedValue<int64_t>("roll", 1));

        } else if (player2->m_isBird) {

            player2->updatePlayerBirdFrame(Mod::get()->getSavedValue<int64_t>("bird", 1));
            player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("cube", 1));

        } else if (player2->m_isDart) {

            player2->updatePlayerDartFrame(Mod::get()->getSavedValue<int64_t>("dart", 1));

        } else if (player2->m_isSwing) {

            player2->updatePlayerSwingFrame(Mod::get()->getSavedValue<int64_t>("swing", 1));

        } else {

            player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("cube", 1));

        }

        // required
        player2->updatePlayerRobotFrame(Mod::get()->getSavedValue<int64_t>("robot", 1));
        player2->updatePlayerSpiderFrame(Mod::get()->getSavedValue<int64_t>("spider", 1));

        player2->setColor(GameManager::get()->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
        player2->setSecondColor(GameManager::get()->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
        

        if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
            player2->m_hasGlow = true;
            player2->m_glowColor = GameManager::get()->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0));
        } else {
            player2->m_hasGlow = false;
        }

        player2->updateGlowColor();
        player2->updatePlayerGlow();

        return true;
    }
};