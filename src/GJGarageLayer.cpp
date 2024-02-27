#include "PlayerData.hpp"
#include <Geode/modify/GJGarageLayer.hpp>


class $modify(MyGarageLayer, GJGarageLayer) {
    void on2PToggle(CCObject* sender) {
        auto btn = as<CCMenuItemToggler*>(sender);

        PlayerData::player2Selected = !btn->isToggled();
    }

    bool init() {
		if (!GJGarageLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

        PlayerData::player2Selected = false;

        auto toggleMenu = CCMenu::create();
        toggleMenu->setPosition({winSize.width*8.75f/10, winSize.height/2.5f});
        toggleMenu->setContentSize({35.f, 70.f});
        toggleMenu->setID("2p-toggle-menu");
        this->addChild(toggleMenu);


        auto toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(MyGarageLayer::on2PToggle), 1.f);
        toggler->setPositionX(toggleMenu->getContentWidth());
        toggler->setID("2p-toggler");
        toggleMenu->addChild(toggler);

        auto label = CCLabelBMFont::create("2P", "bigFont.fnt");
        label->setPositionX(toggleMenu->getContentWidth());
        label->setPositionY(toggler->getContentHeight());
        label->setID("2p-label");
        label->setScale(0.6f);
        toggleMenu->addChild(label);


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