#include "Macros.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/CharacterColorPage.hpp>
using namespace geode::prelude;

class $modify(MyCharacterColorPage, CharacterColorPage) {
    struct Fields {
        CCLabelBMFont* m_pLabel;
    };

    static void onModify(auto& self) {
        (void)self.setHookPriority("CharacterColorPage::onPlayerColor", Priority::Replace);
        (void)self.setHookPriority("CharacterColorPage::toggleGlow", Priority::Replace);
    }

    bool init() {
        if (!CharacterColorPage::init()) return false;

        if (SDI_GET_VALUE(bool, "2pselected", false)) {
            auto cube = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(0));
            cube->updatePlayerFrame(SDI_GET_VALUE(int64_t, "cube", 1), IconType::Cube);

            auto ship = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(1));
            ship->updatePlayerFrame(SDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);

            auto ball = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(2));
            ball->updatePlayerFrame(SDI_GET_VALUE(int64_t, "roll", 1), IconType::Ball);

            auto ufo = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(3));
            ufo->updatePlayerFrame(SDI_GET_VALUE(int64_t, "bird", 1), IconType::Ufo);

            auto wave = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(4));
            wave->updatePlayerFrame(SDI_GET_VALUE(int64_t, "dart", 1), IconType::Wave);

            auto robot = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(5));
            robot->updatePlayerFrame(SDI_GET_VALUE(int64_t, "robot", 1), IconType::Robot);

            auto spider = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(6));
            spider->updatePlayerFrame(SDI_GET_VALUE(int64_t, "spider", 1), IconType::Spider);

            auto swing = static_cast<SimplePlayer*>(m_playerObjects->objectAtIndex(7));
            swing->updatePlayerFrame(SDI_GET_VALUE(int64_t, "swing", 1), IconType::Swing);

            // ??? i have no idea why i need to do !player2Glow
            // honestly i might jus be stupid
            m_glowToggler->toggle(!SDI_GET_VALUE(bool, "glow", false));

            m_fields->m_pLabel = CCLabelBMFont::create("P2", "bigFont.fnt");
            m_fields->m_pLabel->retain();
            m_fields->m_pLabel->setScale(0.3f);
            m_fields->m_pLabel->setAnchorPoint({1.f, 1.f});
            m_fields->m_pLabel->setColor({0, 255, 255});
            m_fields->m_pLabel->setID("player-label");
            static_cast<CCNode*>(m_cursors->objectAtIndex(0))->addChild(m_fields->m_pLabel);
            m_fields->m_pLabel->setPosition({
                static_cast<CCNode*>(m_cursors->objectAtIndex(0))->getContentWidth() - 2.5f,
                static_cast<CCNode*>(m_cursors->objectAtIndex(0))->getContentHeight() - 1.f
            });
            
        } else {
            m_fields->m_pLabel = CCLabelBMFont::create("P1", "bigFont.fnt");
            m_fields->m_pLabel->retain();
            m_fields->m_pLabel->setScale(0.3f);
            m_fields->m_pLabel->setAnchorPoint({0.f, 1.f});
            m_fields->m_pLabel->setColor({255, 255, 0});
            m_fields->m_pLabel->setID("player-label");
            static_cast<CCNode*>(m_cursors->objectAtIndex(0))->addChild(m_fields->m_pLabel);
            m_fields->m_pLabel->setPosition({
                2.5f,
                static_cast<CCNode*>(m_cursors->objectAtIndex(0))->getContentHeight() - 1.f
            });
        }

        return true;
    }

    void toggleShip(CCObject* sender) {
        CharacterColorPage::toggleShip(sender);

        if (SDI_GET_VALUE(bool, "2pselected", false)) {
            auto ship = static_cast<SimplePlayer*>(static_cast<CCMenuItemSprite*>(sender)->getNormalImage());

            switch (sender->getTag()) {
                case 1:
                    ship->updatePlayerFrame(SDI_GET_VALUE(int64_t, "ship", 1), IconType::Ship);
                    break;
                case 8:
                    ship->updatePlayerFrame(SDI_GET_VALUE(int64_t, "jetpack", 1), IconType::Jetpack);
                    break;
                default:
                    log::error("what???");
                    break;
            }
        }
    }


    void updateColorMode(int p0) {
        CharacterColorPage::updateColorMode(p0);

        if (m_fields->m_pLabel) {
            m_fields->m_pLabel->removeFromParentAndCleanup(false);
            static_cast<CCNode*>(m_cursors->objectAtIndex(p0))->addChild(m_fields->m_pLabel);
        }

        if (SDI_GET_VALUE(bool, "2pselected", false)) {
            auto color1 = SDI_GET_VALUE(int64_t, "color1", 0);
            auto color2 = SDI_GET_VALUE(int64_t, "color2", 0);
            auto colorglow = SDI_GET_VALUE(int64_t, "colorglow", 0);

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

        if (SDI_GET_VALUE(bool, "2pselected", false) && GM->isColorUnlocked(sender->getTag(), ut)) {
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

            if (SDI_GET_VALUE(int64_t, colorKey, 0) != sender->getTag()) {
                static_cast<CCNode*>(m_cursors->objectAtIndex(m_colorMode))->setPosition(m_mainLayer->convertToNodeSpace(
                    m_buttonMenu->convertToWorldSpace(static_cast<CCNode*>(sender)->getPosition())
                ));
                SDI_SET_VALUE(int64_t, colorKey, sender->getTag());
            } else {
                m_delegate->showUnlockPopup(sender->getTag(), ut);
            }

            updateIconColors();
        } else {
            CharacterColorPage::onPlayerColor(sender);
        }
    }

    void toggleGlow(CCObject* sender) {
        if (SDI_GET_VALUE(bool, "2pselected", false)) {
            SDI_SET_VALUE(bool, "glow", static_cast<CCMenuItemToggler*>(sender)->isOn());
            updateIconColors();
        } else {
            CharacterColorPage::toggleGlow(sender);
        }
    }

    void updateIconColors() {
        CharacterColorPage::updateIconColors();

        if (SDI_GET_VALUE(bool, "2pselected", false)) {
            auto GM = GameManager::get();
            for (auto* icon : CCArrayExt<SimplePlayer*>(m_playerObjects)) {
                icon->setColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color1", 0)));
                icon->setSecondColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "color2", 0)));
                icon->enableCustomGlowColor(GM->colorForIdx(SDI_GET_VALUE(int64_t, "colorglow", 0)));
                icon->m_hasGlowOutline = SDI_GET_VALUE(bool, "glow", false);
                icon->updateColors();
            }
        }
    }

    
    void onExit() {
        CharacterColorPage::onExit();

        if (m_fields->m_pLabel) {
            m_fields->m_pLabel->removeFromParentAndCleanup(true);
            CC_SAFE_DELETE(m_fields->m_pLabel);
        }
    }
};