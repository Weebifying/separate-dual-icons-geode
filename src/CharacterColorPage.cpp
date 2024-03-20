#include "PlayerData.hpp"
#include <Geode/modify/CharacterColorPage.hpp>


class $modify(CharacterColorPage) {
    IconType shipType = IconType::Ship;
    int colorMode = 0;

    bool init() {
        if (!CharacterColorPage::init()) return false;

        auto GM = GameManager::get();

        if (Mod::get()->getSavedValue<bool>("2pselected", false)) {
            auto layer = this->getChildByID("colors-layer");
            auto menu = layer->getChildByID("buttons-menu");
            auto winSize = CCDirector::get()->getWinSize();

            auto cube = as<SimplePlayer*>(layer->getChildByID("cube-icon"));
            cube->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("cube", 1), IconType::Cube);
            cube->setColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
            cube->setSecondColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
            if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                cube->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
            } else {
                cube->disableGlowOutline();
            }

            auto ship = getChildOfType<SimplePlayer>(layer->getChildByID("buttons-menu")->getChildByID("ship-button"), 0);
            ship->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("ship", 1), IconType::Ship);
            ship->setColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
            ship->setSecondColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
            if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                ship->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
            } else {
                ship->disableGlowOutline();
            }

            auto ball = as<SimplePlayer*>(layer->getChildByID("ball-icon"));
            ball->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("roll", 1), IconType::Ball);
            ball->setColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
            ball->setSecondColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
            if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                ball->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
            } else {
                ball->disableGlowOutline();
            }

            auto ufo = as<SimplePlayer*>(layer->getChildByID("ufo-icon"));
            ufo->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("bird", 1), IconType::Ufo);
            ufo->setColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
            ufo->setSecondColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
            if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                ufo->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
            } else {
                ufo->disableGlowOutline();
            }

            auto wave = as<SimplePlayer*>(layer->getChildByID("wave-icon"));
            wave->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("dart", 1), IconType::Wave);
            wave->setColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
            wave->setSecondColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
            if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                wave->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
            } else {
                wave->disableGlowOutline();
            }

            auto robot = as<SimplePlayer*>(layer->getChildByID("robot-icon"));
            robot->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("robot", 1), IconType::Robot);
            robot->setColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
            robot->setSecondColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
            if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                robot->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
            } else {
                robot->disableGlowOutline();
            }

            auto spider = as<SimplePlayer*>(layer->getChildByID("spider-icon"));
            spider->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("spider", 1), IconType::Spider);
            spider->setColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
            spider->setSecondColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
            if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                spider->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
            } else {
                spider->disableGlowOutline();
            }

            auto swing = as<SimplePlayer*>(layer->getChildByID("swing-icon"));
            swing->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("swing", 1), IconType::Swing);
            swing->setColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
            swing->setSecondColor(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
            if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                swing->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
            } else {
                swing->disableGlowOutline();
            }

            auto cursor1 = layer->getChildByID("cursor-col1");
            auto cursor2 = layer->getChildByID("cursor-col2");
            auto cursorglow = layer->getChildByID("cursor-glow");

            cursor1->setPosition({
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("color1", 0)))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("color1", 0)))->getPositionY() + menu->getPositionY()
            });

            cursor2->setPosition({
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("color2", 0)))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("color2", 0)))->getPositionY() + menu->getPositionY()
            });

            cursorglow->setPosition({
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("colorglow", 0)))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("colorglow", 0)))->getPositionY() + menu->getPositionY()
            });

            // ??? i have no idea why i need to do !player2Glow
            as<CCMenuItemToggler*>(menu->getChildByID("glow-toggler"))->toggle(!Mod::get()->getSavedValue<bool>("glow", false));
        }

        return true;
    }

    void toggleShip(CCObject* sender) {
        CharacterColorPage::toggleShip(sender);
        
        if (Mod::get()->getSavedValue<bool>("2pselected", false)) {
            auto ship = getChildOfType<SimplePlayer>(as<CCMenuItemSpriteExtra*>(sender), 0);

            switch (m_fields->shipType) {
                case IconType::Ship:
                    m_fields->shipType = IconType::Jetpack;
                    ship->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("jetpack", 1), m_fields->shipType);
                    ship->setScale(1.05f);
                    break;
                case IconType::Jetpack:
                    m_fields->shipType = IconType::Ship;
                    ship->updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("ship", 1), m_fields->shipType);
                    ship->setScale(1.15f);
                    break;
                default:
                    log::error("what???");
                    break;
            }
        }
    }

    
    void onMode(CCObject* sender) {
        CharacterColorPage::onMode(sender);
        if (Mod::get()->getSavedValue<bool>("2pselected", false)) {
            auto layer = this->getChildByID("colors-layer");
            auto menu = layer->getChildByID("buttons-menu");

            auto cursor1 = layer->getChildByID("cursor-col1");
            auto cursor2 = layer->getChildByID("cursor-col2");
            auto cursorglow = layer->getChildByID("cursor-glow");

            cursor1->setPosition({
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("color1", 0)))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("color1", 0)))->getPositionY() + menu->getPositionY()
            });

            cursor2->setPosition({
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("color2", 0)))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("color2", 0)))->getPositionY() + menu->getPositionY()
            });

            cursorglow->setPosition({
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("colorglow", 0)))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(Mod::get()->getSavedValue<int64_t>("colorglow", 0)))->getPositionY() + menu->getPositionY()
            });

            m_fields->colorMode = as<CCMenuItemSpriteExtra*>(sender)->getTag();
            log::warn("mode {}", m_fields->colorMode);
        }
    }

    void onPlayerColor(CCObject* sender) {
        UnlockType ut;
        auto GM = GameManager::get();

        switch (m_fields->colorMode) {
            case 0:
                ut = UnlockType::Col1;
                break;
            default:
                ut = UnlockType::Col2;
                break;
        }

        if (Mod::get()->getSavedValue<bool>("2pselected", false) && GM->isColorUnlocked(sender->getTag(), ut)) {
            auto prevCol1 = Mod::get()->getSavedValue<int64_t>("color1", 0);

            auto layer = this->getChildByID("colors-layer");
            auto menu = layer->getChildByID("buttons-menu");
            std::vector<SimplePlayer*> icons;

            icons.push_back(as<SimplePlayer*>(layer->getChildByID("cube-icon")));
            icons.push_back(getChildOfType<SimplePlayer>(layer->getChildByID("buttons-menu")->getChildByID("ship-button"), 0));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("ball-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("ufo-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("wave-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("robot-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("spider-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("swing-icon")));

            auto player2 = as<SimplePlayer*>(CCDirector::get()->getRunningScene()->getChildByID("GJGarageLayer")->getChildByID("player2-icon"));
            CCNode* cursor = nullptr;

            switch (m_fields->colorMode) {
                case 0:
                    if (Mod::get()->getSavedValue<int64_t>("color1", 0) != sender->getTag()) {
                        cursor = layer->getChildByID("cursor-col1");
                        cursor->setPosition({
                            menu->getChildByID(std::to_string(sender->getTag()))->getPositionX() + menu->getPositionX(),
                            menu->getChildByID(std::to_string(sender->getTag()))->getPositionY() + menu->getPositionY()
                        });

                        Mod::get()->setSavedValue<int64_t>("color1", sender->getTag());
                        for (auto* icon : icons) {
                            icon->setColor(GM->colorForIdx(sender->getTag()));
                        }
                        player2->setColor(GM->colorForIdx(sender->getTag()));

                        if (prevCol1 == 15) {
                            for (auto* icon : icons) {
                                icon->disableGlowOutline();
                            }
                            player2->disableGlowOutline();
                        } else if (sender->getTag() == 15) {
                            for (auto* icon : icons) {
                                icon->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
                            }
                            player2->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
                        }

                    } else {
                        ItemInfoPopup::create(sender->getTag(), UnlockType::Col1)->show();
                        return;
                    }
                    break;
                case 1:
                    if (Mod::get()->getSavedValue<int64_t>("color2", 0) != sender->getTag()) {
                        cursor = layer->getChildByID("cursor-col2");
                        cursor->setPosition({
                            menu->getChildByID(std::to_string(sender->getTag()))->getPositionX() + menu->getPositionX(),
                            menu->getChildByID(std::to_string(sender->getTag()))->getPositionY() + menu->getPositionY()
                        });

                        Mod::get()->setSavedValue<int64_t>("color2", sender->getTag());
                        for (auto* icon : icons) {
                            icon->setSecondColor(GM->colorForIdx(sender->getTag()));
                        }
                        player2->setSecondColor(GM->colorForIdx(sender->getTag()));

                    } else {
                        ItemInfoPopup::create(sender->getTag(), UnlockType::Col2)->show();
                        return;
                    }
                    break;
                case 2:
                    if (Mod::get()->getSavedValue<int64_t>("colorglow", 0) != sender->getTag()) {
                        cursor = layer->getChildByID("cursor-glow");
                        cursor->setPosition({
                            menu->getChildByID(std::to_string(sender->getTag()))->getPositionX() + menu->getPositionX(),
                            menu->getChildByID(std::to_string(sender->getTag()))->getPositionY() + menu->getPositionY()
                        });

                        Mod::get()->setSavedValue<int64_t>("colorglow", sender->getTag());
                        if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                            for (auto* icon : icons) {
                                icon->setGlowOutline(GM->colorForIdx(sender->getTag()));
                            }
                            player2->setGlowOutline(GM->colorForIdx(sender->getTag()));
                        }

                    } else {
                        ItemInfoPopup::create(sender->getTag(), UnlockType::Col2)->show();
                        return;
                    }
                    break;
                default:
                    log::error("what did you do lmao");
                    break;
            }

        } else {
            CharacterColorPage::onPlayerColor(sender);
        }
    }

    void toggleGlow(CCObject* sender) {
        if (Mod::get()->getSavedValue<bool>("2pselected", false)) {
            auto GM = GameManager::get();

            auto layer = this->getChildByID("colors-layer");
            auto menu = layer->getChildByID("buttons-menu");
            std::vector<SimplePlayer*> icons;

            icons.push_back(as<SimplePlayer*>(layer->getChildByID("cube-icon")));
            icons.push_back(getChildOfType<SimplePlayer>(layer->getChildByID("buttons-menu")->getChildByID("ship-button"), 0));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("ball-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("ufo-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("wave-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("robot-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("spider-icon")));
            icons.push_back(as<SimplePlayer*>(layer->getChildByID("swing-icon")));

            auto player2 = as<SimplePlayer*>(CCDirector::get()->getRunningScene()->getChildByID("GJGarageLayer")->getChildByID("player2-icon"));

            Mod::get()->setSavedValue<bool>("glow", as<CCMenuItemToggler*>(sender)->isOn());

            for (auto* icon : icons) {
                if (Mod::get()->getSavedValue<bool>("glow", false) || Mod::get()->getSavedValue<int64_t>("color1", 0) == 15) {
                    icon->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
                } else {
                    icon->disableGlowOutline();
                }
            }
            if (Mod::get()->getSavedValue<bool>("glow", false)) 
                player2->setGlowOutline(GM->colorForIdx(Mod::get()->getSavedValue<int64_t>("colorglow", 0)));
            else
                player2->disableGlowOutline();


        } else {
            CharacterColorPage::toggleGlow(sender);
        }
    }
};