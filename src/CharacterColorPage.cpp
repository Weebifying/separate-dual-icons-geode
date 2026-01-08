#include "Macros.hpp"
#include <Geode/modify/CharacterColorPage.hpp>

using namespace geode::prelude;

class $modify(MyCharacterColorPage, CharacterColorPage) {
    static void onModify(auto& self) {
        (void)self.setHookPriority("CharacterColorPage::onPlayerColor", Priority::Replace);
        (void)self.setHookPriority("CharacterColorPage::toggleGlow", Priority::Replace);
    }

    bool init() {
        if (!CharacterColorPage::init()) return false;

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            auto cube = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(0));
            cube->updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1), IconType::Cube);

            auto ship = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(1));
            ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);

            auto ball = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(2));
            ball->updatePlayerFrame(GDI_GET_VALUE(int64_t, "roll", 1), IconType::Ball);

            auto ufo = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(3));
            ufo->updatePlayerFrame(GDI_GET_VALUE(int64_t, "bird", 1), IconType::Ufo);

            auto wave = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(4));
            wave->updatePlayerFrame(GDI_GET_VALUE(int64_t, "dart", 1), IconType::Wave);

            auto robot = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(5));
            robot->updatePlayerFrame(GDI_GET_VALUE(int64_t, "robot", 1), IconType::Robot);

            auto spider = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(6));
            spider->updatePlayerFrame(GDI_GET_VALUE(int64_t, "spider", 1), IconType::Spider);

            auto swing = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(7));
            swing->updatePlayerFrame(GDI_GET_VALUE(int64_t, "swing", 1), IconType::Swing);

            // ??? i have no idea why i need to do !player2Glow
            m_glowToggler->toggle(!GDI_GET_VALUE(bool, "glow", false));
        }

        return true;
    }

    void toggleShip(CCObject* sender) {
        CharacterColorPage::toggleShip(sender);

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            auto ship = static_cast<SimplePlayer*>(static_cast<CCMenuItemSprite*>(sender)->getNormalImage());

            switch (sender->getTag()) {
                case 1:
                    ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                    break;
                case 8:
                    ship->updatePlayerFrame(GDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
                    break;
                default:
                    log::error("what???");
                    break;
            }
        }
    }


    void updateColorMode(int p0) {
        CharacterColorPage::updateColorMode(p0);

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            auto color1 = GDI_GET_VALUE(int64_t, "color1", 0);
            auto color2 = GDI_GET_VALUE(int64_t, "color2", 0);
            auto colorglow = GDI_GET_VALUE(int64_t, "colorglow", 0);

            for (auto [i, sprite] : CCDictionaryExt<intptr_t, ColorChannelSprite*>(m_colorButtons)) {
                if (i == color1) {
                    static_cast<CCNode*>(m_cursors->objectAtIndex(0))->setPosition(m_mainLayer->convertToNodeSpace(
                        m_buttonMenu->convertToWorldSpace(sprite->getParent()->getPosition())
                    ));
                }
                if (i == color2) {
                    static_cast<CCNode*>(m_cursors->objectAtIndex(1))->setPosition(m_mainLayer->convertToNodeSpace(
                        m_buttonMenu->convertToWorldSpace(sprite->getParent()->getPosition())
                    ));
                }
                if (i == colorglow) {
                    static_cast<CCNode*>(m_cursors->objectAtIndex(2))->setPosition(m_mainLayer->convertToNodeSpace(
                        m_buttonMenu->convertToWorldSpace(sprite->getParent()->getPosition())
                    ));
                }
            }
        }
    }

    void onPlayerColor(CCObject* sender) {
        UnlockType ut;
        auto GM = GameManager::get();

        switch (m_colorMode) {
            case 0:
                ut = UnlockType::Col1;
                break;
            default:
                ut = UnlockType::Col2;
                break;
        }

        if (GDI_GET_VALUE(bool, "2pselected", false) && GM->isColorUnlocked(sender->getTag(), ut)) {
            auto colorKey = "";
            switch (m_colorMode) {
                case 0:
                    colorKey = "color1";
                    break;
                case 1:
                    colorKey = "color2";
                    break;
                case 2:
                    colorKey = "colorglow";
                    break;
            }

            if (GDI_GET_VALUE(int64_t, colorKey, 0) != sender->getTag()) {
                static_cast<CCNode*>(m_cursors->objectAtIndex(m_colorMode))->setPosition(m_mainLayer->convertToNodeSpace(
                    m_buttonMenu->convertToWorldSpace(static_cast<CCNode*>(sender)->getPosition())
                ));
                GDI_SET_VALUE(int64_t, colorKey, sender->getTag());
            } else {
                m_delegate->showUnlockPopup(sender->getTag(), ut);
            }

            updateIconColors();
        } else {
            CharacterColorPage::onPlayerColor(sender);
        }
    }

    void toggleGlow(CCObject* sender) {
        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            GDI_SET_VALUE(bool, "glow", static_cast<CCMenuItemToggler*>(sender)->isOn());
            updateIconColors();
        } else {
            CharacterColorPage::toggleGlow(sender);
        }
    }

    void updateIconColors() {
        CharacterColorPage::updateIconColors();

        if (GDI_GET_VALUE(bool, "2pselected", false)) {
            auto GM = GameManager::get();
            for (auto* icon : CCArrayExt<SimplePlayer*>(m_playerObjects)) {
                icon->setColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
                icon->setSecondColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
                icon->enableCustomGlowColor(GM->colorForIdx(GDI_GET_VALUE(int64_t, "colorglow", 0)));
                icon->m_hasGlowOutline = GDI_GET_VALUE(bool, "glow", false);
                icon->updateColors();
            }
        }
    }
};