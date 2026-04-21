#include "../SDIHelper.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
using namespace geode::prelude;

class $modify(PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        if (player && !player->isVanillaPlayer()) return PlayLayer::destroyPlayer(player, object);
        SDIHelper::get()->m_shouldSwap = false;
        PlayLayer::destroyPlayer(player, object);
        SDIHelper::get()->m_shouldSwap = true;
    }
};