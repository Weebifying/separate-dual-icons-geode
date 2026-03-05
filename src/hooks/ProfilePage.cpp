#include "Macros.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(MyProfilePage, ProfilePage) {
    struct Fields {
        // make ship/jetpack toggle
        bool hasLoaded = false;
    };

    static void onModify(auto& self) {
        Result<> result = self.setHookPriorityBefore("ProfilePage::loadPageFromUserInfo", "rynat.better_unlock_info");
        if (!result && *result.err() != "Mod not found") log::error("Failed to set hook priority. Glow colors may break on the jetpack with Better Unlock Info.");
    }

    void toggleShip(CCObject* sender) {
        ProfilePage::toggleShip(sender);

        auto ship = static_cast<SimplePlayer*>(static_cast<CCMenuItemSprite*>(sender)->getNormalImage());
        auto GM = GameManager::get();

        if (SDI_GET_VALUE(bool, "2pselected", false)) {
            switch (sender->getTag()) {
                case 1:
                    ship->updatePlayerFrame(SDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                    break;
                case 8:
                    ship->updatePlayerFrame(SDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
                    break;
            }
        } else {
            switch (sender->getTag()) {
                case 1:
                    ship->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
                    break;
                case 8:
                    ship->updatePlayerFrame(GM->getPlayerJetpack(), IconType::Jetpack);
                    break;
            }
        }
    }

    SimplePlayer* getPlayer(CCNode* node) {
        return findFirstChildRecursive<SimplePlayer>(node, [](auto) { return true; });
    }

    void on2PToggle(CCObject* sender) {
        auto GM = GameManager::get();

        auto menu = m_mainLayer->getChildByID("player-menu");

        auto shipType = (IconType)menu->getChildByID("player-ship")->getTag();
        auto cube = getPlayer(menu->getChildByID("player-icon"));
        auto ship = getPlayer(menu->getChildByID("player-ship"));
        auto ball = getPlayer(menu->getChildByID("player-ball"));
        auto ufo = getPlayer(menu->getChildByID("player-ufo"));
        auto wave = getPlayer(menu->getChildByID("player-wave"));
        auto robot = getPlayer(menu->getChildByID("player-robot"));
        auto spider = getPlayer(menu->getChildByID("player-spider"));
        auto swing = getPlayer(menu->getChildByID("player-swing"));
        auto jetpack = menu->getChildByID("player-jetpack") ? getPlayer(menu->getChildByID("player-jetpack")) : nullptr;

        if (static_cast<CCMenuItemToggler*>(sender)->isOn()) {
            SDI_SET_VALUE(bool, "2pselected", false);
            int glowidx = GM->getPlayerGlowColor();
            if (glowidx == -1) glowidx = GM->getPlayerColor2();

            cube->updatePlayerFrame(GM->getPlayerFrame(), IconType::Cube);
            cube->setColor(GM->colorForIdx(GM->getPlayerColor()));
            cube->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            cube->enableCustomGlowColor(GM->colorForIdx(glowidx));
            cube->m_hasGlowOutline = GM->getPlayerGlow();
            cube->updateColors();

            //BUI added
            if (jetpack) {
                ship->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
                jetpack->updatePlayerFrame(GM->getPlayerJetpack(), IconType::Jetpack);

                jetpack->setColor(GM->colorForIdx(GM->getPlayerColor()));
                jetpack->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                jetpack->enableCustomGlowColor(GM->colorForIdx(glowidx));
                jetpack->m_hasGlowOutline = GM->getPlayerGlow();
                jetpack->updateColors();
            } else {
                if (shipType == IconType::Ship) ship->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
                else ship->updatePlayerFrame(GM->getPlayerJetpack(), IconType::Jetpack);
            }
            ship->setColor(GM->colorForIdx(GM->getPlayerColor()));
            ship->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            ship->enableCustomGlowColor(GM->colorForIdx(glowidx));
            ship->m_hasGlowOutline = GM->getPlayerGlow();
            ship->updateColors();

            ball->updatePlayerFrame(GM->getPlayerBall(), IconType::Ball);
            ball->setColor(GM->colorForIdx(GM->getPlayerColor()));
            ball->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            ball->enableCustomGlowColor(GM->colorForIdx(glowidx));
            ball->m_hasGlowOutline = GM->getPlayerGlow();
            ball->updateColors();

            ufo->updatePlayerFrame(GM->getPlayerBird(), IconType::Ufo);
            ufo->setColor(GM->colorForIdx(GM->getPlayerColor()));
            ufo->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            ufo->enableCustomGlowColor(GM->colorForIdx(glowidx));
            ufo->m_hasGlowOutline = GM->getPlayerGlow();
            ufo->updateColors();

            wave->updatePlayerFrame(GM->getPlayerDart(), IconType::Wave);
            wave->setColor(GM->colorForIdx(GM->getPlayerColor()));
            wave->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            wave->enableCustomGlowColor(GM->colorForIdx(glowidx));
            wave->m_hasGlowOutline = GM->getPlayerGlow();
            wave->updateColors();

            robot->updatePlayerFrame(GM->getPlayerRobot(), IconType::Robot);
            robot->setColor(GM->colorForIdx(GM->getPlayerColor()));
            robot->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            robot->enableCustomGlowColor(GM->colorForIdx(glowidx));
            robot->m_hasGlowOutline = GM->getPlayerGlow();
            robot->updateColors();

            spider->updatePlayerFrame(GM->getPlayerSpider(), IconType::Spider);
            spider->setColor(GM->colorForIdx(GM->getPlayerColor()));
            spider->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            spider->enableCustomGlowColor(GM->colorForIdx(glowidx));
            spider->m_hasGlowOutline = GM->getPlayerGlow();
            spider->updateColors();

            swing->updatePlayerFrame(GM->getPlayerSwing(), IconType::Swing);
            swing->setColor(GM->colorForIdx(GM->getPlayerColor()));
            swing->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
            swing->enableCustomGlowColor(GM->colorForIdx(glowidx));
            swing->m_hasGlowOutline = GM->getPlayerGlow();
            swing->updateColors();
        } else {
            SDI_SET_VALUE(bool, "2pselected", true);
            int glowidx = SDI_GET_VALUE(int64_t, "colorglow", 0);
            if (glowidx == -1) glowidx = SDI_GET_VALUE(int64_t, "color2", 0);

            cube->updatePlayerFrame(SDI_GET_VALUE(int64_t, "cube", 1), IconType::Cube);
            cube->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
            cube->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
            cube->enableCustomGlowColor(GM->colorForIdx(glowidx));
            cube->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
            cube->updateColors();

            //BUI added
            if (jetpack) {
                ship->updatePlayerFrame(SDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                jetpack->updatePlayerFrame(SDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);

                jetpack->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
                jetpack->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
                jetpack->enableCustomGlowColor(GM->colorForIdx(glowidx));
                jetpack->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
                jetpack->updateColors();
            } else {
                if (shipType == IconType::Ship) ship->updatePlayerFrame(SDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                else ship->updatePlayerFrame(SDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
            }
            ship->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
            ship->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
            ship->enableCustomGlowColor(GM->colorForIdx(glowidx));
            ship->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
            ship->updateColors();
            //

            ball->updatePlayerFrame(SDI_GET_VALUE(int64_t, "roll", 1), IconType::Ball);
            ball->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
            ball->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
            ball->enableCustomGlowColor(GM->colorForIdx(glowidx));
            ball->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
            ball->updateColors();

            ufo->updatePlayerFrame(SDI_GET_VALUE(int64_t, "bird", 1), IconType::Ufo);
            ufo->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
            ufo->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
            ufo->enableCustomGlowColor(GM->colorForIdx(glowidx));
            ufo->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
            ufo->updateColors();

            wave->updatePlayerFrame(SDI_GET_VALUE(int64_t, "dart", 1), IconType::Wave);
            wave->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
            wave->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
            wave->enableCustomGlowColor(GM->colorForIdx(glowidx));
            wave->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
            wave->updateColors();

            robot->updatePlayerFrame(SDI_GET_VALUE(int64_t, "robot", 1), IconType::Robot);
            robot->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
            robot->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
            robot->enableCustomGlowColor(GM->colorForIdx(glowidx));
            robot->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
            robot->updateColors();

            spider->updatePlayerFrame(SDI_GET_VALUE(int64_t, "spider", 1), IconType::Spider);
            spider->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
            spider->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
            spider->enableCustomGlowColor(GM->colorForIdx(glowidx));
            spider->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
            spider->updateColors();

            swing->updatePlayerFrame(SDI_GET_VALUE(int64_t, "swing", 1), IconType::Swing);
            swing->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
            swing->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
            swing->enableCustomGlowColor(GM->colorForIdx(glowidx));
            swing->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
            swing->updateColors();
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

        SDI_SET_VALUE(bool, "2pselected", false);
        auto GM = GameManager::get();

        if (this->m_ownProfile) {
            if (auto menu = m_mainLayer->getChildByID("player-menu")) {
                int glowidx = GM->getPlayerGlowColor();
                if (glowidx == -1) glowidx = GM->getPlayerColor2();

                if (auto player = getPlayer(menu->getChildByID("player-icon"))) {
                    player->updatePlayerFrame(GM->getPlayerFrame(), IconType::Cube);
                    player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                    player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                    player->enableCustomGlowColor(GM->colorForIdx(glowidx));
                    player->m_hasGlowOutline = GM->getPlayerGlow();
                    player->updateColors();
                }

                if (auto player = getPlayer(menu->getChildByID("player-ship"))) {
                    player->updatePlayerFrame(GM->getPlayerShip(), IconType::Ship);
                    player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                    player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                    player->enableCustomGlowColor(GM->colorForIdx(glowidx));
                    player->m_hasGlowOutline = GM->getPlayerGlow();
                    player->updateColors();
                }

                if (auto player = getPlayer(menu->getChildByID("player-ball"))) {
                    player->updatePlayerFrame(GM->getPlayerBall(), IconType::Ball);
                    player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                    player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                    player->enableCustomGlowColor(GM->colorForIdx(glowidx));
                    player->m_hasGlowOutline = GM->getPlayerGlow();
                    player->updateColors();
                }

                if (auto player = getPlayer(menu->getChildByID("player-ufo"))) {
                    player->updatePlayerFrame(GM->getPlayerBird(), IconType::Ufo);
                    player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                    player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                    player->enableCustomGlowColor(GM->colorForIdx(glowidx));
                    player->m_hasGlowOutline = GM->getPlayerGlow();
                    player->updateColors();
                }

                if (auto player = getPlayer(menu->getChildByID("player-wave"))) {
                    player->updatePlayerFrame(GM->getPlayerDart(), IconType::Wave);
                    player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                    player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                    player->enableCustomGlowColor(GM->colorForIdx(glowidx));
                    player->m_hasGlowOutline = GM->getPlayerGlow();
                    player->updateColors();
                }

                if (auto player = getPlayer(menu->getChildByID("player-robot"))) {
                    player->updatePlayerFrame(GM->getPlayerRobot(), IconType::Robot);
                    player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                    player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                    player->enableCustomGlowColor(GM->colorForIdx(glowidx));
                    player->m_hasGlowOutline = GM->getPlayerGlow();
                    player->updateColors();
                }

                if (auto player = getPlayer(menu->getChildByID("player-spider"))) {
                    player->updatePlayerFrame(GM->getPlayerSpider(), IconType::Spider);
                    player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                    player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                    player->enableCustomGlowColor(GM->colorForIdx(glowidx));
                    player->m_hasGlowOutline = GM->getPlayerGlow();
                    player->updateColors();
                }

                if (auto player = getPlayer(menu->getChildByID("player-swing"))) {
                    player->updatePlayerFrame(GM->getPlayerSwing(), IconType::Swing);
                    player->setColor(GM->colorForIdx(GM->getPlayerColor()));
                    player->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                    player->enableCustomGlowColor(GM->colorForIdx(glowidx));
                    player->m_hasGlowOutline = GM->getPlayerGlow();
                    player->updateColors();
                }
                // BUI added
                auto jetpack = menu->getChildByID("player-jetpack") ? getPlayer(menu->getChildByID("player-jetpack")) : nullptr;
                if (jetpack) {
                    jetpack->updatePlayerFrame(GM->getPlayerJetpack(), IconType::Jetpack);
                    jetpack->setColor(GM->colorForIdx(GM->getPlayerColor()));
                    jetpack->setSecondColor(GM->colorForIdx(GM->getPlayerColor2()));
                    jetpack->enableCustomGlowColor(GM->colorForIdx(glowidx));
                    jetpack->m_hasGlowOutline = GM->getPlayerGlow();
                    jetpack->updateColors();
                }
            }
        }

        if (this->m_ownProfile && !m_fields->hasLoaded) {
            m_fields->hasLoaded = true;

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
