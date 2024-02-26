#include "PlayerData.hpp"
#include <Geode/modify/GJGarageLayer.hpp>


class $modify(MyGarageLayer, GJGarageLayer) {
    void on2PToggle(CCObject* sender) {

    }

    bool init() {
		if (!GJGarageLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

        // auto toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(MyGarageLayer::on2PToggle), 1.f);

        SimplePlayer* player1 = as<SimplePlayer*>(this->getChildByID("player-icon"));
        player1->setPositionX(player1->getPositionX() - winSize.width/12);

        auto player2 = SimplePlayer::create(0);
        player2->setID("player2-icon");
        player2->setScale(1.6f);
        player2->setPosition(player1->getPosition());
        player2->setPositionX(player2->getPositionX() + winSize.width/6);

        player2->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
        player2->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));

        if (PlayerData::player2Glow) {
            player2->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
        } else {
            player2->disableGlowOutline();
        }

        player2->updatePlayerFrame(PlayerData::player2Cube, IconType::Cube);

        this->addChild(player2);
        

        return true;
    }


    void onSelect(CCObject* sender) {
        GJGarageLayer::onSelect(sender);
        
        log::info("on select");
    }
};