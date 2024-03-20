#include "PlayerData.hpp"
#include <Geode/modify/GJGarageLayer.hpp>



class $modify(MyGarageLayer, GJGarageLayer) {
    int page;
    IconType type;
    
    void on2PToggle(CCObject* sender) {
        auto btn = as<CCMenuItemSpriteExtra*>(sender);
        if (btn->getID() == "player1-button") Mod::get()->setSavedValue<bool>("2pselected", false);
        else Mod::get()->setSavedValue<bool>("2pselected", true);

        auto GM = GameManager::get();
        auto winSize = CCDirector::get()->getWinSize();

        auto iconBar = getChildOfType<ListButtonBar>(this, 0);

        auto menu = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(iconBar, 0), 0), 0), 0);
        CCMenu* menu2 = nullptr;
        if (m_fields->type == IconType::Special) 
            menu2 = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(getChildOfType<ListButtonBar>(iconBar, 0), 0), 0), 0), 0);

        auto cursor1 = this->getChildByID("cursor-1");
        auto cursor2 = this->getChildByID("cursor-2");

        if (Mod::get()->getSavedValue<bool>("2pselected", false)) {
            
            int tag = 0;
            int tag2 = 0;

            as<CCSprite*>(cursor1)->setColor({0, 255, 255});
            as<CCSprite*>(cursor2)->setColor({0, 255, 255});

            switch (m_fields->type) {
                case IconType::Cube:
                    tag = Mod::get()->getSavedValue<int64_t>("cube", 1);
                    break;
                case IconType::Ship:
                    tag = Mod::get()->getSavedValue<int64_t>("ship", 1);
                    break;
                case IconType::Ball:
                    tag = Mod::get()->getSavedValue<int64_t>("roll", 1);
                    break;
                case IconType::Ufo:
                    tag = Mod::get()->getSavedValue<int64_t>("bird", 1);
                    break;
                case IconType::Wave:
                    tag = Mod::get()->getSavedValue<int64_t>("dart", 1);
                    break;
                case IconType::Robot:
                    tag = Mod::get()->getSavedValue<int64_t>("robot", 1);
                    break;
                case IconType::Spider:
                    tag = Mod::get()->getSavedValue<int64_t>("spider", 1);
                    break;
                case IconType::Swing:
                    tag = Mod::get()->getSavedValue<int64_t>("swing", 1);
                    break;
                case IconType::Jetpack:
                    tag = Mod::get()->getSavedValue<int64_t>("jetpack", 1);
                    break;
                case IconType::Special:
                    tag = Mod::get()->getSavedValue<int64_t>("trail", 1);
                    tag2 = Mod::get()->getSavedValue<int64_t>("shiptrail", 1);
                    break;
                case IconType::DeathEffect:
                    tag = Mod::get()->getSavedValue<int64_t>("death", 1);
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
                    tag = GM->getPlayerFrame();
                    break;
                case IconType::Ship:
                    tag = GM->getPlayerShip();
                    break;
                case IconType::Ball:
                    tag = GM->getPlayerBall();
                    break;
                case IconType::Ufo:
                    tag = GM->getPlayerBird();
                    break;
                case IconType::Wave:
                    tag = GM->getPlayerDart();
                    break;
                case IconType::Robot:
                    tag = GM->getPlayerRobot();
                    break;
                case IconType::Spider:
                    tag = GM->getPlayerSpider();
                    break;
                case IconType::Swing:
                    tag = GM->getPlayerSwing();
                    break;
                case IconType::Jetpack:
                    tag = GM->getPlayerJetpack();
                    break;
                case IconType::Special:
                    tag = GM->getPlayerStreak();
                    tag2 = GM->getPlayerShipFire();
                    break;
                case IconType::DeathEffect:
                    tag = GM->getPlayerDeathEffect();
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
        Mod::get()->setSavedValue<bool>("2pselected", false);
        m_fields->page = 0;
        m_fields->type = IconType::Cube;

		if (!GJGarageLayer::init()) return false;

        auto GM = GameManager::get();
        auto winSize = CCDirector::get()->getWinSize();

        as<CCSprite*>(this->getChildByID("cursor-1"))->setColor({255, 255, 0});
        as<CCSprite*>(this->getChildByID("cursor-2"))->setColor({255, 255, 0});

        SimplePlayer* player1 = as<SimplePlayer*>(this->getChildByID("player-icon"));
        player1->setPositionX(player1->getPositionX() - winSize.width/12);

        auto player2 = SimplePlayer::create(0);
        player2->setID("player2-icon");
        player2->setScale(1.6f);
        player2->setPosition(player1->getPosition());
        player2->setPositionX(player2->getPositionX() + winSize.width/6);

        player2->setColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
        player2->setSecondColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));

        if (Mod::get()->getSavedValue<bool>("glow", false)) {
            player2->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
        } else {
            player2->disableGlowOutline();
        }

        switch (Mod::get()->getSavedValue<int64_t>("lasttype", 0)) {
            case 0:
                player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("cube", 1), IconType::Cube);
                break;
            case 1:
                player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("ship", 1), IconType::Ship);
                break;
            case 2:
                player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("roll", 1), IconType::Ball);
                break;
            case 3:
                player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("bird", 1), IconType::Ufo);
                break;
            case 4:
                player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("dart", 1), IconType::Wave);
                break;
            case 5:
                player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("robot", 1), IconType::Robot);
                break;
            case 6:
                player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("spider", 1), IconType::Spider);
                break;
            case 7:
                player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("swing", 1), IconType::Swing);
                break;
            case 8:
                player2->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("jetpack", 1), IconType::Jetpack);
                break;
        }

        player2->updateColors();
        this->addChild(player2);


        auto playerMenu = CCMenu::create();
        playerMenu->setContentSize(winSize);
        playerMenu->setPosition({0, 0});
        playerMenu->setID("player-buttons-menu");
        this->addChild(playerMenu);

        auto sprite = CCSprite::create("GJ_button_01.png");
        sprite->setOpacity(0);
        auto button1 = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(MyGarageLayer::on2PToggle));
        auto button2 = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(MyGarageLayer::on2PToggle));

        button1->setPosition(player1->getPosition());
        button2->setPosition(player2->getPosition());
        button1->setContentSize({70.f, 50.f});
        button1->setID("player1-button");
        button2->setContentSize({70.f, 50.f});
        button2->setID("player2-button");

        playerMenu->addChild(button1);
        playerMenu->addChild(button2);


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

        if (Mod::get()->getSavedValue<bool>("2pselected", false)) {
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
                    tag = Mod::get()->getSavedValue<int64_t>("cube", 1);
                    break;
                case IconType::Ship:
                    tag = Mod::get()->getSavedValue<int64_t>("ship", 1);
                    break;
                case IconType::Ball:
                    tag = Mod::get()->getSavedValue<int64_t>("roll", 1);
                    break;
                case IconType::Ufo:
                    tag = Mod::get()->getSavedValue<int64_t>("bird", 1);
                    break;
                case IconType::Wave:
                    tag = Mod::get()->getSavedValue<int64_t>("dart", 1);
                    break;
                case IconType::Robot:
                    tag = Mod::get()->getSavedValue<int64_t>("robot", 1);
                    break;
                case IconType::Spider:
                    tag = Mod::get()->getSavedValue<int64_t>("spider", 1);
                    break;
                case IconType::Swing:
                    tag = Mod::get()->getSavedValue<int64_t>("swing", 1);
                    break;
                case IconType::Jetpack:
                    tag = Mod::get()->getSavedValue<int64_t>("jetpack", 1);
                    break;
                case IconType::Special:
                    tag = Mod::get()->getSavedValue<int64_t>("trail", 1);
                    tag2 = Mod::get()->getSavedValue<int64_t>("shiptrail", 1);
                    break;
                case IconType::DeathEffect:
                    tag = Mod::get()->getSavedValue<int64_t>("death", 1);
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
        auto GM = GameManager::get();

        int n = sender->getTag();
        bool hehe = GM->isIconUnlocked(n, m_fields->type);
        if (m_fields->type == IconType::Special) 
            hehe = true;
        
        // same death effect cuz not working rn :(
        if (Mod::get()->getSavedValue<bool>("2pselected", false) &&  hehe  && m_fields->type != IconType::DeathEffect) {
            auto player2 = as<SimplePlayer*>(this->getChildByID("player2-icon"));
            auto winSize = CCDirector::get()->getWinSize();
            bool isShipTrail = false;


            if (as<int>(m_fields->type) < 10) {
                player2->updatePlayerFrame(n, m_fields->type);
                player2->updateColors();
            }

            switch (m_fields->type) {
                case IconType::Cube:
                    if (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 0 || Mod::get()->getSavedValue<int64_t>("cube", 1) != n) {
                        Mod::get()->setSavedValue<int64_t>("cube", n);
                        Mod::get()->setSavedValue<int64_t>("lasttype", 0);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Cube);
                        return;
                    }
                    break;
                case IconType::Ship:
                    if (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 1 || Mod::get()->getSavedValue<int64_t>("ship", 1) != n) {
                        Mod::get()->setSavedValue<int64_t>("ship", n);
                        Mod::get()->setSavedValue<int64_t>("lasttype", 1);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Ship);
                        return;
                    }
                    break;
                case IconType::Ball:
                    if (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 2 || Mod::get()->getSavedValue<int64_t>("roll", 1) != n) {
                        Mod::get()->setSavedValue<int64_t>("roll", n);
                        Mod::get()->setSavedValue<int64_t>("lasttype", 2);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Ball);
                        return;
                    }
                    break;
                case IconType::Ufo:
                    if (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 3 || Mod::get()->getSavedValue<int64_t>("bird", 1) != n) {
                        Mod::get()->setSavedValue<int64_t>("bird", n);
                        Mod::get()->setSavedValue<int64_t>("lasttype", 3);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Bird);
                        return;
                    }
                    break;
                case IconType::Wave:
                    if (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 4 || Mod::get()->getSavedValue<int64_t>("dart", 1) != n) {
                        Mod::get()->setSavedValue<int64_t>("dart", n);
                        Mod::get()->setSavedValue<int64_t>("lasttype", 4);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Dart);
                        return;
                    }
                    break;
                case IconType::Robot:
                    if (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 5 || Mod::get()->getSavedValue<int64_t>("robot", 1) != n) {
                        Mod::get()->setSavedValue<int64_t>("robot", n);
                        Mod::get()->setSavedValue<int64_t>("lasttype", 5);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Robot);
                        return;
                    }
                    break;
                case IconType::Spider:
                    if (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 6 || Mod::get()->getSavedValue<int64_t>("spider", 1) != n) {
                        Mod::get()->setSavedValue<int64_t>("spider", n);
                        Mod::get()->setSavedValue<int64_t>("lasttype", 6);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Spider);
                        return;
                    }
                    break;
                case IconType::Swing:
                    if (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 7 || Mod::get()->getSavedValue<int64_t>("swing", 1) != n) {
                        Mod::get()->setSavedValue<int64_t>("swing", n);
                        Mod::get()->setSavedValue<int64_t>("lasttype", 7);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Swing);
                        return;
                    }
                    break;
                case IconType::Jetpack:
                    if (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 8 || Mod::get()->getSavedValue<int64_t>("jetpack", 1) != n) {
                        Mod::get()->setSavedValue<int64_t>("jetpack", n);
                        Mod::get()->setSavedValue<int64_t>("lasttype", 8);
                        player2->setScale(1.5f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Jetpack);
                        return;
                    }
                    break;
                case IconType::Special:
                    if (as<CCNode*>(sender)->getParent()->getChildrenCount() == 7) {
                        if (GM->isIconUnlocked(n, IconType::Special) && (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 99 || Mod::get()->getSavedValue<int64_t>("trail", 1) != n)) {
                            Mod::get()->setSavedValue<int64_t>("trail", n);
                            Mod::get()->setSavedValue<int64_t>("lasttype", 99);
                            } else {
                            GJGarageLayer::showUnlockPopup(n, UnlockType::Streak);
                            return; 
                        }
                    } else if (as<CCNode*>(sender)->getParent()->getChildrenCount() == 6) {
                        if (GM->isIconUnlocked(n, IconType::ShipFire) && (Mod::get()->getSavedValue<int64_t>("lasttype", 0) != 101 || Mod::get()->getSavedValue<int64_t>("shiptrail", 1) != n)) {
                            Mod::get()->setSavedValue<int64_t>("shiptrail", n);
                            Mod::get()->setSavedValue<int64_t>("lasttype", 101);
                                isShipTrail = true;
                        } else {
                            GJGarageLayer::showUnlockPopup(n, UnlockType::ShipFire);
                            return;
                        }
                    }
                    break;
                // case IconType::DeathEffect:
                //     GM->setPlayerDeathEffect(n);
                //     Mod::get()->setSavedValue<int64_t>("death", n);
                //     break;
                default:
                    log::error("what the hell lmao");
                    break;
            }

            if (as<int>(m_fields->type) < 10) {
                player2->updatePlayerFrame(n, m_fields->type);
                player2->updateColors();
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