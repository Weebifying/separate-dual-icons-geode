#include "PlayerData.hpp"
#include "Macros.hpp"
#include <Geode/modify/ProfilePage.hpp>


class $modify(MyProfilePage, ProfilePage) {
    struct Fields {
        // make ship/jetpack toggle
        bool hasLoaded = false;
    };
    
    static void onModify(auto& self) {
        self.setHookPriority("CharacterColorPage::loadPageFromUserInfo", 1000000);
    }

    void toggleShip(CCObject* sender) {
        ProfilePage::toggleShip(sender);

        auto ship = getChildOfType<SimplePlayer>(as<CCNode*>(sender), 0);
        auto GM = GameManager::get();

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            switch (sender->getTag()) {
                case 1:
                    ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Ship);
                    break;
                case 8:
                    ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Jetpack);
                    break;
                default:
                    log::error("huh???");
                    break;
            }

        }
    }

    void on2PToggle(CCObject* sender) {
        auto GM = GameManager::get();

        auto menu = m_mainLayer->getChildByID("player-menu");
        auto isAnimated = Loader::get()->isModLoaded("thesillydoggo.animatedprofiles");
        auto BUI = Loader::get()->isModLoaded("rynat.better_unlock_info");

        auto shipType = (IconType)menu->getChildByID("player-ship")->getTag();
        auto cube = getChildOfType<SimplePlayer>(menu->getChildByID("player-icon"), 0);
        auto ship = getChildOfType<SimplePlayer>(menu->getChildByID("player-ship"), 0);
        auto ball = getChildOfType<SimplePlayer>(menu->getChildByID("player-ball"), 0);
        auto ufo = getChildOfType<SimplePlayer>(menu->getChildByID("player-ufo"), 0);
        auto wave = getChildOfType<SimplePlayer>(menu->getChildByID("player-wave"), 0);
        CCNode* robotNode = nullptr;
        CCNode* spiderNode = nullptr;
        if (isAnimated && !BUI) {
            robotNode = menu->getChildByID("player-robot")->getChildByID("player-robot");
            spiderNode = menu->getChildByID("player-spider")->getChildByID("player-spider");
        } else {
            robotNode = menu->getChildByID("player-robot");
            spiderNode = menu->getChildByID("player-spider");
        }
        auto robot = getChildOfType<SimplePlayer>(robotNode, 0);
        auto spider = getChildOfType<SimplePlayer>(spiderNode, 0);
        auto swing = getChildOfType<SimplePlayer>(menu->getChildByID("player-swing"), 0);
        
        //BUI added
        
        SimplePlayer* jetpack = nullptr;
        if (BUI && menu->getChildByID("player-jetpack"))
            jetpack = getChildOfType<SimplePlayer>(menu->getChildByID("player-jetpack"), 0);
        //

        if (as<CCMenuItemToggler*>(sender)->isOn()) {
            GDI_SET_VALUE(bool, "2pselected", false);

            cube->updatePlayerFrame(GM->getPlayerFrame(), IconType::Cube);
            cube->setColor(GM->colorForIdx(GM->getPlayerColor()));
            cube->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                cube->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                cube->disableGlowOutline();
            }

            /*
            if (m_fields->shipType == IconType::Ship) ship->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
            else ship->updatePlayerFrame(GM->getPlayerJetpack(), IconType::Jetpack);
            ship->setColor(GM->colorForIdx(GM->getPlayerColor()));
            ship->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            if (GM->getPlayerGlow()) {
                ship->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
            } else {
                ship->disableGlowOutline();
            }
            */
            //BUI added
            if (jetpack) {
                ship->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
                jetpack->updatePlayerFrame(GM->getPlayerJetpack(), IconType::Jetpack);
                
                jetpack->setColor(GM->colorForIdx(GM->getPlayerColor()));
                jetpack->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) {
                    jetpack->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                } else {
                    jetpack->disableGlowOutline();
                }
            } else if (!BUI) {
                if (shipType == IconType::Ship) ship->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
                else ship->updatePlayerFrame(GM->getPlayerJetpack(), IconType::Jetpack);
            }
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
            GDI_SET_VALUE(bool, "2pselected", true);

            cube->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1), IconType::Cube);
            cube->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            cube->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                cube->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            } else {
                cube->disableGlowOutline();
            }

            /*
            if (m_fields->shipType == IconType::Ship) ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
            else ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
            ship->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            ship->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                ship->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            } else {
                ship->disableGlowOutline();
            }
            */
            //BUI added
            if (jetpack) {
                ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                jetpack->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
                
                jetpack->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
                jetpack->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
                if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                    jetpack->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
                } else {
                    jetpack->disableGlowOutline();
                }
            } else if (!BUI) {
                if (shipType == IconType::Ship) ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                else ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
            }
            ship->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            ship->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                ship->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            } else {
                ship->disableGlowOutline();
            }
            //

            ball->updatePlayerFrame(GDI_GET_VALUE(int64_t, "roll", 1), IconType::Ball);
            ball->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            ball->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                ball->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            } else {
                ball->disableGlowOutline();
            }

            ufo->updatePlayerFrame(GDI_GET_VALUE(int64_t, "bird", 1), IconType::Ufo);
            ufo->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            ufo->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                ufo->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            } else {
                ufo->disableGlowOutline();
            }

            wave->updatePlayerFrame(GDI_GET_VALUE(int64_t, "dart", 1), IconType::Wave);
            wave->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            wave->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                wave->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            } else {
                wave->disableGlowOutline();
            }

            robot->updatePlayerFrame(GDI_GET_VALUE(int64_t, "robot", 1), IconType::Robot);
            robot->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            robot->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                robot->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            } else {
                robot->disableGlowOutline();
            }

            spider->updatePlayerFrame(GDI_GET_VALUE(int64_t, "spider", 1), IconType::Spider);
            spider->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            spider->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                spider->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            } else {
                spider->disableGlowOutline();
            }

            swing->updatePlayerFrame(GDI_GET_VALUE(int64_t, "swing", 1), IconType::Swing);
            swing->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
            swing->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
            if (GDI_GET_VALUE(bool, "glow", false) || GDI_GET_VALUE(int64_t, "color1", 0) == 15) {
                swing->setGlowOutline(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
            } else {
                swing->disableGlowOutline();
            }
        }
    };

    // static ProfilePage* create(int p0, bool p1) {
    //     auto res = ProfilePage::create(p0, p1);
    //     log::error("ProfilePage:create");
    //     return res;
    // }

    // void setupCommentsBrowser(cocos2d::CCArray* p0) {
    //     ProfilePage::setupCommentsBrowser(p0);
    //     log::info("ProfilePage::setupCommentsBrowser");
    // }

    void loadPageFromUserInfo(GJUserScore* p0){
        ProfilePage::loadPageFromUserInfo(p0);
        // log::warn("ProfilePage::loadPageFromUserInfo");
        GDI_SET_VALUE(bool, "2pselected", false);

        auto GM = GameManager::get();

        if (this->m_ownProfile) {
            if (auto menu = m_mainLayer->getChildByID("player-menu")) {
                SimplePlayer* player = nullptr;

                player = as<SimplePlayer*>(menu->getChildByID("player-icon")->getChildByID("player-icon"));
                player->updatePlayerFrame(GM->getPlayerFrame(), IconType::Cube);
                player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) player->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                else player->disableGlowOutline();

                player = as<SimplePlayer*>(as<CCMenuItemSpriteExtra*>(menu->getChildByID("player-ship"))->getNormalImage());
                player->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
                player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) player->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                else player->disableGlowOutline();

                player = as<SimplePlayer*>(menu->getChildByID("player-ball")->getChildByID("player-ball"));
                player->updatePlayerFrame(GM->getPlayerBall(), IconType::Ball);
                player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) player->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                else player->disableGlowOutline();

                player = as<SimplePlayer*>(menu->getChildByID("player-ufo")->getChildByID("player-ufo"));
                player->updatePlayerFrame(GM->getPlayerBird(), IconType::Ufo);
                player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) player->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                else player->disableGlowOutline();

                player = as<SimplePlayer*>(menu->getChildByID("player-wave")->getChildByID("player-wave"));
                player->updatePlayerFrame(GM->getPlayerDart(), IconType::Wave);
                player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) player->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                else player->disableGlowOutline();

                player = as<SimplePlayer*>(menu->getChildByID("player-robot")->getChildByID("player-robot"));
                player->updatePlayerFrame(GM->getPlayerRobot(), IconType::Robot);
                player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) player->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                else player->disableGlowOutline();

                player = as<SimplePlayer*>(menu->getChildByID("player-spider")->getChildByID("player-spider"));
                player->updatePlayerFrame(GM->getPlayerSpider(), IconType::Spider);
                player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) player->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                else player->disableGlowOutline();

                player = as<SimplePlayer*>(menu->getChildByID("player-swing")->getChildByID("player-swing"));
                player->updatePlayerFrame(GM->getPlayerSwing(), IconType::Swing);
                player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                if (GM->getPlayerGlow()) player->setGlowOutline(GM->colorForIdx(GM->getPlayerGlowColor()));
                else player->disableGlowOutline();

            }
        }
        
        if (this->m_ownProfile && !m_fields->hasLoaded) {
            
            m_fields->hasLoaded = true;
            auto winSize = CCDirector::get()->getWinSize();

            if (auto menu = m_mainLayer->getChildByID("left-menu")) {
                
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
