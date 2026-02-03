#include "Macros.hpp"
#include "SDIHelper.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(MyBaseGameLayer, GJBaseGameLayer) {
    void setInfo(PlayerObject* player, bool isP2) {
        auto GM = GameManager::get();
        auto SDI = SDIHelper::get();

        player->setColor(GM->colorForIdx(SDI->getColor1(isP2)));
        player->setSecondColor(GM->colorForIdx(SDI->getColor2(isP2)));
        player->m_originalMainColor = GM->colorForIdx(SDI->getColor1(isP2));
        player->m_originalSecondColor = GM->colorForIdx(SDI->getColor2(isP2));
        if (player->m_isShip) {
            if (player->m_isPlatformer) {
                player->updatePlayerJetpackFrame(SDI->getJetpack(isP2));
                player->updatePlayerFrame(SDI->getCube(isP2));
            } else {
                player->updatePlayerShipFrame(SDI->getShip(isP2));
                player->updatePlayerFrame(SDI->getCube(isP2));
            }
        } else if (player->m_isBall) {
            player->updatePlayerRollFrame(SDI->getBall(isP2));
        } else if (player->m_isBird) {
            player->updatePlayerBirdFrame(SDI->getUFO(isP2));
            player->updatePlayerFrame(SDI->getCube(isP2));
        } else if (player->m_isDart) {
            player->updatePlayerDartFrame(SDI->getWave(isP2));
        } else if (player->m_isRobot) {
            player->updatePlayerRobotFrame(SDI->getRobot(isP2));
        } else if (player->m_isSpider) {
            player->updatePlayerSpiderFrame(SDI->getSpider(isP2));
        } else if (player->m_isSwing) {
            player->updatePlayerSwingFrame(SDI->getSwing(isP2));
        } else {
            player->updatePlayerFrame(SDI->getCube(isP2));
        }
        player->toggleGhostEffect(player->m_ghostType);
        player->m_hasGlow = SDI->getGlow(isP2);
        player->enableCustomGlowColor(GM->colorForIdx(SDI->getGlowColor(isP2)));
        player->updatePlayerGlow();
        player->updateGlowColor();
        setupNormalStreak(player, isP2);
        // setupShipFire(player, isP2);
    }

    void setupNormalStreak(PlayerObject* player, bool isP2) {
        auto SDI = SDIHelper::get();
        player->m_streakStrokeWidth = 10.0;

        float streakFade = 0.3;
        float streakStroke = 10.0;
        switch (SDI->getTrail(isP2)) {
            case 2:
            case 7:
                streakStroke = 14.0;
                player->m_disableStreakTint = true;
                player->m_streakStrokeWidth = 14.0;
                break;
            case 3:
                streakStroke = 8.5;
                player->m_streakStrokeWidth = 8.5;
                break;
            case 4:
                streakFade = 0.4;
                streakStroke = 10.0;
                break;
            case 5:
                streakFade = 0.6;
                streakStroke = 5.0;
                player->m_streakStrokeWidth = 5.0;
                player->m_alwaysShowStreak = true;
                break;
            case 6:
                streakFade = 1.0;
                streakStroke = 3.0;
                player->m_streakStrokeWidth = 3.0;
                player->m_alwaysShowStreak = true;
                break;
        }
        
        player->m_playerStreak = SDI->getTrail(isP2);
        player->m_regularTrail->initWithFade(streakFade, 5.0, streakStroke, ccc3(255, 255, 255), CCString::createWithFormat("streak_%02d_001.png", SDI->getTrail(isP2))->getCString());
        if (SDI->getTrail(isP2) == 6) {
            player->m_regularTrail->enableRepeatMode(0.1);
        }
        player->m_regularTrail->m_fMaxSeg = 50.0;
        player->m_regularTrail->setBlendFunc({GL_SRC_ALPHA, GL_ONE});
        player->m_regularTrail->stopStroke();        
    }

    void setupShipFire(PlayerObject* player, bool isP2) {
        auto SDI = SDIHelper::get();

        float streakFade = 0.0;
        float streakStroke = 0.0;
        switch (SDI->getShipTrail(isP2)) {
            case 2:
                streakFade = 0.0636;
                streakStroke = 22.0;
                break;
            case 3:
                streakFade = 0.1278;
                streakStroke = 28.6;
                break;
            case 4:
                streakFade = 0.105;
                streakStroke = 28.6;
                break;
            case 5:
                streakFade = 0.09;
                streakStroke = 18.7;
                break;
            case 6:
                streakFade = 0.096;
                streakStroke = 27.0;
                break;
        }

        player->m_shipStreakType = static_cast<ShipStreak>(SDI->getShipTrail(isP2));
        player->m_shipStreak->initWithFade(streakFade, 5.0, streakStroke, ccc3(255, 255, 255), CCString::createWithFormat("shipfire_%02d_001.png", SDI->getShipTrail(isP2))->getCString());
        player->m_shipStreak->m_fMaxSeg = 50.0;
        player->m_shipStreak->m_bDontOpacityFade = true;
        player->m_shipStreak->setBlendFunc({GL_SRC_ALPHA, GL_ONE});
    }

    void resetPlayer() {
        if (!this->m_isPracticeMode) {
            SDIHelper::get()->reset();
        }
        GJBaseGameLayer::resetPlayer();
        setInfo(this->m_player1, false);
    }

    bool init() {
        SDIHelper::get()->reset();
        return GJBaseGameLayer::init();
    }

    void onExit() {
        GJBaseGameLayer::onExit();
        SDIHelper::get()->reset();
    }

    void playExitDualEffect(PlayerObject* p0) {
        GJBaseGameLayer::playExitDualEffect(p0);

        auto GM = GameManager::get();
        auto SDI = SDIHelper::get();
        
        if (p0 == m_player1) {
            if (Mod::get()->getSettingValue<bool>("exitDualSwitch") && SDI->m_shouldSwap) {
                SDI->swapAll();

                setInfo(m_player1, false);
                setInfo(m_player2, true);
                
            }

            if (auto player = findFirstChildRecursive<SimplePlayer>(this, [](SimplePlayer* node) { return node->getZOrder() == 100; })) {
                if (m_player1->m_isShip) {
                    if (m_player1->m_isPlatformer)
                        player->updatePlayerFrame(SDI->getJetpack(true), IconType::Jetpack);
                    else
                        player->updatePlayerFrame(SDI->getShip(true), IconType::Ship);
                } else if (m_player1->m_isBall) {
                    player->updatePlayerFrame(SDI->getBall(true), IconType::Ball);
                } else if (m_player1->m_isBird) {
                    player->updatePlayerFrame(SDI->getUFO(true), IconType::Ufo);
                } else if (m_player1->m_isDart) {
                    player->updatePlayerFrame(SDI->getWave(true), IconType::Wave);
                } else if (m_player1->m_isRobot) {
                    player->updatePlayerFrame(SDI->getRobot(true), IconType::Robot);
                } else if (m_player1->m_isSpider) {
                    player->updatePlayerFrame(SDI->getSpider(true), IconType::Spider);
                } else if (m_player1->m_isSwing) {
                    player->updatePlayerFrame(SDI->getSwing(true), IconType::Swing);
                } else {
                    player->updatePlayerFrame(SDI->getCube(true), IconType::Cube);
                }
            }
        } else if (p0 == m_player2) {
            if (auto player = findFirstChildRecursive<SimplePlayer>(this, [](SimplePlayer* node) { return node->getZOrder() == 100; })) {
                if (m_player2->m_isShip) {
                    if (m_player2->m_isPlatformer)
                        player->updatePlayerFrame(SDI->getJetpack(true), IconType::Jetpack);
                    else
                        player->updatePlayerFrame(SDI->getShip(true), IconType::Ship);
                } else if (m_player2->m_isBall) {
                    player->updatePlayerFrame(SDI->getBall(true), IconType::Ball);
                } else if (m_player2->m_isBird) {
                    player->updatePlayerFrame(SDI->getUFO(true), IconType::Ufo);
                } else if (m_player2->m_isDart) {
                    player->updatePlayerFrame(SDI->getWave(true), IconType::Wave);
                } else if (m_player2->m_isRobot) {
                    player->updatePlayerFrame(SDI->getRobot(true), IconType::Robot);
                } else if (m_player2->m_isSpider) {
                    player->updatePlayerFrame(SDI->getSpider(true), IconType::Spider);
                } else if (m_player2->m_isSwing) {
                    player->updatePlayerFrame(SDI->getSwing(true), IconType::Swing);
                } else {
                    player->updatePlayerFrame(SDI->getCube(true), IconType::Cube);
                }
            }
        }
    }
};
