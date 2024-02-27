#include "PlayerData.hpp"
#include <Geode/modify/GJGarageLayer.hpp>

int page;
IconType type;

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
        

        return true;
    }

    void setupPage(int p1, IconType p2) {
        GJGarageLayer::setupPage(p1, p2);
        log::info("balls");
        
        page = p1;
        type = p2;
        if (p1 == -1) page = 0;

        auto winSize = CCDirector::get()->getWinSize();

        auto iconBar = getChildOfType<ListButtonBar>(this, 0);
        auto menu = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(iconBar, 0), 0), 0), 0);
        CCMenu* menu2 = nullptr;

        if (p2 == IconType::Special) 
            menu2 = getChildOfType<CCMenu>(getChildOfType<ListButtonPage>(getChildOfType<ExtendedLayer>(getChildOfType<BoomScrollLayer>(getChildOfType<ListButtonBar>(iconBar, 0), 0), 0), 0), 0);
        
        int tag = 0;
        int tag2 = 0;

        switch (p2) {
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

        log::warn("{} {} {}", tag, tag2, menu->getChildrenCount());
        if (menu) {
            if (menu->getChildByTag(tag)) {
                cursor1->setVisible(true);
                cursor1->setPosition({menu->getChildByTag(tag)->getPositionX() + winSize.width/2, menu->getChildByTag(tag)->getPositionY() + winSize.height/2});
            } else {
                cursor1->setVisible(false);
            }
        }

        if (menu2) {
            if (menu2->getChildByTag(tag2)) {
                cursor2->setVisible(true);
                cursor2->setPosition({menu2->getChildByTag(tag2)->getPositionX() + winSize.width/2, menu2->getChildByTag(tag2)->getPositionY() + winSize.height/2});
            } else {
                cursor2->setVisible(false);
            }
        }

    }


    void onSelect(CCObject* sender) {
        int n = sender->getTag();
        if (PlayerData::player2Selected && GameManager::get()->isIconUnlocked(n, type)) {
            auto player2 = as<SimplePlayer*>(this->getChildByID("player2-icon"));
            auto winSize = CCDirector::get()->getWinSize();
            bool isShipTrail = false;


            if (as<int>(type) < 10) {
                player2->updatePlayerFrame(n, type);
            }


            switch (type) {
                case IconType::Cube:
                    Mod::get()->setSettingValue<int64_t>("cube", n);
                    break;
                case IconType::Ship:
                    Mod::get()->setSettingValue<int64_t>("ship", n);
                    break;
                case IconType::Ball:
                    Mod::get()->setSettingValue<int64_t>("roll", n);
                    break;
                case IconType::Ufo:
                    Mod::get()->setSettingValue<int64_t>("bird", n);
                    break;
                case IconType::Wave:
                    Mod::get()->setSettingValue<int64_t>("dart", n);
                    break;
                case IconType::Robot:
                    Mod::get()->setSettingValue<int64_t>("robot", n);
                    break;
                case IconType::Spider:
                    Mod::get()->setSettingValue<int64_t>("spider", n);
                    break;
                case IconType::Swing:
                    Mod::get()->setSettingValue<int64_t>("swing", n);
                    break;
                case IconType::Jetpack:
                    Mod::get()->setSettingValue<int64_t>("jetpack", n);
                    break;
                case IconType::Special:
                    if (as<CCNode*>(sender)->getParent()->getChildrenCount() == 7) {
                        Mod::get()->setSettingValue<int64_t>("trail", n);
                    } else if (as<CCNode*>(sender)->getParent()->getChildrenCount() == 6) {
                        Mod::get()->setSettingValue<int64_t>("shiptrail", n);
                        isShipTrail = true;
                    }
                    break;
                case IconType::DeathEffect:
                    Mod::get()->setSettingValue<int64_t>("death", n);
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

        } else {
            GJGarageLayer::onSelect(sender);

        }

        log::error("{} {}", as<int>(type), sender->getTag());
    }
};