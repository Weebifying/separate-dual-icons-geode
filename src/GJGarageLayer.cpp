#include "PlayerData.hpp"
#include <Geode/modify/GJGarageLayer.hpp>


class $modify(GJGarageLayer) {
    void onSelect(CCObject* sender) {
        GJGarageLayer::onSelect(sender);
        
        log::info("on select");
    }
};