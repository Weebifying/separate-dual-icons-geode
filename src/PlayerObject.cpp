#include "PlayerData.hpp"
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

        if (PlayLayer::get()) {
            if (PlayerData::callPosStreak == 1) {
                GameManager::get()->m_playerStreak = Mod::get()->getSavedValue<int64_t>("trail", 1);
                GameManager::get()->m_playerShipFire = Mod::get()->getSavedValue<int64_t>("shiptrail", 1);
            }

            PlayerData::callPosStreak++;
            if (PlayerData::callPosStreak == 2) PlayerData::callPosStreak = 0;
        }

        PlayerObject::setupStreak();

        GameManager::get()->m_playerStreak = origStreak;
        GameManager::get()->m_playerShipFire = origShipStreak;
    }

    void setColor(ccColor3B const &color) {
        PlayerObject::setColor(color);

        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::setColor(GameManager::get()->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::setColor(GameManager::get()->colorForIdx(Mod::get()->getSavedValue<int64_t>("color1", 0)));
        }
    }

    void setSecondColor(ccColor3B const &color) {
        PlayerObject::setSecondColor(color);

        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::setSecondColor(GameManager::get()->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::setSecondColor(GameManager::get()->colorForIdx(Mod::get()->getSavedValue<int64_t>("color2", 0)));
        }
    }

    void updatePlayerFrame(int p0) {
        PlayerObject::updatePlayerFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2) {
                if (m_fields->m_is2PMini && this->m_gamevar0060) PlayerObject::updatePlayerFrame(0);
                else PlayerObject::updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("cube", 1));
            }
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                if (m_fields->m_is2PMini && this->m_gamevar0060) PlayerObject::updatePlayerFrame(0);
                else PlayerObject::updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("cube", 1));
        }
    }
    
	void updatePlayerShipFrame(int p0) {
        PlayerObject::updatePlayerShipFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerShipFrame(Mod::get()->getSavedValue<int64_t>("ship", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerShipFrame(Mod::get()->getSavedValue<int64_t>("ship", 1));
        }
        
    }

    void updatePlayerRollFrame(int p0) {
        PlayerObject::updatePlayerRollFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                if (m_fields->m_is2PMini && this->m_gamevar0060) PlayerObject::updatePlayerRollFrame(0);
                else PlayerObject::updatePlayerRollFrame(Mod::get()->getSavedValue<int64_t>("roll", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                if (m_fields->m_is2PMini && this->m_gamevar0060) PlayerObject::updatePlayerRollFrame(0);
                else PlayerObject::updatePlayerRollFrame(Mod::get()->getSavedValue<int64_t>("roll", 1));
        }
        
    }

    void updatePlayerBirdFrame(int p0) {
        PlayerObject::updatePlayerBirdFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerBirdFrame(Mod::get()->getSavedValue<int64_t>("bird", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerBirdFrame(Mod::get()->getSavedValue<int64_t>("bird", 1));
        }
        
    }

    void updatePlayerDartFrame(int p0) {
        PlayerObject::updatePlayerDartFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerDartFrame(Mod::get()->getSavedValue<int64_t>("dart", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerDartFrame(Mod::get()->getSavedValue<int64_t>("dart", 1));
        }
        
    }

    void updatePlayerSwingFrame(int p0) {
        PlayerObject::updatePlayerSwingFrame(p0);
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerSwingFrame(Mod::get()->getSavedValue<int64_t>("swing", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerSwingFrame(Mod::get()->getSavedValue<int64_t>("swing", 1));
        }

    }

    void updatePlayerJetpackFrame(int p0) {
        PlayerObject::updatePlayerJetpackFrame(p0);
        
        
        if (PlayLayer::get()) {
            if (this == PlayLayer::get()->m_player2)
                PlayerObject::updatePlayerJetpackFrame(Mod::get()->getSavedValue<int64_t>("jetpack", 1));
        } else if (LevelEditorLayer::get()) {
            if (this == LevelEditorLayer::get()->m_player2)
                PlayerObject::updatePlayerJetpackFrame(Mod::get()->getSavedValue<int64_t>("jetpack", 1));
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
                if (this == PlayLayer::get()->m_player2) {
                    if (this->m_gamevar0060) {
                        if (this->m_isBall)
                            PlayerObject::updatePlayerRollFrame(0);
                        else if (this->m_isDart)
                            PlayerObject::updatePlayerDartFrame(Mod::get()->getSavedValue<int64_t>("dart", 1));
                        else if (this->m_isSwing)
                            PlayerObject::updatePlayerSwingFrame(Mod::get()->getSavedValue<int64_t>("swing", 1));
                        else
                            PlayerObject::updatePlayerFrame(0);
                    }
                }
            } else if (LevelEditorLayer::get()) {
                if (this == LevelEditorLayer::get()->m_player2) {
                    if (this->m_gamevar0060) {
                        if (this->m_isBall)
                            PlayerObject::updatePlayerRollFrame(0);
                        else if (this->m_isDart)
                            PlayerObject::updatePlayerDartFrame(Mod::get()->getSavedValue<int64_t>("dart", 1));
                        else if (this->m_isSwing)
                            PlayerObject::updatePlayerSwingFrame(Mod::get()->getSavedValue<int64_t>("swing", 1));
                        else
                            PlayerObject::updatePlayerFrame(0);
                    }
                }
            }
        } else {
            if (PlayLayer::get()) {
                if (this == PlayLayer::get()->m_player2) {
                    if (this->m_gamevar0060) {
                        if (this->m_isBall)
                            PlayerObject::updatePlayerRollFrame(Mod::get()->getSavedValue<int64_t>("roll", 1));
                        else if (this->m_isDart)
                            PlayerObject::updatePlayerDartFrame(Mod::get()->getSavedValue<int64_t>("dart", 1));
                        else if (this->m_isSwing)
                            PlayerObject::updatePlayerSwingFrame(Mod::get()->getSavedValue<int64_t>("swing", 1));
                        else
                            PlayerObject::updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("cube", 1));
                    }
                }
            } else if (LevelEditorLayer::get()) {
                if (this == LevelEditorLayer::get()->m_player2) {
                    if (this->m_gamevar0060) {
                        if (this->m_isBall)
                            PlayerObject::updatePlayerRollFrame(Mod::get()->getSavedValue<int64_t>("roll", 1));
                        else if (this->m_isDart)
                            PlayerObject::updatePlayerDartFrame(Mod::get()->getSavedValue<int64_t>("dart", 1));
                        else if (this->m_isSwing)
                            PlayerObject::updatePlayerSwingFrame(Mod::get()->getSavedValue<int64_t>("swing", 1));
                        else
                            PlayerObject::updatePlayerFrame(Mod::get()->getSavedValue<int64_t>("cube", 1));
                    }
                }
            }
        }
    }
};