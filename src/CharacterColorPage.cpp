#include "PlayerData.hpp"
#include <Geode/modify/CharacterColorPage.hpp>


class $modify(CharacterColorPage) {
    IconType shipType = IconType::Ship;
    int colorMode = 0;

    bool init() {
        if (!CharacterColorPage::init()) return false;

        if (PlayerData::player2Selected) {
            auto layer = this->getChildByID("colors-layer");
            auto menu = layer->getChildByID("buttons-menu");
            auto winSize = CCDirector::get()->getWinSize();

            
            as<SimplePlayer*>(layer->getChildByID("cube-icon"))->updatePlayerFrame(PlayerData::player2Cube, IconType::Cube);
            as<SimplePlayer*>(layer->getChildByID("cube-icon"))->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            as<SimplePlayer*>(layer->getChildByID("cube-icon"))->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                as<SimplePlayer*>(layer->getChildByID("cube-icon"))->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                as<SimplePlayer*>(layer->getChildByID("cube-icon"))->disableGlowOutline();
            }

            getChildOfType<SimplePlayer>(layer->getChildByID("buttons-menu")->getChildByID("ship-button"), 0)->updatePlayerFrame(PlayerData::player2Ship, IconType::Ship);
            getChildOfType<SimplePlayer>(layer->getChildByID("buttons-menu")->getChildByID("ship-button"), 0)->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            getChildOfType<SimplePlayer>(layer->getChildByID("buttons-menu")->getChildByID("ship-button"), 0)->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                getChildOfType<SimplePlayer>(layer->getChildByID("buttons-menu")->getChildByID("ship-button"), 0)->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                getChildOfType<SimplePlayer>(layer->getChildByID("buttons-menu")->getChildByID("ship-button"), 0)->disableGlowOutline();
            }

            as<SimplePlayer*>(layer->getChildByID("ball-icon"))->updatePlayerFrame(PlayerData::player2Roll, IconType::Ball);
            as<SimplePlayer*>(layer->getChildByID("ball-icon"))->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            as<SimplePlayer*>(layer->getChildByID("ball-icon"))->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                as<SimplePlayer*>(layer->getChildByID("ball-icon"))->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                as<SimplePlayer*>(layer->getChildByID("ball-icon"))->disableGlowOutline();
            }

            as<SimplePlayer*>(layer->getChildByID("ufo-icon"))->updatePlayerFrame(PlayerData::player2Bird, IconType::Ufo);
            as<SimplePlayer*>(layer->getChildByID("ufo-icon"))->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            as<SimplePlayer*>(layer->getChildByID("ufo-icon"))->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                as<SimplePlayer*>(layer->getChildByID("ufo-icon"))->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                as<SimplePlayer*>(layer->getChildByID("ufo-icon"))->disableGlowOutline();
            }

            as<SimplePlayer*>(layer->getChildByID("wave-icon"))->updatePlayerFrame(PlayerData::player2Dart, IconType::Wave);
            as<SimplePlayer*>(layer->getChildByID("wave-icon"))->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            as<SimplePlayer*>(layer->getChildByID("wave-icon"))->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                as<SimplePlayer*>(layer->getChildByID("wave-icon"))->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                as<SimplePlayer*>(layer->getChildByID("wave-icon"))->disableGlowOutline();
            }

            as<SimplePlayer*>(layer->getChildByID("robot-icon"))->updatePlayerFrame(PlayerData::player2Robot, IconType::Robot);
            as<SimplePlayer*>(layer->getChildByID("robot-icon"))->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            as<SimplePlayer*>(layer->getChildByID("robot-icon"))->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                as<SimplePlayer*>(layer->getChildByID("robot-icon"))->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                as<SimplePlayer*>(layer->getChildByID("robot-icon"))->disableGlowOutline();
            }

            as<SimplePlayer*>(layer->getChildByID("spider-icon"))->updatePlayerFrame(PlayerData::player2Spider, IconType::Spider);
            as<SimplePlayer*>(layer->getChildByID("spider-icon"))->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            as<SimplePlayer*>(layer->getChildByID("spider-icon"))->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                as<SimplePlayer*>(layer->getChildByID("spider-icon"))->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                as<SimplePlayer*>(layer->getChildByID("spider-icon"))->disableGlowOutline();
            }

            as<SimplePlayer*>(layer->getChildByID("swing-icon"))->updatePlayerFrame(PlayerData::player2Swing, IconType::Swing);
            as<SimplePlayer*>(layer->getChildByID("swing-icon"))->setColor(GameManager::get()->colorForIdx(PlayerData::player2Color1));
            as<SimplePlayer*>(layer->getChildByID("swing-icon"))->setSecondColor(GameManager::get()->colorForIdx(PlayerData::player2Color2));
            if (PlayerData::player2Glow) {
                as<SimplePlayer*>(layer->getChildByID("swing-icon"))->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            } else {
                as<SimplePlayer*>(layer->getChildByID("swing-icon"))->disableGlowOutline();
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
        switch (m_fields->colorMode) {
            case 0:
                ut = UnlockType::Col1;
                break;
            default:
                ut = UnlockType::Col2;
                break;
        }

        if (PlayerData::player2Selected && GameManager::get()->isColorUnlocked(sender->getTag(), ut)) {
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
                        icon->setColor(GameManager::get()->colorForIdx(sender->getTag()));
                    }
                    player2->setColor(GameManager::get()->colorForIdx(sender->getTag()));

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
                        icon->setSecondColor(GameManager::get()->colorForIdx(sender->getTag()));
                    }
                    player2->setSecondColor(GameManager::get()->colorForIdx(sender->getTag()));

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
                            icon->setGlowOutline(GameManager::get()->colorForIdx(sender->getTag()));
                        }
                        player2->setGlowOutline(GameManager::get()->colorForIdx(sender->getTag()));
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
                    icon->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
                } else {
                    icon->disableGlowOutline();
                }
            }
            if (PlayerData::player2Glow) 
                player2->setGlowOutline(GameManager::get()->colorForIdx(PlayerData::player2ColorGlow));
            else
                player2->disableGlowOutline();


        } else {
            CharacterColorPage::toggleGlow(sender);
        }
    }
};