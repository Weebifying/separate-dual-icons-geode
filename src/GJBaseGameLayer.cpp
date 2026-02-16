#include "Macros.hpp"
#include "SDIHelper.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(MyBaseGameLayer, GJBaseGameLayer) {
    void resetPlayer() {
        if (!this->m_isPracticeMode) {
            SDIHelper::get()->reset();
        }
        GJBaseGameLayer::resetPlayer();
        SDIHelper::get()->setPlayerInfo(this->m_player1, false);
        SDIHelper::get()->setPlayerInfo(this->m_player2, true);
    }

    bool init() {
        SDIHelper::get()->reset();
        SDIHelper::get()->loadDeathTextures(SDIHelper::get()->getDeathEffect(true));
        return GJBaseGameLayer::init();
    }

    void onExit() {
        GJBaseGameLayer::onExit();
        SDIHelper::get()->reset();
        SDIHelper::get()->unloadDeathTextures(SDIHelper::get()->getDeathEffect(true));
        SDIHelper::get()->m_p1ShipFire = nullptr;
        SDIHelper::get()->m_p2ShipFire = nullptr;
    }

    void playExitDualEffect(PlayerObject* p0) {
        GJBaseGameLayer::playExitDualEffect(p0);

        auto GM = GameManager::get();
        auto SDI = SDIHelper::get();
        
        if (p0 == m_player1) {
            if (Mod::get()->getSettingValue<bool>("exitDualSwitch") && SDI->m_shouldSwap) {
                SDI->swapAll();
                SDI->setPlayerInfo(m_player1, false);
                SDI->setPlayerInfo(m_player2, true);
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
