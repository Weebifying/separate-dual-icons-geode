#include "PlayerData.hpp"
#include "Macros.hpp"
#include <Geode/modify/PlayerObject.hpp>


class $modify(PlayerObject) {
    struct Fields {
        bool m_is2PMini = false;
    };

    void setupStreak() {
        // thanks alphalaneous for the fucking genius code
        // theres no way i dont copy this
        int origStreak = GameManager::get()->m_playerStreak;
        int origShipStreak = GameManager::get()->m_playerShipFire;

        if (PlayLayer::get() || LevelEditorLayer::get()) {
            if (PlayerData::callPosStreak == 1) {
                GameManager::get()->m_playerStreak = GDI_GET_VALUE(int64_t, "trail", 1);
                GameManager::get()->m_playerShipFire = GDI_GET_VALUE(int64_t, "shiptrail", 1);
            }

            PlayerData::callPosStreak++;
            if (PlayerData::callPosStreak == 2) PlayerData::callPosStreak = 0;
        }

        PlayerObject::setupStreak();

        GameManager::get()->m_playerStreak = origStreak;
        GameManager::get()->m_playerShipFire = origShipStreak;
    }

    void playDeathEffect() {
        int origDeath = GameManager::get()->m_playerDeathEffect;
        bool orgDeathExplode = GameManager::get()->getGameVariable("0153");

        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2) {
                GameManager::get()->m_playerDeathEffect = GDI_GET_VALUE(int64_t, "death", 1);
                GameManager::get()->setGameVariable("0153", GDI_GET_VALUE(bool, "deathexplode", false));
            }
        }

        PlayerObject::playDeathEffect();

        GameManager::get()->m_playerDeathEffect = origDeath;
        GameManager::get()->setGameVariable("0153", orgDeathExplode);
    }

    void setColor(ccColor3B const &color) {
        PlayerObject::setColor(color);

        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::setColor(GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::setColor(GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "color1", 0)));
        }
    }

    void setSecondColor(ccColor3B const &color) {
        PlayerObject::setSecondColor(color);

        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::setSecondColor(GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::setSecondColor(GameManager::get()->colorForIdx(GDI_GET_VALUE(int64_t, "color2", 0)));
        }
    }

    void updatePlayerFrame(int p0) {
        PlayerObject::updatePlayerFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2) {
                if (m_fields->m_is2PMini && this->m_gamevar0060) PlayerObject::updatePlayerFrame(0);
                else PlayerObject::updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1));
            }
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2) {
                if (m_fields->m_is2PMini && this->m_gamevar0060) PlayerObject::updatePlayerFrame(0);
                else PlayerObject::updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1));
            }
        }
    }
    
	void updatePlayerShipFrame(int p0) {
        PlayerObject::updatePlayerShipFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerShipFrame(GDI_GET_VALUE(int64_t, "ship", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerShipFrame(GDI_GET_VALUE(int64_t, "ship", 1));
        }
        
    }

    void updatePlayerRollFrame(int p0) {
        PlayerObject::updatePlayerRollFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2) {
                if (m_fields->m_is2PMini && this->m_gamevar0060) PlayerObject::updatePlayerRollFrame(0);
                else PlayerObject::updatePlayerRollFrame(GDI_GET_VALUE(int64_t, "roll", 1));
            }
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2) {
                if (m_fields->m_is2PMini && this->m_gamevar0060) PlayerObject::updatePlayerRollFrame(0);
                else PlayerObject::updatePlayerRollFrame(GDI_GET_VALUE(int64_t, "roll", 1));
            }
        }
        
    }

    void updatePlayerBirdFrame(int p0) {
        PlayerObject::updatePlayerBirdFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerBirdFrame(GDI_GET_VALUE(int64_t, "bird", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerBirdFrame(GDI_GET_VALUE(int64_t, "bird", 1));
        }
        
    }

    void updatePlayerDartFrame(int p0) {
        PlayerObject::updatePlayerDartFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerDartFrame(GDI_GET_VALUE(int64_t, "dart", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerDartFrame(GDI_GET_VALUE(int64_t, "dart", 1));
        }
        
    }

    void updatePlayerSwingFrame(int p0) {
        PlayerObject::updatePlayerSwingFrame(p0);
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerSwingFrame(GDI_GET_VALUE(int64_t, "swing", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerSwingFrame(GDI_GET_VALUE(int64_t, "swing", 1));
        }

    }

    void updatePlayerJetpackFrame(int p0) {
        PlayerObject::updatePlayerJetpackFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerJetpackFrame(GDI_GET_VALUE(int64_t, "jetpack", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerJetpackFrame(GDI_GET_VALUE(int64_t, "jetpack", 1));
        }   

    }

    void togglePlayerScale(bool p0, bool p1) {
        PlayerObject::togglePlayerScale(p0, p1);

        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2) m_fields->m_is2PMini = p0;
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2) m_fields->m_is2PMini = p0;
        }
        
        
        if (p0) {
            if (PlayLayer::get()) {
                if (this == PlayLayer::get()->m_player2 && this->m_gamevar0060) {
                    if (this->m_isBall)
                        PlayerObject::updatePlayerRollFrame(0);
                    else if (this->m_isDart)
                        PlayerObject::updatePlayerDartFrame(GDI_GET_VALUE(int64_t, "dart", 1));
                    else if (this->m_isSwing)
                        PlayerObject::updatePlayerSwingFrame(GDI_GET_VALUE(int64_t, "swing", 1));
                    else
                        PlayerObject::updatePlayerFrame(0);
                }
            } else if (LevelEditorLayer::get()) {
                if (this == LevelEditorLayer::get()->m_player2 && this->m_gamevar0060) {
                    if (this->m_isBall)
                        PlayerObject::updatePlayerRollFrame(0);
                    else if (this->m_isDart)
                        PlayerObject::updatePlayerDartFrame(GDI_GET_VALUE(int64_t, "dart", 1));
                    else if (this->m_isSwing)
                        PlayerObject::updatePlayerSwingFrame(GDI_GET_VALUE(int64_t, "swing", 1));
                    else
                        PlayerObject::updatePlayerFrame(0);
                }
            }
        } else {
            if (PlayLayer::get()) {
                if (this == PlayLayer::get()->m_player2 && this->m_gamevar0060) {
                    if (this->m_isBall)
                        PlayerObject::updatePlayerRollFrame(GDI_GET_VALUE(int64_t, "roll", 1));
                    else if (this->m_isDart)
                        PlayerObject::updatePlayerDartFrame(GDI_GET_VALUE(int64_t, "dart", 1));
                    else if (this->m_isSwing)
                        PlayerObject::updatePlayerSwingFrame(GDI_GET_VALUE(int64_t, "swing", 1));
                    else
                        PlayerObject::updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1));
                }
            } else if (LevelEditorLayer::get()) {
                if (this == LevelEditorLayer::get()->m_player2 && this->m_gamevar0060) {
                    if (this->m_isBall)
                        PlayerObject::updatePlayerRollFrame(GDI_GET_VALUE(int64_t, "roll", 1));
                    else if (this->m_isDart)
                        PlayerObject::updatePlayerDartFrame(GDI_GET_VALUE(int64_t, "dart", 1));
                    else if (this->m_isSwing)
                        PlayerObject::updatePlayerSwingFrame(GDI_GET_VALUE(int64_t, "swing", 1));
                    else
                        PlayerObject::updatePlayerFrame(GDI_GET_VALUE(int64_t, "cube", 1));
                }
            }
        }
    }
};