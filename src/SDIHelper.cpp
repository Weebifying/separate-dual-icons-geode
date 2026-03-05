#include "SDIHelper.hpp"

SDIHelper* SDIHelper::get() {
    static SDIHelper instance;
    return &instance;
}

void SDIHelper::reset() {
    m_isP2Main = false;
    m_shouldSwap = true;
}

void SDIHelper::swapAll() {
    m_isP2Main = !m_isP2Main;
}

void SDIHelper::loadDeathTextures(int id) {
    auto GM = GameManager::get();
    if (id < 1) id = 1;

    if (id != GM->m_loadedDeathEffect && id > 1) {
        CCTextureCache::sharedTextureCache()->addImage(
            CCString::createWithFormat("PlayerExplosion_%02d.png", id-1)->getCString(),
            false
        );
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(
            CCString::createWithFormat("PlayerExplosion_%02d.plist", id-1)->getCString()
        );
    }
}

void SDIHelper::unloadDeathTextures(int id) {
    auto GM = GameManager::get();
    if (id < 1) id = 1;

    if (id != GM->m_loadedDeathEffect && id > 1) {
        CCTextureCache::sharedTextureCache()->removeTextureForKey(
            CCString::createWithFormat("PlayerExplosion_%02d.png", id-1)->getCString()
        );
    }
}

void SDIHelper::setPlayerInfo(PlayerObject* player, bool isP2) {
    auto GM = GameManager::get();

    player->setColor(GM->colorForIdx(this->getColor1(isP2)));
    player->setSecondColor(GM->colorForIdx(this->getColor2(isP2)));
    player->m_originalMainColor = GM->colorForIdx(this->getColor1(isP2));
    player->m_originalSecondColor = GM->colorForIdx(this->getColor2(isP2));
    if (player->m_isShip) {
        if (player->m_isPlatformer) {
            player->updatePlayerJetpackFrame(this->getJetpack(isP2));
            player->updatePlayerFrame(this->getCube(isP2));
        } else {
            player->updatePlayerShipFrame(this->getShip(isP2));
            player->updatePlayerFrame(this->getCube(isP2));
        }
    } else if (player->m_isBall) {
        player->updatePlayerRollFrame(this->getBall(isP2));
    } else if (player->m_isBird) {
        player->updatePlayerBirdFrame(this->getUFO(isP2));
        player->updatePlayerFrame(this->getCube(isP2));
    } else if (player->m_isDart) {
        player->updatePlayerDartFrame(this->getWave(isP2));
    } else if (player->m_isRobot) {
        player->updatePlayerRobotFrame(this->getRobot(isP2));
    } else if (player->m_isSpider) {
        player->updatePlayerSpiderFrame(this->getSpider(isP2));
    } else if (player->m_isSwing) {
        player->updatePlayerSwingFrame(this->getSwing(isP2));
    } else {
        player->updatePlayerFrame(this->getCube(isP2));
    }
    player->toggleGhostEffect(player->m_ghostType);
    player->m_hasGlow = this->getGlow(isP2);
    player->enableCustomGlowColor(GM->colorForIdx(this->getGlowColor(isP2)));
    player->updatePlayerGlow();
    player->updateGlowColor();
    setupNormalStreak(player, isP2);
    setupShipFire(player, isP2);
}

void SDIHelper::setupNormalStreak(PlayerObject* player, bool isP2) {
    player->m_streakStrokeWidth = 10.0;
    player->m_alwaysShowStreak = false;

    float streakFade = 0.3;
    float streakStroke = 10.0;
    switch (this->getTrail(isP2)) {
        case 2:
        case 7:
            streakStroke = 14.0;
            player->m_disableStreakTint = true;
            player->m_streakStrokeWidth = 14.0;
            break;
        case 3:
            streakStroke = 8.5;
            player->m_streakStrokeWidth = 8.5;
            break;
        case 4:
            streakFade = 0.4;
            streakStroke = 10.0;
            break;
        case 5:
            streakFade = 0.6;
            streakStroke = 5.0;
            player->m_streakStrokeWidth = 5.0;
            player->m_alwaysShowStreak = true;
            break;
        case 6:
            streakFade = 1.0;
            streakStroke = 3.0;
            player->m_streakStrokeWidth = 3.0;
            player->m_alwaysShowStreak = true;
            break;
    }
    
    player->m_playerStreak = this->getTrail(isP2);
    player->m_regularTrail->initWithFade(streakFade, 5.0, streakStroke, ccc3(255, 255, 255), CCString::createWithFormat("streak_%02d_001.png", this->getTrail(isP2))->getCString());
    if (this->getTrail(isP2) == 6) {
        player->m_regularTrail->enableRepeatMode(0.1);
    }
    player->m_regularTrail->m_fMaxSeg = 50.0;
    player->m_regularTrail->setBlendFunc({GL_SRC_ALPHA, GL_ONE});
    if (!player->m_disableStreakTint) {
        player->m_regularTrail->tintWithColor(player->getSecondColor());
    }
    if (!player->m_alwaysShowStreak) {
        player->m_regularTrail->stopStroke();        
    }
}

void SDIHelper::setupShipFire(PlayerObject* player, bool isP2) {
    auto SDI = SDIHelper::get();

    float streakFade = 0.0;
    float streakStroke = 0.0;
    switch (this->getShipTrail(isP2)) {
        case 2:
            streakFade = 0.0636;
            streakStroke = 22.0;
            break;
        case 3:
            streakFade = 0.1278;
            streakStroke = 28.6;
            break;
        case 4:
            streakFade = 0.105;
            streakStroke = 28.6;
            break;
        case 5:
            streakFade = 0.09;
            streakStroke = 18.7;
            break;
        case 6:
            streakFade = 0.096;
            streakStroke = 27.0;
            break;
    }

    player->m_shipStreakType = static_cast<ShipStreak>(this->getShipTrail(isP2));

    if (this->getShipTrail(isP2) > 1) {
        CCTexture2D* texture2d = CCTextureCache::get()->addImage(this->getFrameForStreak(this->getShipTrail(isP2), 0), false);
        CCMotionStreak* p = SDI->getShipFireNode(isP2);
        if (p) {
            p->setTexture(texture2d);
            player->m_shipStreak = p;
        }
        // player->m_shipStreak = CCMotionStreak::create(streakFade, 5.0, streakStroke, ccc3(255, 255, 255), texture2d);
        // player->m_shipStreak->m_fMaxSeg = 50.0;
        // player->m_shipStreak->m_bDontOpacityFade = true;
        // player->m_shipStreak->setBlendFunc({GL_SRC_ALPHA, GL_ONE});
    } else {
        player->m_shipStreak = nullptr;
    }
}

const char* SDIHelper::getFrameForStreak(int shipFire, float delta) {
    // robby toppy global func :/
    int spritesCount;
    float timeStep;
    if (shipFire == 4) {
        timeStep = 5.0/12;
    } else if (shipFire == 5) {
        timeStep = 0.05;
    } else if (shipFire == 6) {
        timeStep = 5.0/12;
    } else {
        timeStep = 3.0/96;
    }

    if (shipFire == 2) {
        spritesCount = 9;
    } else if (shipFire == 3) {
        spritesCount = 10;
    } else {
        if (shipFire == 4) spritesCount = 6;
        else if (shipFire == 5) spritesCount = 16;
        else if (shipFire == 6) spritesCount = 5;
        else spritesCount = 0;
    }

    if (spritesCount == 0) return "";
    int step = (int)floorf(delta / timeStep);
    int spriteStep = step % spritesCount + 1;

    return CCString::createWithFormat("shipfire%02d_%03d.png", shipFire, spriteStep)->getCString(); // org actually uses fmt but i cba
}

int SDIHelper::getCube(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "cube", 1)
        : GameManager::get()->getPlayerFrame();
}

int SDIHelper::getShip(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "ship", 1)
        : GameManager::get()->getPlayerShip();
}

int SDIHelper::getBall(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "roll", 1)
        : GameManager::get()->getPlayerBall();
}

int SDIHelper::getUFO(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "bird", 1)
        : GameManager::get()->getPlayerBird();
}

int SDIHelper::getWave(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "dart", 1)
        : GameManager::get()->getPlayerDart();
}

int SDIHelper::getRobot(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "robot", 1)
        : GameManager::get()->getPlayerRobot();
}

int SDIHelper::getSpider(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "spider", 1)
        : GameManager::get()->getPlayerSpider();
}

int SDIHelper::getSwing(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "swing", 1)
        : GameManager::get()->getPlayerSwing();
}

int SDIHelper::getJetpack(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "jetpack", 1)
        : GameManager::get()->getPlayerJetpack();
}

int SDIHelper::getTrail(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "trail", 1)
        : GameManager::get()->getPlayerStreak();
}

int SDIHelper::getShipTrail(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "shiptrail", 1)
        : GameManager::get()->getPlayerShipFire();
}

int SDIHelper::getDeathEffect(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "death", 1)
        : GameManager::get()->getPlayerDeathEffect();
}

bool SDIHelper::getDeathExplode(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(bool, "deathexplode", false)
        : GameManager::get()->getGameVariable("0153");
}

int SDIHelper::getColor1(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "color1", 0)
        : GameManager::get()->getPlayerColor();
}

int SDIHelper::getColor2(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(int64_t, "color2", 0)
        : GameManager::get()->getPlayerColor2();
}

bool SDIHelper::getGlow(bool isP2) {
    return m_isP2Main != isP2
        ? SDI_GET_VALUE(bool, "glow", false)
        : GameManager::get()->getPlayerGlow();
}

int SDIHelper::getGlowColor(bool isP2) {
    if (m_isP2Main != isP2) {
        int64_t colorglow = SDI_GET_VALUE(int64_t, "colorglow", 0);
        // vanilla behavior when glow color is -1
        if (colorglow == -1) {
            return SDI_GET_VALUE(int64_t, "color2", 0);
        }
        return colorglow;
    } else {
        int colorglow = GameManager::get()->getPlayerGlowColor();
        if (colorglow == -1) {
            return GameManager::get()->getPlayerColor2();
        }
        return colorglow;
    }
}

void SDIHelper::logAll() {
    log::info("isP2Main: {}", m_isP2Main);
}

CCMotionStreak* SDIHelper::getShipFireNode(bool isP2) {
    return m_isP2Main != isP2 ? m_p2ShipFire : m_p1ShipFire;
}

$on_mod(Loaded) {
    auto SDI = SDIHelper::get();
    SDI->reset();

    if (Loader::get()->isModLoaded("absolllute.megahack")) {
        SDI->m_incompatFound = true;
        SDI->m_incompatMod = "Mega Hack";
        SDI->m_shouldWarnIncompat = true;
    } else if (Loader::get()->isModLoaded("thesillydoggo.qolmod")) {
        SDI->m_incompatFound = true;
        SDI->m_incompatMod = "QOLMod";
        SDI->m_shouldWarnIncompat = true;
    }
};
