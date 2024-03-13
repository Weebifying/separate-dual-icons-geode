#include "PlayerData.hpp"
#include <Geode/modify/ProfilePage.hpp>


class $modify(MyProfilePage, ProfilePage) {

    // make ship/jetpack toggle
    bool hasLoaded = false;
    IconType shipType = IconType::Ship;

    static void onModify(auto& self) {
        self.setHookPriority("CharacterColorPage::loadPageFromUserInfo", 1000000);
    }

    void onShipToggle(CCObject* sender) {
        auto ship = getChildOfType<SimplePlayer>(as<CCNode*>(sender), 0);
        auto GM = GameManager::get();

        if (PlayerData::player2Selected) {
            switch (m_fields->shipType) {
                case IconType::Ship:
                    m_fields->shipType = IconType::Jetpack;
                    ship->updatePlayerFrame(PlayerData::player2Jetpack, m_fields->shipType);
                    ship->setScale(0.9f);
                    break;
                case IconType::Jetpack:
                    m_fields->shipType = IconType::Ship;
                    ship->updatePlayerFrame(PlayerData::player2Ship, m_fields->shipType);
                    ship->setScale(0.95f);
                    break;
            }

        } else {
            switch (m_fields->shipType) {
                case IconType::Ship:
                    m_fields->shipType = IconType::Jetpack;
                    ship->updatePlayerFrame(GM->getPlayerShip(), m_fields->shipType);
                    ship->setScale(0.9f);
                    break;
                case IconType::Jetpack:
                    m_fields->shipType = IconType::Ship;
                    ship->updatePlayerFrame(GM->getPlayerJetpack(), m_fields->shipType);
                    ship->setScale(0.95f);
                    break;
            }

        }
    }

    void on2PToggle(CCObject* sender) {
        auto GM = GameManager::get();

        auto layer = as<CCLayer*>(this->getChildren()->objectAtIndex(0));
        auto menu = layer->getChildByID("player-menu");

        auto cube = getChildOfType<SimplePlayer>(menu->getChildByID("player-icon"), 0);
        auto ship = getChildOfType<SimplePlayer>(menu->getChildByID("player-ship"), 0);
        auto ball = getChildOfType<SimplePlayer>(menu->getChildByID("player-ball"), 0);
        auto ufo = getChildOfType<SimplePlayer>(menu->getChildByID("player-ufo"), 0);
        auto wave = getChildOfType<SimplePlayer>(menu->getChildByID("player-wave"), 0);
        auto robot = getChildOfType<SimplePlayer>(menu->getChildByID("player-robot"), 0);
        auto spider = getChildOfType<SimplePlayer>(menu->getChildByID("player-spider"), 0);
        auto swing = getChildOfType<SimplePlayer>(menu->getChildByID("player-swing"), 0);


        if (as<CCMenuItemToggler*>(sender)->isOn()) {
            PlayerData::player2Selected = false;

            cube->updatePlayerFrame(GM->getPlayerFrame(), IconType::Cube);
            cube->setColor(GM->colorForIdx(GM->getPlayerColor()));
            cube->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                cube->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                cube->disableGlowOutline();
            }

            if (m_fields->shipType == IconType::Ship) ship->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
            else ship->updatePlayerFrame(GM->getPlayerJetpack(), IconType::Jetpack);
            ship->setColor(GM->colorForIdx(GM->getPlayerColor()));
            ship->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                ship->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                ship->disableGlowOutline();
            }

            ball->updatePlayerFrame(GM->getPlayerBall(), IconType::Ball);
            ball->setColor(GM->colorForIdx(GM->getPlayerColor()));
            ball->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                ball->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                ball->disableGlowOutline();
            }

            ufo->updatePlayerFrame(GM->getPlayerBird(), IconType::Ufo);
            ufo->setColor(GM->colorForIdx(GM->getPlayerColor()));
            ufo->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                ufo->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                ufo->disableGlowOutline();
            }

            wave->updatePlayerFrame(GM->getPlayerDart(), IconType::Wave);
            wave->setColor(GM->colorForIdx(GM->getPlayerColor()));
            wave->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                wave->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                wave->disableGlowOutline();
            }

            robot->updatePlayerFrame(GM->getPlayerRobot(), IconType::Robot);
            robot->setColor(GM->colorForIdx(GM->getPlayerColor()));
            robot->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                robot->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                robot->disableGlowOutline();
            }

            spider->updatePlayerFrame(GM->getPlayerSpider(), IconType::Spider);
            spider->setColor(GM->colorForIdx(GM->getPlayerColor()));
            spider->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                spider->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                spider->disableGlowOutline();
            }

            swing->updatePlayerFrame(GM->getPlayerSwing(), IconType::Swing);
            swing->setColor(GM->colorForIdx(GM->getPlayerColor()));
            swing->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                swing->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                swing->disableGlowOutline();
            }
        } else {
            PlayerData::player2Selected = true;

            cube->updatePlayerFrame(PlayerData::player2Cube, IconType::Cube);
            cube->setColor(GM->colorForIdx(PlayerData::player2Color1));
            cube->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                cube->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                cube->disableGlowOutline();
            }

            if (m_fields->shipType == IconType::Ship) ship->updatePlayerFrame(PlayerData::player2Ship, IconType::Ship);
            else ship->updatePlayerFrame(PlayerData::player2Jetpack, IconType::Jetpack);
            ship->setColor(GM->colorForIdx(PlayerData::player2Color1));
            ship->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                ship->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                ship->disableGlowOutline();
            }

            ball->updatePlayerFrame(PlayerData::player2Roll, IconType::Ball);
            ball->setColor(GM->colorForIdx(PlayerData::player2Color1));
            ball->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                ball->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                ball->disableGlowOutline();
            }

            ufo->updatePlayerFrame(PlayerData::player2Bird, IconType::Ufo);
            ufo->setColor(GM->colorForIdx(PlayerData::player2Color1));
            ufo->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                ufo->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                ufo->disableGlowOutline();
            }

            wave->updatePlayerFrame(PlayerData::player2Dart, IconType::Wave);
            wave->setColor(GM->colorForIdx(PlayerData::player2Color1));
            wave->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                wave->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                wave->disableGlowOutline();
            }

            robot->updatePlayerFrame(PlayerData::player2Robot, IconType::Robot);
            robot->setColor(GM->colorForIdx(PlayerData::player2Color1));
            robot->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                robot->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                robot->disableGlowOutline();
            }

            spider->updatePlayerFrame(PlayerData::player2Spider, IconType::Spider);
            spider->setColor(GM->colorForIdx(PlayerData::player2Color1));
            spider->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                spider->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                spider->disableGlowOutline();
            }

            swing->updatePlayerFrame(PlayerData::player2Swing, IconType::Swing);
            swing->setColor(GM->colorForIdx(PlayerData::player2Color1));
            swing->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                swing->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                swing->disableGlowOutline();
            }
        }
    };

    void loadPageFromUserInfo(GJUserScore* p0){
        ProfilePage::loadPageFromUserInfo(p0);
        PlayerData::player2Selected = false;

        auto GM = GameManager::get();

        if (this->m_ownProfile) {
            if (auto menu = as<CCLayer*>(this->getChildren()->objectAtIndex(0))->getChildByID("player-menu")) {
                auto ship = menu->getChildByID("player-ship");

                auto myShipSprite = SimplePlayer::create(GM->getPlayerShip());
                myShipSprite->setScale(0.95f);
                myShipSprite->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
                myShipSprite->setColor(GM->colorForIdx(GM->getPlayerColor()));
                myShipSprite->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) {
                    myShipSprite->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                }

                auto myShip = CCMenuItemSpriteExtra::create(myShipSprite, this, menu_selector(MyProfilePage::onShipToggle));
                myShip->setPosition(ship->getPosition());
                myShip->setContentSize(ship->getContentSize());
                myShipSprite->setPosition({myShip->getContentWidth()/2, myShip->getContentHeight()/2});
                menu->addChild(myShip);
                menu->removeChild(ship);
                myShip->setID("player-ship");

            }
        }
        
        if (this->m_ownProfile && !m_fields->hasLoaded) {
            
            m_fields->hasLoaded = true;
            auto layer = as<CCLayer*>(this->getChildren()->objectAtIndex(0));
            auto winSize = CCDirector::get()->getWinSize();

            if (auto menu = layer->getChildByID("left-menu")) {
                
                menu->setContentHeight(menu->getContentHeight()*2);
                menu->setPositionY(menu->getPositionY() - menu->getContentHeight()/4);

                auto label = CCLabelBMFont::create("2P", "bigFont.fnt");
                auto sprite2POff = CircleButtonSprite::create(label, CircleBaseColor::Green, CircleBaseSize::Medium);
                sprite2POff->setScale(0.7f);
                auto sprite2POn = CircleButtonSprite::create(label, CircleBaseColor::Cyan, CircleBaseSize::Medium);
                sprite2POn->setScale(0.7f);

                auto toggler = CCMenuItemToggler::create(sprite2POff, sprite2POn, this, menu_selector(MyProfilePage::on2PToggle));
                toggler->setID("2p-toggler");
                menu->addChild(toggler);
                menu->updateLayout();

            }
        }
    }
};