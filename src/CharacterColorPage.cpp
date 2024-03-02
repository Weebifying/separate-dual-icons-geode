#include "PlayerData.hpp"
#include <Geode/modify/CharacterColorPage.hpp>


class $modify(CharacterColorPage) {
    IconType shipType = IconType::Ship;
    int colorMode = 0;

    bool init() {
        if (!CharacterColorPage::init()) return false;

        auto GM = GameManager::get();

        if (PlayerData::player2Selected) {
            auto layer = this->getChildByID("colors-layer");
            auto menu = layer->getChildByID("buttons-menu");
            auto winSize = CCDirector::get()->getWinSize();

            auto cube = as<SimplePlayer*>(layer->getChildByID("cube-icon"));
            cube->updatePlayerFrame(PlayerData::player2Cube, IconType::Cube);
            cube->setColor(GM->colorForIdx(PlayerData::player2Color1));
            cube->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                cube->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                cube->disableGlowOutline();
            }

            auto ship = getChildOfType<SimplePlayer>(layer->getChildByID("buttons-menu")->getChildByID("ship-button"), 0);
            ship->updatePlayerFrame(PlayerData::player2Ship, IconType::Ship);
            ship->setColor(GM->colorForIdx(PlayerData::player2Color1));
            ship->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                ship->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                ship->disableGlowOutline();
            }

            auto ball = as<SimplePlayer*>(layer->getChildByID("ball-icon"));
            ball->updatePlayerFrame(PlayerData::player2Roll, IconType::Ball);
            ball->setColor(GM->colorForIdx(PlayerData::player2Color1));
            ball->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                ball->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                ball->disableGlowOutline();
            }

            auto ufo = as<SimplePlayer*>(layer->getChildByID("ufo-icon"));
            ufo->updatePlayerFrame(PlayerData::player2Bird, IconType::Ufo);
            ufo->setColor(GM->colorForIdx(PlayerData::player2Color1));
            ufo->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                ufo->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                ufo->disableGlowOutline();
            }

            auto wave = as<SimplePlayer*>(layer->getChildByID("wave-icon"));
            wave->updatePlayerFrame(PlayerData::player2Dart, IconType::Wave);
            wave->setColor(GM->colorForIdx(PlayerData::player2Color1));
            wave->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                wave->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                wave->disableGlowOutline();
            }

            auto robot = as<SimplePlayer*>(layer->getChildByID("robot-icon"));
            robot->updatePlayerFrame(PlayerData::player2Robot, IconType::Robot);
            robot->setColor(GM->colorForIdx(PlayerData::player2Color1));
            robot->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                robot->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                robot->disableGlowOutline();
            }

            auto spider = as<SimplePlayer*>(layer->getChildByID("spider-icon"));
            spider->updatePlayerFrame(PlayerData::player2Spider, IconType::Spider);
            spider->setColor(GM->colorForIdx(PlayerData::player2Color1));
            spider->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                spider->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                spider->disableGlowOutline();
            }

            auto swing = as<SimplePlayer*>(layer->getChildByID("swing-icon"));
            swing->updatePlayerFrame(PlayerData::player2Swing, IconType::Swing);
            swing->setColor(GM->colorForIdx(PlayerData::player2Color1));
            swing->setSecondColor(GM->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                swing->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                swing->disableGlowOutline();
            }

            auto cursor1 = layer->getChildByID("cursor-col1");
            auto cursor2 = layer->getChildByID("cursor-col2");
            auto cursorglow = layer->getChildByID("cursor-glow");

            cursor1->setPosition({
                menu->getChildByID(std::to_string(PlayerData::player2Color1))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(PlayerData::player2Color1))->getPositionY() + menu->getPositionY()
            });

            cursor2->setPosition({
                menu->getChildByID(std::to_string(PlayerData::player2Color2))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(PlayerData::player2Color2))->getPositionY() + menu->getPositionY()
            });

            cursorglow->setPosition({
                menu->getChildByID(std::to_string(PlayerData::player2ColorGlow))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(PlayerData::player2ColorGlow))->getPositionY() + menu->getPositionY()
            });

            // ??? i have no idea why i need to do !player2Glow
            as<CCMenuItemToggler*>(menu->getChildByID("glow-toggler"))->toggle(!PlayerData::player2Glow);
        }

        return true;
    }

    void toggleShip(CCObject* sender) {
        CharacterColorPage::toggleShip(sender);
        
        if (PlayerData::player2Selected) {
            auto ship = getChildOfType<SimplePlayer>(as<CCMenuItemSpriteExtra*>(sender), 0);

            switch (m_fields->shipType) {
                case IconType::Ship:
                    m_fields->shipType = IconType::Jetpack;
                    ship->updatePlayerFrame(PlayerData::player2Jetpack, m_fields->shipType);
                    ship->setScale(1.05f);
                    break;
                case IconType::Jetpack:
                    m_fields->shipType = IconType::Ship;
                    ship->updatePlayerFrame(PlayerData::player2Ship, m_fields->shipType);
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
        if (PlayerData::player2Selected) {
            auto layer = this->getChildByID("colors-layer");
            auto menu = layer->getChildByID("buttons-menu");

            auto cursor1 = layer->getChildByID("cursor-col1");
            auto cursor2 = layer->getChildByID("cursor-col2");
            auto cursorglow = layer->getChildByID("cursor-glow");

            cursor1->setPosition({
                menu->getChildByID(std::to_string(PlayerData::player2Color1))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(PlayerData::player2Color1))->getPositionY() + menu->getPositionY()
            });

            cursor2->setPosition({
                menu->getChildByID(std::to_string(PlayerData::player2Color2))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(PlayerData::player2Color2))->getPositionY() + menu->getPositionY()
            });

            cursorglow->setPosition({
                menu->getChildByID(std::to_string(PlayerData::player2ColorGlow))->getPositionX() + menu->getPositionX(),
                menu->getChildByID(std::to_string(PlayerData::player2ColorGlow))->getPositionY() + menu->getPositionY()
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

        if (PlayerData::player2Selected && GM->isColorUnlocked(sender->getTag(), ut)) {
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
                    cursor = layer->getChildByID("cursor-col1");
                    cursor->setPosition({
                        menu->getChildByID(std::to_string(sender->getTag()))->getPositionX() + menu->getPositionX(),
                        menu->getChildByID(std::to_string(sender->getTag()))->getPositionY() + menu->getPositionY()
                    });

                    for (auto* icon : icons) {
                        icon->setColor(GM->colorForIdx(sender->getTag()));
                    }
                    player2->setColor(GM->colorForIdx(sender->getTag()));

                    Mod::get()->setSavedValue<int64_t>("color1", sender->getTag());
                    PlayerData::player2Color1 = sender->getTag();
                    break;
                case 1:
                    cursor = layer->getChildByID("cursor-col2");
                    cursor->setPosition({
                        menu->getChildByID(std::to_string(sender->getTag()))->getPositionX() + menu->getPositionX(),
                        menu->getChildByID(std::to_string(sender->getTag()))->getPositionY() + menu->getPositionY()
                    });

                    for (auto* icon : icons) {
                        icon->setSecondColor(GM->colorForIdx(sender->getTag()));
                    }
                    player2->setSecondColor(GM->colorForIdx(sender->getTag()));

                    Mod::get()->setSavedValue<int64_t>("color2", sender->getTag());
                    PlayerData::player2Color2 = sender->getTag();
                    break;
                case 2:
                    cursor = layer->getChildByID("cursor-glow");
                    cursor->setPosition({
                        menu->getChildByID(std::to_string(sender->getTag()))->getPositionX() + menu->getPositionX(),
                        menu->getChildByID(std::to_string(sender->getTag()))->getPositionY() + menu->getPositionY()
                    });

                    if (PlayerData::player2Glow) {
                        for (auto* icon : icons) {
                            icon->setGlowOutline(GM->colorForIdx(sender->getTag()));
                        }
                        player2->setGlowOutline(GM->colorForIdx(sender->getTag()));
                    }

                    Mod::get()->setSavedValue<int64_t>("colorglow", sender->getTag());
                    PlayerData::player2ColorGlow = sender->getTag();
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
        if (PlayerData::player2Selected) {
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
            PlayerData::player2Glow = as<CCMenuItemToggler*>(sender)->isOn();

            for (auto* icon : icons) {
                if (PlayerData::player2Glow) {
                    icon->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
                } else {
                    icon->disableGlowOutline();
                }
            }
            if (PlayerData::player2Glow) 
                player2->setGlowOutline(GM->colorForIdx(PlayerData::player2ColorGlow));
            else
                player2->disableGlowOutline();


        } else {
            CharacterColorPage::toggleGlow(sender);
        }
    }
};