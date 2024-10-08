#include "PlayerData.hpp"
#include "Macros.hpp"
#include <Geode/modify/GJGarageLayer.hpp>

class $modify(MyGarageLayer, GJGarageLayer) {
    struct Fields {
        int page;
        IconType type;
    };
    
    void on2PToggle(CCObject* sender) {
        auto btn = as<CCMenuItemSpriteExtra*>(sender);
        if (btn->getID() == "player1-button") GDI_SET_VALUE(bool, "2pselected", false);
        else GDI_SET_VALUE(bool, "2pselected", true);

        auto GM = GameManager::get();
        auto winSize = CCDirector::get()->getWinSize();

        auto iconBar = getChildOfType<ListButtonBar>(this, 0);

        auto menu = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(iconBar, 0), 0), 0), 0);
        CCMenu* menu2 = nullptr;
        if (m_fields->type == IconType::Special) 
            menu2 = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(getChildOfType<ListButtonBar>(iconBar, 0), 0), 0), 0), 0);

        auto cursor1 = this->getChildByID("cursor-1");
        auto cursor2 = this->getChildByID("cursor-2");

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            
            int tag = 0;
            int tag2 = 0;

            as<CCSprite*>(cursor1)->setColor({0, 255, 255});
            as<CCSprite*>(cursor2)->setColor({0, 255, 255});

            switch (m_fields->type) {
                case IconType::Cube:
                    tag = GDI_GET_VALUE(int64_t, "cube", 1);
                    break;
                case IconType::Ship:
                    tag = GDI_GET_VALUE(int64_t, "ship", 1);
                    break;
                case IconType::Ball:
                    tag = GDI_GET_VALUE(int64_t, "roll", 1);
                    break;
                case IconType::Ufo:
                    tag = GDI_GET_VALUE(int64_t, "bird", 1);
                    break;
                case IconType::Wave:
                    tag = GDI_GET_VALUE(int64_t, "dart", 1);
                    break;
                case IconType::Robot:
                    tag = GDI_GET_VALUE(int64_t, "robot", 1);
                    break;
                case IconType::Spider:
                    tag = GDI_GET_VALUE(int64_t, "spider", 1);
                    break;
                case IconType::Swing:
                    tag = GDI_GET_VALUE(int64_t, "swing", 1);
                    break;
                case IconType::Jetpack:
                    tag = GDI_GET_VALUE(int64_t, "jetpack", 1);
                    break;
                case IconType::Special:
                    tag = GDI_GET_VALUE(int64_t, "trail", 1);
                    tag2 = GDI_GET_VALUE(int64_t, "shiptrail", 1);
                    break;
                case IconType::DeathEffect:
                    tag = GDI_GET_VALUE(int64_t, "death", 1);
                    getChildOfType<CCMenuItemToggler>(getChildOfType<CCMenu>(iconBar, 0), 0)->toggle(GDI_GET_VALUE(bool, "deathexplode", false));
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
                    getChildOfType<CCMenuItemToggler>(getChildOfType<CCMenu>(iconBar, 0), 0)->toggle(GM->getGameVariable("0153"));
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

    void swap2PKit(CCObject* sender) {
        auto GM = GameManager::get();
        GDI_SET_VALUE(bool, "2pselected", !GDI_GET_VALUE(bool, "2pselected", false));
        GDI_GET_VALUE(bool, "2pselected", false) ? GDI_SET_VALUE(bool, "2pselected", false) : GDI_SET_VALUE(bool, "2pselected", true);

        int oldCube = GM->getPlayerFrame();
        int oldShip = GM->getPlayerShip();
        int oldRoll = GM->getPlayerBall();
        int oldBird = GM->getPlayerBird();
        int oldDart = GM->getPlayerDart();
        int oldRobot = GM->getPlayerRobot();
        int oldSpider = GM->getPlayerSpider();
        int oldSwing = GM->getPlayerSwing();
        int oldJetpack = GM->getPlayerJetpack();
        int oldTrail = GM->getPlayerStreak();
        int oldShipTrail = GM->getPlayerShipFire();
        int oldDeath = GM->getPlayerDeathEffect();
        bool oldDeathExplode = GM->getGameVariable("0153");
        int oldColor1 = GM->getPlayerColor();
        int oldColor2 = GM->getPlayerColor2();
        int oldColorGlow = GM->getPlayerGlowColor();
        bool oldGlow = GM->getPlayerGlow();

        GM->setPlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1));
        GM->setPlayerShip(GDI_GET_VALUE(int64_t, "ship", 1));
        GM->setPlayerBall(GDI_GET_VALUE(int64_t, "roll", 1));
        GM->setPlayerBird(GDI_GET_VALUE(int64_t, "bird", 1));
        GM->setPlayerDart(GDI_GET_VALUE(int64_t, "dart", 1));
        GM->setPlayerRobot(GDI_GET_VALUE(int64_t, "robot", 1));
        GM->setPlayerSpider(GDI_GET_VALUE(int64_t, "spider", 1));
        GM->setPlayerSwing(GDI_GET_VALUE(int64_t, "swing", 1));
        GM->setPlayerJetpack(GDI_GET_VALUE(int64_t, "jetpack", 1));
        GM->setPlayerStreak(GDI_GET_VALUE(int64_t, "trail", 1));
        GM->setPlayerShipStreak(GDI_GET_VALUE(int64_t, "shiptrail", 1));
        GM->setPlayerDeathEffect(GDI_GET_VALUE(int64_t, "death", 1));
        GM->setGameVariable("0153", GDI_GET_VALUE(bool, "deathexplode", false));
        GM->setPlayerColor(GDI_GET_VALUE(int64_t, "color1", 0));
        GM->setPlayerColor2(GDI_GET_VALUE(int64_t, "color2", 0));
        GM->setPlayerColor3(GDI_GET_VALUE(int64_t, "colorglow", 0));
        GM->setPlayerGlow(GDI_GET_VALUE(bool, "glow", false));

        GDI_SET_VALUE(int64_t, "cube", oldCube);
        GDI_SET_VALUE(int64_t, "ship", oldShip);
        GDI_SET_VALUE(int64_t, "roll", oldRoll);
        GDI_SET_VALUE(int64_t, "bird", oldBird);
        GDI_SET_VALUE(int64_t, "dart", oldDart);
        GDI_SET_VALUE(int64_t, "robot", oldRobot);
        GDI_SET_VALUE(int64_t, "spider", oldSpider);
        GDI_SET_VALUE(int64_t, "swing", oldSwing);
        GDI_SET_VALUE(int64_t, "jetpack", oldJetpack);
        GDI_SET_VALUE(int64_t, "trail", oldTrail);
        GDI_SET_VALUE(int64_t, "shiptrail", oldShipTrail);
        GDI_SET_VALUE(int64_t, "death", oldDeath);
        GDI_SET_VALUE(bool, "deathexplode", oldDeathExplode);
        GDI_SET_VALUE(int64_t, "color1", oldColor1);
        GDI_SET_VALUE(int64_t, "color2", oldColor2);
        GDI_SET_VALUE(int64_t, "colorglow", oldColorGlow);
        GDI_SET_VALUE(bool, "glow", oldGlow);

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            this->getChildByID("arrow-1")->setVisible(false);
            this->getChildByID("arrow-2")->setVisible(true);
        } else {
            this->getChildByID("arrow-1")->setVisible(true);
            this->getChildByID("arrow-2")->setVisible(false);
        }

        auto cursor1 = as<CCSprite*>(this->getChildByID("cursor-1"));
        auto cursor2 = as<CCSprite*>(this->getChildByID("cursor-2"));

        if (cursor1->getColor() == ccColor3B({255, 255, 0})) {
            cursor1->setColor({0, 255, 255});
            cursor2->setColor({0, 255, 255});
        } else if (cursor1->getColor() == ccColor3B({0, 255, 255})) {
            cursor1->setColor({255, 255, 0});
            cursor2->setColor({255, 255, 0});            
        }


        auto player1 = as<SimplePlayer*>(this->getChildByID("player-icon"));
        auto player2 = as<SimplePlayer*>(this->getChildByID("player2-icon"));
        switch ((int)GM->m_playerIconType) {
            case 0:
                player1->updatePlayerFrame(GM->m_playerFrame, IconType::Cube);
                break;
            case 1:
                player1->updatePlayerFrame(GM->m_playerShip, IconType::Ship);
                break;
            case 2:
                player1->updatePlayerFrame(GM->m_playerBall, IconType::Ball);
                break;
            case 3:
                player1->updatePlayerFrame(GM->m_playerBird, IconType::Ufo);
                break;
            case 4:
                player1->updatePlayerFrame(GM->m_playerDart, IconType::Wave);
                break;
            case 5:
                player1->updatePlayerFrame(GM->m_playerRobot, IconType::Robot);
                break;
            case 6:
                player1->updatePlayerFrame(GM->m_playerSpider, IconType::Spider);
                break;
            case 7:
                player1->updatePlayerFrame(GM->m_playerSwing, IconType::Swing);
                break;
            case 8:
                player1->updatePlayerFrame(GM->m_playerJetpack, IconType::Jetpack);
                break;
        }
        player1->setColor(GM->colorForIdx(GM->m_playerColor));
        player1->setSecondColor(GM->colorForIdx(GM->m_playerColor2));
        player1->setGlowOutline(GM->colorForIdx(GM->m_playerGlowColor));
        if (!GM->m_playerGlow) player1->disableGlowOutline();

        switch (Mod::get()->getSavedValue("lastmode", 0)) {
            case 0:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1), IconType::Cube);
                break;
            case 1:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                break;
            case 2:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "roll", 1), IconType::Ball);
                break;
            case 3:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "bird", 1), IconType::Ufo);
                break;
            case 4:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "dart", 1), IconType::Wave);
                break;
            case 5:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "robot", 1), IconType::Robot);
                break;
            case 6:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "spider", 1), IconType::Spider);
                break;
            case 7:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "swing", 1), IconType::Swing);
                break;
            case 8:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
                break;
        }
        player2->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
        player2->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
        player2->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
        if (!GDI_GET_VALUE(bool, "glow", false)) player2->disableGlowOutline();


    }

    void onSpecialRep(CCObject* sender) {
        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            Mod::get()->setSavedValue<bool>("deathexplode", !as<CCMenuItemToggler*>(sender)->isOn());
        } else {
            GameManager::get()->toggleGameVariable("0153");
        }
    }

    bool init() {
        GDI_SET_VALUE(bool, "2pselected", false);
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

        player2->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
        player2->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));

        if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
            player2->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
        } else {
            player2->disableGlowOutline();
        }

        // first time initiation loooool
        // god i write such shit code
        if (GDI_GET_VALUE(int64_t, "lasttype", 0) < 90
        && GDI_GET_VALUE(int64_t, "lastmode", 0) == 0) {
            GDI_SET_VALUE(int64_t, "lasttype", 0);
        }

        switch (GDI_GET_VALUE(int64_t, "lastmode", 0)) {
            case 0:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1), IconType::Cube);
                break;
            case 1:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                break;
            case 2:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "roll", 1), IconType::Ball);
                break;
            case 3:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "bird", 1), IconType::Ufo);
                break;
            case 4:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "dart", 1), IconType::Wave);
                break;
            case 5:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "robot", 1), IconType::Robot);
                break;
            case 6:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "spider", 1), IconType::Spider);
                break;
            case 7:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "swing", 1), IconType::Swing);
                break;
            case 8:
                player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
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

    
        auto swapSprite = CircleButtonSprite::createWithSprite("GJ_2PSwapBtn.png"_spr, 0.95, CircleBaseColor::Green, CircleBaseSize::Small);
        auto swapBtn = CCMenuItemSpriteExtra::create(swapSprite, this, menu_selector(MyGarageLayer::swap2PKit));
        swapBtn->setID("swap-2p-button");
        this->getChildByID("shards-menu")->addChild(swapBtn);
        this->getChildByID("shards-menu")->updateLayout();


        // i might actually kill myself if omgrod fucks me up again
        // if (Loader::get()->isModLoaded("omgrod.garage_plus")) {
        //     if (auto garageMod = Loader::get()->getLoadedMod("omgrod.garage_plus")) {
        //         if (garageMod->getSettingValue<bool>("top-buttons") && garageMod->getSettingValue<bool>("no-lock-hint")) {
        //             player2->setPositionY(player2->getPositionY() - winSize.height/12);
        //             arrow1->setPositionY(arrow1->getPositionY() - winSize.height/12);
        //             arrow2->setPositionY(arrow2->getPositionY() - winSize.height/12);
        //             playerMenu->setPositionY(playerMenu->getPositionY() - winSize.height/12);
        //         }
        //     }
        // }

        return true;
    }

    void setupPage(int p1, IconType p2) {
        GJGarageLayer::setupPage(p1, p2);
        
        m_fields->page = p1;
        m_fields->type = p2;
        if (p1 == -1) m_fields->page = 0;

        auto iconBar = getChildOfType<ListButtonBar>(this, 0);
        // DELETE WHEN TULIPHOOK IS FIXED
        if (p2 == IconType::DeathEffect) {
            auto bruh = getChildOfType<CCMenuItemToggler>(getChildOfType<CCMenu>(iconBar, 0), 0);
            
            auto spriteOn = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
            auto spriteOff = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
            spriteOn->setScale(0.6f);
            spriteOff->setScale(0.6f);
            auto repToggler = CCMenuItemToggler::create(
                spriteOn,
                spriteOff,
                this,
                menu_selector(MyGarageLayer::onSpecialRep)
            );
            repToggler->toggle(GameManager::get()->getGameVariable("0153"));

            repToggler->setPosition(bruh->getPosition());
            repToggler->setTag(bruh->getTag());
            repToggler->setZOrder(bruh->getZOrder());
            repToggler->setScale(bruh->getScale());
            repToggler->setContentSize(bruh->getContentSize());
            repToggler->setID("xd");

            bruh->getParent()->addChild(repToggler);
            bruh->removeFromParent();
        }

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            auto winSize = CCDirector::get()->getWinSize();

            auto menu = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(iconBar, 0), 0), 0), 0);
            CCMenu* menu2 = nullptr;

            if (m_fields->type == IconType::Special) 
                menu2 = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(getChildOfType<ListButtonBar>(iconBar, 0), 0), 0), 0), 0);
            
            int tag = 0;
            int tag2 = 0;

            switch (m_fields->type) {
                case IconType::Cube:
                    tag = GDI_GET_VALUE(int64_t, "cube", 1);
                    break;
                case IconType::Ship:
                    tag = GDI_GET_VALUE(int64_t, "ship", 1);
                    break;
                case IconType::Ball:
                    tag = GDI_GET_VALUE(int64_t, "roll", 1);
                    break;
                case IconType::Ufo:
                    tag = GDI_GET_VALUE(int64_t, "bird", 1);
                    break;
                case IconType::Wave:
                    tag = GDI_GET_VALUE(int64_t, "dart", 1);
                    break;
                case IconType::Robot:
                    tag = GDI_GET_VALUE(int64_t, "robot", 1);
                    break;
                case IconType::Spider:
                    tag = GDI_GET_VALUE(int64_t, "spider", 1);
                    break;
                case IconType::Swing:
                    tag = GDI_GET_VALUE(int64_t, "swing", 1);
                    break;
                case IconType::Jetpack:
                    tag = GDI_GET_VALUE(int64_t, "jetpack", 1);
                    break;
                case IconType::Special:
                    tag = GDI_GET_VALUE(int64_t, "trail", 1);
                    tag2 = GDI_GET_VALUE(int64_t, "shiptrail", 1);
                    break;
                case IconType::DeathEffect:
                    tag = GDI_GET_VALUE(int64_t, "death", 1);
                    getChildOfType<CCMenuItemToggler>(getChildOfType<CCMenu>(iconBar, 0), 0)->toggle(GDI_GET_VALUE(bool, "deathexplode", false));
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
        bool isUnlocked = GM->isIconUnlocked(n, m_fields->type);
        if (m_fields->type == IconType::Special) 
            isUnlocked = true;
        
        // same death effect cuz not working rn :(
        if (
            GDI_GET_VALUE(bool, "2pselected", false)
            && isUnlocked
            // && m_fields->type != IconType::DeathEffect
        ) {
            auto player2 = as<SimplePlayer*>(this->getChildByID("player2-icon"));
            auto winSize = CCDirector::get()->getWinSize();
            bool isShipTrail = false;


            if (as<int>(m_fields->type) < 10) {
                player2->updatePlayerFrame(n, m_fields->type);
                player2->updateColors();
            }

            switch (m_fields->type) {
                case IconType::Cube:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 0 || GDI_GET_VALUE(int64_t, "cube", 1) != n) {
                        GDI_SET_VALUE(int64_t, "cube", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 0);
                        GDI_SET_VALUE(int64_t, "lastmode", 0);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Cube);
                        return;
                    }
                    break;
                case IconType::Ship:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 1 || GDI_GET_VALUE(int64_t, "ship", 1) != n) {
                        GDI_SET_VALUE(int64_t, "ship", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 1);
                        GDI_SET_VALUE(int64_t, "lastmode", 1);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Ship);
                        return;
                    }
                    break;
                case IconType::Ball:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 2 || GDI_GET_VALUE(int64_t, "roll", 1) != n) {
                        GDI_SET_VALUE(int64_t, "roll", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 2);
                        GDI_SET_VALUE(int64_t, "lastmode", 2);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Ball);
                        return;
                    }
                    break;
                case IconType::Ufo:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 3 || GDI_GET_VALUE(int64_t, "bird", 1) != n) {
                        GDI_SET_VALUE(int64_t, "bird", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 3);
                        GDI_SET_VALUE(int64_t, "lastmode", 3);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Bird);
                        return;
                    }
                    break;
                case IconType::Wave:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 4 || GDI_GET_VALUE(int64_t, "dart", 1) != n) {
                        GDI_SET_VALUE(int64_t, "dart", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 4);
                        GDI_SET_VALUE(int64_t, "lastmode", 4);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Dart);
                        return;
                    }
                    break;
                case IconType::Robot:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 5 || GDI_GET_VALUE(int64_t, "robot", 1) != n) {
                        GDI_SET_VALUE(int64_t, "robot", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 5);
                        GDI_SET_VALUE(int64_t, "lastmode", 5);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Robot);
                        return;
                    }
                    break;
                case IconType::Spider:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 6 || GDI_GET_VALUE(int64_t, "spider", 1) != n) {
                        GDI_SET_VALUE(int64_t, "spider", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 6);
                        GDI_SET_VALUE(int64_t, "lastmode", 6);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Spider);
                        return;
                    }
                    break;
                case IconType::Swing:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 7 || GDI_GET_VALUE(int64_t, "swing", 1) != n) {
                        GDI_SET_VALUE(int64_t, "swing", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 7);
                        GDI_SET_VALUE(int64_t, "lastmode", 7);
                        player2->setScale(1.6f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Swing);
                        return;
                    }
                    break;
                case IconType::Jetpack:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 8 || GDI_GET_VALUE(int64_t, "jetpack", 1) != n) {
                        GDI_SET_VALUE(int64_t, "jetpack", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 8);
                        GDI_SET_VALUE(int64_t, "lastmode", 8);
                        player2->setScale(1.5f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Jetpack);
                        return;
                    }
                    break;
                case IconType::Special:
                    // please dont shit on me this is the only way LOL
                    if (as<CCNode*>(sender)->getParent()->getParent()->getParent()->getParent()->getParent()->getParent()->getID() == "GJGarageLayer") {
                        if (GM->isIconUnlocked(n, IconType::Special) && (GDI_GET_VALUE(int64_t, "lasttype", 0) != 99 || GDI_GET_VALUE(int64_t, "trail", 1) != n)) {
                            GDI_SET_VALUE(int64_t, "trail", n);
                            GDI_SET_VALUE(int64_t, "lasttype", 99);
                        } else {    
                            GJGarageLayer::showUnlockPopup(n, UnlockType::Streak);
                            return; 
                        }
                    } else if (as<CCNode*>(sender)->getParent()->getParent()->getParent()->getParent()->getParent()->getParent()->getParent()->getID() == "GJGarageLayer") {
                        if (GM->isIconUnlocked(n, IconType::ShipFire) && (GDI_GET_VALUE(int64_t, "lasttype", 0) != 101 || GDI_GET_VALUE(int64_t, "shiptrail", 1) != n)) {
                            GDI_SET_VALUE(int64_t, "shiptrail", n);
                            GDI_SET_VALUE(int64_t, "lasttype", 101);
                            isShipTrail = true;
                        } else {
                            GJGarageLayer::showUnlockPopup(n, UnlockType::ShipFire);
                            return;
                        }
                    }
                    break;
                case IconType::DeathEffect:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 98 || GDI_GET_VALUE(int64_t, "death", 1) != n) {
                        GDI_SET_VALUE(int64_t, "death", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 98);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Death);
                        return;
                    }
                    break;
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