#pragma once

#include "Macros.hpp"
#include <Geode/Geode.hpp>
using namespace geode::prelude;

class SDIHelper {
public:
    bool m_isP2Main = false;

    int m_p1Cube = 1;
    int m_p1Ship = 1;
    int m_p1Ball = 1;
    int m_p1UFO = 1;
    int m_p1Wave = 1;
    int m_p1Robot = 1;
    int m_p1Spider = 1;
    int m_p1Swing = 1;
    int m_p1Jetpack = 1;
    int m_p1Trail = 1;
    int m_p1ShipTrail = 1;
    int m_p1DeathEffect = 1;
    bool m_p1DeathExplode = false;
    int m_p1Color1 = 0;
    int m_p1Color2 = 0;
    bool m_p1Glow = false;
    int m_p1GlowColor = 0;

    int m_p2Cube = 1;
    int m_p2Ship = 1;
    int m_p2Ball = 1;
    int m_p2UFO = 1;
    int m_p2Wave = 1;
    int m_p2Robot = 1;
    int m_p2Spider = 1;
    int m_p2Swing = 1;
    int m_p2Jetpack = 1;
    int m_p2Trail = 1;
    int m_p2ShipTrail = 1;
    int m_p2DeathEffect = 1;
    bool m_p2DeathExplode = false;
    int m_p2Color1 = 0;
    int m_p2Color2 = 0;
    bool m_p2Glow = false;
    int m_p2GlowColor = 0;

    static SDIHelper* get();
    void reset();
    void swapAll();
    void logAll();

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

private:
    SDIHelper() = default;
};