#include "PlayerData.hpp"
#include <Geode/modify/ProfilePage.hpp>


class $modify(MyProfilePage, ProfilePage) {

    // make ship/jetpack toggle


    void on2PToggle(CCObject* sender) {
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
            cube->updatePlayerFrame(GameManager::get()->getPlayerFrame(), IconType::Cube);
            cube->setColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor()));
            cube->setSecondColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor2()));
            if (GameManager::get()->getPlayerGlow()) {
                cube->setGlowOutline(GameManager::get()->colorForIdx(GameManager::get()->getPlayerGlowColor()));
            } else {
                cube->disableGlowOutline();
            }

            ship->updatePlayerFrame(GameManager::get()->getPlayerShip(), IconType::Ship);
            ship->setColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor()));
            ship->setSecondColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor2()));
            if (GameManager::get()->getPlayerGlow()) {
                ship->setGlowOutline(GameManager::get()->colorForIdx(GameManager::get()->getPlayerGlowColor()));
            } else {
                ship->disableGlowOutline();
            }

            ball->updatePlayerFrame(GameManager::get()->getPlayerBall(), IconType::Ball);
            ball->setColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor()));
            ball->setSecondColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor2()));
            if (GameManager::get()->getPlayerGlow()) {
                ball->setGlowOutline(GameManager::get()->colorForIdx(GameManager::get()->getPlayerGlowColor()));
            } else {
                ball->disableGlowOutline();
            }

            ufo->updatePlayerFrame(GameManager::get()->getPlayerBird(), IconType::Ufo);
            ufo->setColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor()));
            ufo->setSecondColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor2()));
            if (GameManager::get()->getPlayerGlow()) {
                ufo->setGlowOutline(GameManager::get()->colorForIdx(GameManager::get()->getPlayerGlowColor()));
            } else {
                ufo->disableGlowOutline();
            }

            wave->updatePlayerFrame(GameManager::get()->getPlayerDart(), IconType::Wave);
            wave->setColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor()));
            wave->setSecondColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor2()));
            if (GameManager::get()->getPlayerGlow()) {
                wave->setGlowOutline(GameManager::get()->colorForIdx(GameManager::get()->getPlayerGlowColor()));
            } else {
                wave->disableGlowOutline();
            }

            robot->updatePlayerFrame(GameManager::get()->getPlayerRobot(), IconType::Robot);
            robot->setColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor()));
            robot->setSecondColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor2()));
            if (GameManager::get()->getPlayerGlow()) {
                robot->setGlowOutline(GameManager::get()->colorForIdx(GameManager::get()->getPlayerGlowColor()));
            } else {
                robot->disableGlowOutline();
            }

            spider->updatePlayerFrame(GameManager::get()->getPlayerSpider(), IconType::Spider);
            spider->setColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor()));
            spider->setSecondColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor2()));
            if (GameManager::get()->getPlayerGlow()) {
                spider->setGlowOutline(GameManager::get()->colorForIdx(GameManager::get()->getPlayerGlowColor()));
            } else {
                spider->disableGlowOutline();
            }

            swing->updatePlayerFrame(GameManager::get()->getPlayerSwing(), IconType::Swing);
            swing->setColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor()));
            swing->setSecondColor(GameManager::get()->colorForIdx(GameManager::get()->getPlayerColor2()));
            if (GameManager::get()->getPlayerGlow()) {
                swing->setGlowOutline(GameManager::get()->colorForIdx(GameManager::get()->getPlayerGlowColor()));
            } else {
                swing->disableGlowOutline();
            }
        } else {
            cube->updatePlayerFrame(PlayerData::player2Cube, IconType::Cube);
            cube->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            cube->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                cube->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                cube->disableGlowOutline();
            }

            ship->updatePlayerFrame(PlayerData::player2Ship, IconType::Ship);
            ship->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            ship->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                ship->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                ship->disableGlowOutline();
            }

            ball->updatePlayerFrame(PlayerData::player2Roll, IconType::Ball);
            ball->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            ball->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                ball->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                ball->disableGlowOutline();
            }

            ufo->updatePlayerFrame(PlayerData::player2Bird, IconType::Ufo);
            ufo->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            ufo->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                ufo->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                ufo->disableGlowOutline();
            }

            wave->updatePlayerFrame(PlayerData::player2Dart, IconType::Wave);
            wave->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            wave->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                wave->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                wave->disableGlowOutline();
            }

            robot->updatePlayerFrame(PlayerData::player2Robot, IconType::Robot);
            robot->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            robot->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                robot->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                robot->disableGlowOutline();
            }

            spider->updatePlayerFrame(PlayerData::player2Spider, IconType::Spider);
            spider->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            spider->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                spider->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                spider->disableGlowOutline();
            }

            swing->updatePlayerFrame(PlayerData::player2Swing, IconType::Swing);
            swing->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            swing->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                swing->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                swing->disableGlowOutline();
            }
        }
    };

    bool init(int accountID, bool ownProfile) {
        if (!ProfilePage::init(accountID, ownProfile)) return false;

        if (ownProfile) {
            auto layer = as<CCLayer*>(this->getChildren()->objectAtIndex(0));
            auto winSize = CCDirector::get()->getWinSize();

            auto menu = CCMenu::create();
            layer->addChild(menu);
            menu->setID("right-menu");
            menu->setContentSize({32.2f, 90.f});
            menu->setTouchPriority(-504);
            menu->setZOrder(10);
            menu->setPosition({winSize.width - layer->getChildByID("left-menu")->getPositionX(), layer->getChildByID("left-menu")->getPositionY()});
            menu->setLayout(
                ColumnLayout::create()
                    ->setAxisReverse(true)
                    ->setAxisAlignment(AxisAlignment::End)
                    ->setGap(6.f)
            );

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

        return true;
    }
};