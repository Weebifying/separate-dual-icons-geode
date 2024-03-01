#include "PlayerData.hpp"
#include <Geode/modify/GJGarageLayer.hpp>



class $modify(MyGarageLayer, GJGarageLayer) {
    int page;
    IconType type;
    
    void on2PToggle(CCObject* sender) {
        auto btn = as<CCMenuItemToggler*>(sender);
        PlayerData::player2Selected = !btn->isOn();

        auto winSize = CCDirector::get()->getWinSize();

        auto iconBar = getChildOfType<ListButtonBar>(this, 0);

        auto menu = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(iconBar, 0), 0), 0), 0);
        CCMenu* menu2 = nullptr;
        if (m_fields->type == IconType::Special) 
            menu2 = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(getChildOfType<ListButtonBar>(iconBar, 0), 0), 0), 0), 0);

        auto cursor1 = this->getChildByID("cursor-1");
        auto cursor2 = this->getChildByID("cursor-2");

        if (PlayerData::player2Selected) {
            
            int tag = 0;
            int tag2 = 0;

            as<CCSprite*>(cursor1)->setColor({0, 255, 255});
            as<CCSprite*>(cursor2)->setColor({0, 255, 255});

            switch (m_fields->type) {
                case IconType::Cube:
                    tag = PlayerData::player2Cube;
                    break;
                case IconType::Ship:
                    tag = PlayerData::player2Ship;
                    break;
                case IconType::Ball:
                    tag = PlayerData::player2Roll;
                    break;
                case IconType::Ufo:
                    tag = PlayerData::player2Bird;
                    break;
                case IconType::Wave:
                    tag = PlayerData::player2Dart;
                    break;
                case IconType::Robot:
                    tag = PlayerData::player2Robot;
                    break;
                case IconType::Spider:
                    tag = PlayerData::player2Spider;
                    break;
                case IconType::Swing:
                    tag = PlayerData::player2Swing;
                    break;
                case IconType::Jetpack:
                    tag = PlayerData::player2Jetpack;
                    break;
                case IconType::Special:
                    tag = PlayerData::player2Trail;
                    tag2 = PlayerData::player2ShipTrail;
                    break;
                case IconType::DeathEffect:
                    tag = PlayerData::player2Death;
                    break;
                default:
                    break;
            }

            bool tagIsHere = false;
            bool tag2IsHere = false;

            // i cant use getChildByTag bc crashes lol
            if (menu) {
                CCArrayExt<CCMenuItemSpriteExtra*> children = menu->getChildren();
                for (auto* child : children) {
                    if (child->getTag() == tag) {
                        tagIsHere = true;
                        cursor1->setVisible(true);
                        cursor1->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                    }
                }
                if (!tagIsHere) cursor1->setVisible(false);
            }

            if (menu2) {
                CCArrayExt<CCMenuItemSpriteExtra*> children2 = menu2->getChildren();
                for (auto* child : children2) {
                    if (child->getTag() == tag2) {
                        tag2IsHere = true;
                        cursor2->setVisible(true);
                        cursor2->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                    }
                }
                if (!tag2IsHere) cursor2->setVisible(false);
            }

            this->getChildByID("arrow-1")->setVisible(false);
            this->getChildByID("arrow-2")->setVisible(true);

        } else {
            int tag = 0;
            int tag2 = 0;

            as<CCSprite*>(cursor1)->setColor({255, 255, 0});
            as<CCSprite*>(cursor2)->setColor({255, 255, 0});

            switch (m_fields->type) {
                case IconType::Cube:
                    tag = GameManager::get()->getPlayerFrame();
                    break;
                case IconType::Ship:
                    tag = GameManager::get()->getPlayerShip();
                    break;
                case IconType::Ball:
                    tag = GameManager::get()->getPlayerBall();
                    break;
                case IconType::Ufo:
                    tag = GameManager::get()->getPlayerBird();
                    break;
                case IconType::Wave:
                    tag = GameManager::get()->getPlayerDart();
                    break;
                case IconType::Robot:
                    tag = GameManager::get()->getPlayerRobot();
                    break;
                case IconType::Spider:
                    tag = GameManager::get()->getPlayerSpider();
                    break;
                case IconType::Swing:
                    tag = GameManager::get()->getPlayerSwing();
                    break;
                case IconType::Jetpack:
                    tag = GameManager::get()->getPlayerJetpack();
                    break;
                case IconType::Special:
                    tag = GameManager::get()->getPlayerStreak();
                    tag2 = GameManager::get()->getPlayerShipFire();
                    break;
                case IconType::DeathEffect:
                    tag = GameManager::get()->getPlayerDeathEffect();
                    break;
                default:
                    break;
            }

            bool tagIsHere = false;
            bool tag2IsHere = false;

            // i cant use getChildByTag bc crashes lol
            if (menu) {
                CCArrayExt<CCMenuItemSpriteExtra*> children = menu->getChildren();
                for (auto* child : children) {
                    if (child->getTag() == tag) {
                        tagIsHere = true;
                        cursor1->setVisible(true);
                        cursor1->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                    }
                }
                if (!tagIsHere) cursor1->setVisible(false);
            }

            if (menu2) {
                CCArrayExt<CCMenuItemSpriteExtra*> children2 = menu2->getChildren();
                for (auto* child : children2) {
                    if (child->getTag() == tag2) {
                        tag2IsHere = true;
                        cursor2->setVisible(true);
                        cursor2->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                    }
                }
                if (!tag2IsHere) cursor2->setVisible(false);
            }

            this->getChildByID("arrow-1")->setVisible(true);
            this->getChildByID("arrow-2")->setVisible(false);

        }
    }

    bool init() {
        PlayerData::player2Selected = false;
        m_fields->page = 0;
        m_fields->type = IconType::Cube;

		if (!GJGarageLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();


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

        as<CCSprite*>(this->getChildByID("cursor-1"))->setColor({255, 255, 0});

        SimplePlayer* player1 = as<SimplePlayer*>(this->getChildByID("player-icon"));
        player1->setPositionX(player1->getPositionX() - winSize.width/12);
        player1->updatePlayerFrame(GameManager::get()->getPlayerFrame(), IconType::Cube);

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


        auto arrow1 = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
        auto arrow2 = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");

        arrow1->setScale(0.4f);
        arrow1->setPosition({player1->getPositionX() - winSize.width/12, player1->getPositionY()});
        arrow1->setID("arrow-1");

        arrow2->setScale(0.4f);
        arrow2->setFlipX(true);
        arrow2->setPosition({player2->getPositionX() + winSize.width/12, player2->getPositionY()});
        arrow2->setID("arrow-2");

        arrow2->setVisible(false);

        auto actions1 = CCArray::create();
        actions1->addObject(CCMoveBy::create(0.5, {5, 0}));
        actions1->addObject(CCMoveBy::create(0.5, {-5, 0}));

        auto actions2 = CCArray::create();
        actions2->addObject(CCMoveBy::create(0.5, {-5, 0}));
        actions2->addObject(CCMoveBy::create(0.5, {5, 0}));

        arrow1->runAction(CCRepeatForever::create(CCSequence::create(actions1)));
        arrow2->runAction(CCRepeatForever::create(CCSequence::create(actions2)));

        this->addChild(arrow1);
        this->addChild(arrow2);

        return true;
    }

    void setupPage(int p1, IconType p2) {
        GJGarageLayer::setupPage(p1, p2);
        
        m_fields->page = p1;
        m_fields->type = p2;
        if (p1 == -1) m_fields->page = 0;

        if (PlayerData::player2Selected) {
            auto winSize = CCDirector::get()->getWinSize();

            auto iconBar = getChildOfType<ListButtonBar>(this, 0);
            auto menu = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(iconBar, 0), 0), 0), 0);
            CCMenu* menu2 = nullptr;

            if (m_fields->type == IconType::Special) 
                menu2 = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(getChildOfType<ListButtonBar>(iconBar, 0), 0), 0), 0), 0);
            
            int tag = 0;
            int tag2 = 0;

            switch (m_fields->type) {
                case IconType::Cube:
                    tag = PlayerData::player2Cube;
                    break;
                case IconType::Ship:
                    tag = PlayerData::player2Ship;
                    break;
                case IconType::Ball:
                    tag = PlayerData::player2Roll;
                    break;
                case IconType::Ufo:
                    tag = PlayerData::player2Bird;
                    break;
                case IconType::Wave:
                    tag = PlayerData::player2Dart;
                    break;
                case IconType::Robot:
                    tag = PlayerData::player2Robot;
                    break;
                case IconType::Spider:
                    tag = PlayerData::player2Spider;
                    break;
                case IconType::Swing:
                    tag = PlayerData::player2Swing;
                    break;
                case IconType::Jetpack:
                    tag = PlayerData::player2Jetpack;
                    break;
                case IconType::Special:
                    tag = PlayerData::player2Trail;
                    tag2 = PlayerData::player2ShipTrail;
                    break;
                case IconType::DeathEffect:
                    tag = PlayerData::player2Death;
                    break;
                default:
                    break;
            }

            auto cursor1 = this->getChildByID("cursor-1");
            auto cursor2 = this->getChildByID("cursor-2");

            bool tagIsHere = false;
            bool tag2IsHere = false;

            // i cant use getChildByTag bc crashes lol
            if (menu) {
                CCArrayExt<CCMenuItemSpriteExtra*> children = menu->getChildren();
                for (auto* child : children) {
                    if (child->getTag() == tag) {
                        tagIsHere = true;
                        cursor1->setVisible(true);
                        cursor1->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                    }
                }
                if (!tagIsHere) cursor1->setVisible(false);
            }

            if (menu2) {
                CCArrayExt<CCMenuItemSpriteExtra*> children2 = menu2->getChildren();
                for (auto* child : children2) {
                    if (child->getTag() == tag2) {
                        tag2IsHere = true;
                        cursor2->setVisible(true);
                        cursor2->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                    }
                }
                if (!tag2IsHere) cursor2->setVisible(false);
            }
        }
    }

    void onSelect(CCObject* sender) {
        int n = sender->getTag();
        if (PlayerData::player2Selected && GameManager::get()->isIconUnlocked(n, m_fields->type)) {
            auto player2 = as<SimplePlayer*>(this->getChildByID("player2-icon"));
            auto winSize = CCDirector::get()->getWinSize();
            bool isShipTrail = false;


            if (as<int>(m_fields->type) < 10) {
                player2->updatePlayerFrame(n, m_fields->type);
                player2->updateColors();
            }

            switch (m_fields->type) {
                case IconType::Cube:
                    Mod::get()->setSavedValue<int64_t>("cube", n);
                    PlayerData::player2Cube = n;
                    player2->setScale(1.6f);
                    break;
                case IconType::Ship:
                    Mod::get()->setSavedValue<int64_t>("ship", n);
                    PlayerData::player2Ship = n;
                    player2->setScale(1.6f);
                    break;
                case IconType::Ball:
                    Mod::get()->setSavedValue<int64_t>("roll", n);
                    PlayerData::player2Roll = n;
                    player2->setScale(1.6f);
                    break;
                case IconType::Ufo:
                    Mod::get()->setSavedValue<int64_t>("bird", n);
                    PlayerData::player2Bird = n;
                    player2->setScale(1.6f);
                    break;
                case IconType::Wave:
                    Mod::get()->setSavedValue<int64_t>("dart", n);
                    PlayerData::player2Dart = n;
                    player2->setScale(1.6f);
                    break;
                case IconType::Robot:
                    Mod::get()->setSavedValue<int64_t>("robot", n);
                    PlayerData::player2Robot = n;
                    player2->setScale(1.6f);
                    break;
                case IconType::Spider:
                    Mod::get()->setSavedValue<int64_t>("spider", n);
                    PlayerData::player2Spider = n;
                    player2->setScale(1.6f);
                    break;
                case IconType::Swing:
                    Mod::get()->setSavedValue<int64_t>("swing", n);
                    PlayerData::player2Swing = n;
                    player2->setScale(1.6f);
                    break;
                case IconType::Jetpack:
                    Mod::get()->setSavedValue<int64_t>("jetpack", n);
                    PlayerData::player2Jetpack = n;
                    player2->setScale(1.5f);
                    break;
                case IconType::Special:
                    if (as<CCNode*>(sender)->getParent()->getChildrenCount() == 7) {
                        Mod::get()->setSavedValue<int64_t>("trail", n);
                        PlayerData::player2Trail = n;
                    } else if (as<CCNode*>(sender)->getParent()->getChildrenCount() == 6) {
                        Mod::get()->setSavedValue<int64_t>("shiptrail", n);
                        PlayerData::player2ShipTrail = n;
                        isShipTrail = true;
                    }
                    break;
                case IconType::DeathEffect:
                    Mod::get()->setSavedValue<int64_t>("death", n);
                    PlayerData::player2Death = n;
                    break;
                default:
                    log::error("what the hell lmao");
                    break;
            }

            CCNode* cursor;
            if (isShipTrail) 
                cursor = this->getChildByID("cursor-2");
            else
                cursor = this->getChildByID("cursor-1");

            cursor->setPosition({as<CCNode*>(sender)->getPositionX() + winSize.width/2, as<CCNode*>(sender)->getPositionY() + winSize.height/2});
            cursor->setVisible(true);

        } else {
            GJGarageLayer::onSelect(sender);

        }
    }
};