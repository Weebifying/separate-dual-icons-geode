#pragma once

#include "Macros.hpp"
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class SDIHelper {
public:
    bool m_incompatFound = false;
    std::string m_incompatMod = "";
    bool m_shouldWarnIncompat = false;

    bool m_isP2Main = false;
    bool m_shouldSwap = true;
    // this is so cursed but also like the only way to do this
    // plan: store the streaks in the helper upon setupStreak, then replace/remove accordingly bla bla
    CCMotionStreak* m_p1ShipFire = nullptr;
    CCMotionStreak* m_p2ShipFire = nullptr;

    static SDIHelper* get();
    void reset();
    void swapAll();
    void logAll();

    void loadDeathTextures(int id);
    void unloadDeathTextures(int id);
    void setPlayerInfo(PlayerObject* player, bool isP2);
    void setupNormalStreak(PlayerObject* player, bool isP2);
    void setupShipFire(PlayerObject* player, bool isP2);
    const char* getFrameForStreak(int shipFire, float delta);

    int getCube(bool isP2);
    int getShip(bool isP2);
    int getBall(bool isP2);
    int getUFO(bool isP2);
    int getWave(bool isP2);
    int getRobot(bool isP2);
    int getSpider(bool isP2);
    int getSwing(bool isP2);
    int getJetpack(bool isP2);
    int getTrail(bool isP2);
    int getShipTrail(bool isP2);
    int getDeathEffect(bool isP2);
    bool getDeathExplode(bool isP2);
    int getColor1(bool isP2);
    int getColor2(bool isP2);
    bool getGlow(bool isP2);
    int getGlowColor(bool isP2);
    CCMotionStreak* getShipFireNode(bool isP2);

private:
    SDIHelper() = default;
};