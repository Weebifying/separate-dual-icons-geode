#include "PlayerData.hpp"
#include <Geode/modify/CharacterColorPage.hpp>

class $modify(CharacterColorPage) {
    bool init() {
        if (!CharacterColorPage::init()) return false;

        auto layer = getChildOfType<CCLayer>(this, 0);
        

        return true;
    }
};