#include "Macros.hpp"
#include <Geode/modify/GJGarageLayer.hpp>

using namespace geode::prelude;

class $modify(MyGarageLayer, GJGarageLayer) {
    struct Fields {
        CCSprite* arrow1;
        CCSprite* arrow2;
        SimplePlayer* player2;
    };

    static void onModify(auto& self) {
        (void)self.setHookPriority("GJGarageLayer::onSelect", Priority::Replace);
        (void)self.setHookPriority("GJGarageLayer::onSpecial", Priority::Replace);
    }

    void on2PToggle(CCObject* sender) {
        GDI_SET_VALUE(bool, "2pselected", static_cast<CCNode*>(sender)->getID() == "player2-button");

        auto GM = GameManager::get();
        auto winSize = CCDirector::get()->getWinSize();

        auto menu = static_cast<CCNode*>(m_iconSelection->m_pages->objectAtIndex(0))->getChildByType<CCMenu>(0);
        CCMenu* menu2 = nullptr;
        if (m_iconType == IconType::Special)
            menu2 = static_cast<CCNode*>(m_iconSelection->getChildByType<ListButtonBar>(0)->m_pages->objectAtIndex(0))->getChildByType<CCMenu>(0);

        if (GDI_GET_VALUE(bool, "2pselected", false)) {

            int tag = 0;
            int tag2 = 0;

            m_cursor1->setColor({0, 255, 255});
            m_cursor2->setColor({0, 255, 255});

            switch (m_iconType) {
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
                    m_iconSelection->getChildByType<CCMenu>(0)->getChildByType<CCMenuItemToggler>(0)->toggle(GDI_GET_VALUE(bool, "deathexplode", false));
                    break;
                default:
                    break;
            }

            if (menu) {
                if (auto child = menu->getChildByTag(tag)) {
                    m_cursor1->setVisible(true);
                    m_cursor1->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                }
                else m_cursor1->setVisible(false);
            }

            if (menu2) {
                if (auto child = menu2->getChildByTag(tag2)) {
                    m_cursor2->setVisible(true);
                    m_cursor2->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                }
                else m_cursor2->setVisible(false);
            }

            m_fields->arrow1->setVisible(false);
            m_fields->arrow2->setVisible(true);

        } else {
            int tag = 0;
            int tag2 = 0;

            m_cursor1->setColor({255, 255, 0});
            m_cursor2->setColor({255, 255, 0});

            switch (m_iconType) {
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
                    m_iconSelection->getChildByType<CCMenu>(0)->getChildByType<CCMenuItemToggler>(0)->toggle(GM->getGameVariable("0153"));
                    break;
                default:
                    break;
            }

            if (menu) {
                if (auto child = menu->getChildByTag(tag)) {
                    m_cursor1->setVisible(true);
                    m_cursor1->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                }
                else m_cursor1->setVisible(false);
            }

            if (menu2) {
                if (auto child = menu2->getChildByTag(tag2)) {
                    m_cursor2->setVisible(true);
                    m_cursor2->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                }
                else m_cursor2->setVisible(false);
            }

            m_fields->arrow1->setVisible(true);
            m_fields->arrow2->setVisible(false);

        }
    }

    void swap2PKit(CCObject* sender) {
        auto GM = GameManager::get();

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
            m_fields->arrow1->setVisible(false);
            m_fields->arrow2->setVisible(true);
        } else {
            m_fields->arrow1->setVisible(true);
            m_fields->arrow2->setVisible(false);
        }

        if (m_cursor1->getColor() == ccColor3B({255, 255, 0})) {
            m_cursor1->setColor({0, 255, 255});
            m_cursor2->setColor({0, 255, 255});
        } else if (m_cursor1->getColor() == ccColor3B({0, 255, 255})) {
            m_cursor1->setColor({255, 255, 0});
            m_cursor2->setColor({255, 255, 0});
        }


        switch ((int)GM->m_playerIconType) {
            case 0:
                m_playerObject->updatePlayerFrame(GM->m_playerFrame, IconType::Cube);
                break;
            case 1:
                m_playerObject->updatePlayerFrame(GM->m_playerShip, IconType::Ship);
                break;
            case 2:
                m_playerObject->updatePlayerFrame(GM->m_playerBall, IconType::Ball);
                break;
            case 3:
                m_playerObject->updatePlayerFrame(GM->m_playerBird, IconType::Ufo);
                break;
            case 4:
                m_playerObject->updatePlayerFrame(GM->m_playerDart, IconType::Wave);
                break;
            case 5:
                m_playerObject->updatePlayerFrame(GM->m_playerRobot, IconType::Robot);
                break;
            case 6:
                m_playerObject->updatePlayerFrame(GM->m_playerSpider, IconType::Spider);
                break;
            case 7:
                m_playerObject->updatePlayerFrame(GM->m_playerSwing, IconType::Swing);
                break;
            case 8:
                m_playerObject->updatePlayerFrame(GM->m_playerJetpack, IconType::Jetpack);
                break;
        }
        m_playerObject->setColor(GM->colorForIdx(GM->m_playerColor));
        m_playerObject->setSecondColor(GM->colorForIdx(GM->m_playerColor2));
        m_playerObject->enableCustomGlowColor(GM->colorForIdx(GM->m_playerGlowColor));
        m_playerObject->m_hasGlowOutline = GM->m_playerGlow;
        m_playerObject->updateColors();

        switch (GDI_GET_VALUE(int64_t, "lastmode", 0)) {
            case 0:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1), IconType::Cube);
                break;
            case 1:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                break;
            case 2:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "roll", 1), IconType::Ball);
                break;
            case 3:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "bird", 1), IconType::Ufo);
                break;
            case 4:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "dart", 1), IconType::Wave);
                break;
            case 5:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "robot", 1), IconType::Robot);
                break;
            case 6:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "spider", 1), IconType::Spider);
                break;
            case 7:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "swing", 1), IconType::Swing);
                break;
            case 8:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
                break;
        }
        m_fields->player2->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
        m_fields->player2->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
        m_fields->player2->enableCustomGlowColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
        m_fields->player2->m_hasGlowOutline = GDI_GET_VALUE(bool, "glow", false);
        m_fields->player2->updateColors();


    }

    void onSpecial(CCObject* sender) {
        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            GDI_SET_VALUE(bool, "deathexplode", !static_cast<CCMenuItemToggler*>(sender)->isOn());
        } else {
            GJGarageLayer::onSpecial(sender);
        }
    }

    bool init() {
        GDI_SET_VALUE(bool, "2pselected", false);
        if (!GJGarageLayer::init()) return false;

        auto GM = GameManager::get();
        auto winSize = CCDirector::get()->getWinSize();

        m_cursor1->setColor({255, 255, 0});
        m_cursor2->setColor({255, 255, 0});

        m_playerObject->setPositionX(m_playerObject->getPositionX() - winSize.width/12);

        m_fields->player2 = SimplePlayer::create(0);
        m_fields->player2->setID("player2-icon");
        m_fields->player2->setScale(1.6f);
        m_fields->player2->setPosition(m_playerObject->getPosition());
        m_fields->player2->setPositionX(m_fields->player2->getPositionX() + winSize.width/6);

        m_fields->player2->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
        m_fields->player2->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
        m_fields->player2->enableCustomGlowColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
        m_fields->player2->m_hasGlowOutline = GDI_GET_VALUE(bool, "glow", false);
        m_fields->player2->updateColors();

        // first time initiation loooool
        // god i write such shit code
        if (GDI_GET_VALUE(int64_t, "lasttype", 0) < 90
        && GDI_GET_VALUE(int64_t, "lastmode", 0) == 0) {
            GDI_SET_VALUE(int64_t, "lasttype", 0);
        }

        switch (GDI_GET_VALUE(int64_t, "lastmode", 0)) {
            case 0:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1), IconType::Cube);
                break;
            case 1:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                break;
            case 2:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "roll", 1), IconType::Ball);
                break;
            case 3:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "bird", 1), IconType::Ufo);
                break;
            case 4:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "dart", 1), IconType::Wave);
                break;
            case 5:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "robot", 1), IconType::Robot);
                break;
            case 6:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "spider", 1), IconType::Spider);
                break;
            case 7:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "swing", 1), IconType::Swing);
                break;
            case 8:
                m_fields->player2->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
                break;
        }

        m_fields->player2->updateColors();
        this->addChild(m_fields->player2);


        auto playerMenu = CCMenu::create();
        playerMenu->setContentSize(winSize);
        playerMenu->setPosition({0, 0});
        playerMenu->setID("player-buttons-menu");
        this->addChild(playerMenu);

        auto sprite = CCSprite::create("GJ_button_01.png");
        sprite->setOpacity(0);
        auto button1 = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(MyGarageLayer::on2PToggle));
        auto button2 = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(MyGarageLayer::on2PToggle));

        button1->setPosition(m_playerObject->getPosition());
        button2->setPosition(m_fields->player2->getPosition());
        button1->setContentSize({70.f, 50.f});
        button1->setID("player1-button");
        button2->setContentSize({70.f, 50.f});
        button2->setID("player2-button");

        playerMenu->addChild(button1);
        playerMenu->addChild(button2);


        m_fields->arrow1 = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");
        m_fields->arrow2 = CCSprite::createWithSpriteFrameName("navArrowBtn_001.png");

        m_fields->arrow1->setScale(0.4f);
        m_fields->arrow1->setPosition({m_playerObject->getPositionX() - winSize.width/12, m_playerObject->getPositionY()});
        m_fields->arrow1->setID("arrow-1");

        m_fields->arrow2->setScale(0.4f);
        m_fields->arrow2->setFlipX(true);
        m_fields->arrow2->setPosition({m_fields->player2->getPositionX() + winSize.width/12, m_fields->player2->getPositionY()});
        m_fields->arrow2->setID("arrow-2");

        m_fields->arrow2->setVisible(false);

        auto actions1 = CCArray::create();
        actions1->addObject(CCMoveBy::create(0.5, {5, 0}));
        actions1->addObject(CCMoveBy::create(0.5, {-5, 0}));

        auto actions2 = CCArray::create();
        actions2->addObject(CCMoveBy::create(0.5, {-5, 0}));
        actions2->addObject(CCMoveBy::create(0.5, {5, 0}));

        m_fields->arrow1->runAction(CCRepeatForever::create(CCSequence::create(actions1)));
        m_fields->arrow2->runAction(CCRepeatForever::create(CCSequence::create(actions2)));

        this->addChild(m_fields->arrow1);
        this->addChild(m_fields->arrow2);


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

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            auto winSize = CCDirector::get()->getWinSize();

            auto menu = static_cast<CCNode*>(m_iconSelection->m_pages->objectAtIndex(0))->getChildByType<CCMenu>(0);
            CCMenu* menu2 = nullptr;

            if (m_iconType == IconType::Special)
                menu2 = static_cast<CCNode*>(m_iconSelection->getChildByType<ListButtonBar>(0)->m_pages->objectAtIndex(0))->getChildByType<CCMenu>(0);

            int tag = 0;
            int tag2 = 0;

            switch (m_iconType) {
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
                    m_iconSelection->getChildByType<CCMenu>(0)->getChildByType<CCMenuItemToggler>(0)->toggle(GDI_GET_VALUE(bool, "deathexplode", false));
                    break;
                default:
                    break;
            }

            if (menu) {
                if (auto child = menu->getChildByTag(tag)) {
                    m_cursor1->setVisible(true);
                    m_cursor1->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                }
                else m_cursor1->setVisible(false);
            }

            if (menu2) {
                if (auto child = menu2->getChildByTag(tag2)) {
                    m_cursor2->setVisible(true);
                    m_cursor2->setPosition({child->getPositionX() + winSize.width/2, child->getPositionY() + winSize.height/2});
                }
                else m_cursor2->setVisible(false);
            }
        }
    }

    void onSelect(CCObject* sender) {
        auto GM = GameManager::get();

        int n = sender->getTag();
        bool isUnlocked = GM->isIconUnlocked(n, m_iconType);
        if (m_iconType == IconType::Special)
            isUnlocked = true;

        // same death effect cuz not working rn :(
        if (
            GDI_GET_VALUE(bool, "2pselected", false)
            && isUnlocked
            // && m_fields->type != IconType::DeathEffect
        ) {
            auto winSize = CCDirector::get()->getWinSize();
            bool isShipTrail = false;


            if (static_cast<int>(m_iconType) < 10) {
                m_fields->player2->updatePlayerFrame(n, m_iconType);
                m_fields->player2->updateColors();
            }

            switch (m_iconType) {
                case IconType::Cube:
                    if (GDI_GET_VALUE(int64_t, "lasttype", 0) != 0 || GDI_GET_VALUE(int64_t, "cube", 1) != n) {
                        GDI_SET_VALUE(int64_t, "cube", n);
                        GDI_SET_VALUE(int64_t, "lasttype", 0);
                        GDI_SET_VALUE(int64_t, "lastmode", 0);
                        m_fields->player2->setScale(1.6f);
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
                        m_fields->player2->setScale(1.6f);
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
                        m_fields->player2->setScale(1.6f);
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
                        m_fields->player2->setScale(1.6f);
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
                        m_fields->player2->setScale(1.6f);
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
                        m_fields->player2->setScale(1.6f);
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
                        m_fields->player2->setScale(1.6f);
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
                        m_fields->player2->setScale(1.6f);
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
                        m_fields->player2->setScale(1.5f);
                    } else {
                        GJGarageLayer::showUnlockPopup(n, UnlockType::Jetpack);
                        return;
                    }
                    break;
                case IconType::Special:
                    if (static_cast<CCMenuItemSpriteExtra*>(sender)->m_iconType == IconType::Special) {
                        if (GM->isIconUnlocked(n, IconType::Special) && (GDI_GET_VALUE(int64_t, "lasttype", 0) != 99 || GDI_GET_VALUE(int64_t, "trail", 1) != n)) {
                            GDI_SET_VALUE(int64_t, "trail", n);
                            GDI_SET_VALUE(int64_t, "lasttype", 99);
                        } else {
                            GJGarageLayer::showUnlockPopup(n, UnlockType::Streak);
                            return;
                        }
                    } else if (static_cast<CCMenuItemSpriteExtra*>(sender)->m_iconType == IconType::ShipFire) {
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

            if (static_cast<int>(m_iconType) < 10) {
                m_fields->player2->updatePlayerFrame(n, m_iconType);
                m_fields->player2->updateColors();
            }

            auto cursor = isShipTrail ? m_cursor2 : m_cursor1;

            cursor->setPosition({static_cast<CCNode*>(sender)->getPositionX() + winSize.width/2, static_cast<CCNode*>(sender)->getPositionY() + winSize.height/2});
            cursor->setVisible(true);

        } else {
            GJGarageLayer::onSelect(sender);
        }
    }

    void updatePlayerColors() {
        GJGarageLayer::updatePlayerColors();

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            auto GM = GameManager::get();
            m_fields->player2->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            m_fields->player2->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            m_fields->player2->enableCustomGlowColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            m_fields->player2->m_hasGlowOutline = GDI_GET_VALUE(bool, "glow", false);
            m_fields->player2->updateColors();
        }
    }
};