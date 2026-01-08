#include "Macros.hpp"
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(MyBaseGameLayer, GJBaseGameLayer) {
    void playExitDualEffect(PlayerObject* p0) {
        GJBaseGameLayer::playExitDualEffect(p0);

        if (p0 == m_player2) {
            if (auto player = findFirstChildRecursive<SimplePlayer>(this, [](SimplePlayer* node) { return node->getZOrder() == 100; })) {
                if (m_player2->m_isShip) {
                    if (m_player2->m_isPlatformer)
                        player->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
                    else
                        player->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                } else if (m_player2->m_isBall) {
                    player->updatePlayerFrame(GDI_GET_VALUE(int64_t, "roll", 1), IconType::Ball);
                } else if (m_player2->m_isBird) {
                    player->updatePlayerFrame(GDI_GET_VALUE(int64_t, "bird", 1), IconType::Ufo);
                } else if (m_player2->m_isDart) {
                    player->updatePlayerFrame(GDI_GET_VALUE(int64_t, "dart", 1), IconType::Wave);
                } else if (m_player2->m_isRobot) {
                    player->updatePlayerFrame(GDI_GET_VALUE(int64_t, "robot", 1), IconType::Robot);
                } else if (m_player2->m_isSpider) {
                    player->updatePlayerFrame(GDI_GET_VALUE(int64_t, "spider", 1), IconType::Spider);
                } else if (m_player2->m_isSwing) {
                    player->updatePlayerFrame(GDI_GET_VALUE(int64_t, "swing", 1), IconType::Swing);
                } else {
                    player->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1), IconType::Cube);
                }
            }
        }
    }
};
