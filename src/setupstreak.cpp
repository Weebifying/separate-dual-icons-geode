// #include <Geode/Geode.hpp>
// using namespace geode::prelude;
// using namespace fmt;

// void PlayerObject::setupStreak() {
//     GameManager* GM = GameManager::get();
//     int streakID = GM->m_playerStreak.value();
//     if (streakID < 7) {
//         if (streakID < 2) {
//             streakID = 1;
//         }
//     }
//     else {
//         streakID = 7;
//     }
//     this->m_playerStreak = streakID;
//     this->m_hasGlow = GM->m_playerGlow;
    
//     CCString* streakCCString = CCString::createWithFormat("streak_%02d_001.png");
//     const char* streakTexture = streakCCString->getCString();
//     this->m_streakStrokeWidth = 10.0;

//     float streakFade = 0.3;
//     float streakStroke = 10.0;
//     switch (this->m_playerStreak) {
//         case 2:
//         case 7:
//             streakStroke = 14.0;
//             this->m_disableStreakTint = true;
//             this->m_streakStrokeWidth = 14.0;
//             break;
//         case 3:
//             streakStroke = 8.5;
//             this->m_streakStrokeWidth = 8.5;
//             break;
//         case 4:
//             streakFade = 0.4;
//             streakStroke = 10.0;
//             break;
//         case 5:
//             streakFade = 0.6;
//             streakStroke = 5.0;
//             this->m_streakStrokeWidth = 5.0;
//             this->m_alwaysShowStreak = true;
//             break;
//         case 6:
//             streakFade = 1.0;
//             streakStroke = 3.0;
//             this->m_streakStrokeWidth = 3.0;
//             this->m_alwaysShowStreak = true;
//     }
//     CCMotionStreak* streakMoStr = CCMotionStreak::create(streakFade, 5.0, streakStroke, ccc3(255, 255, 255), streakTexture);
//     this->m_regularTrail = streakMoStr;
//     if (this->m_playerStreak == 6) {
//         streakMoStr->enableRepeatMode(0.1);
//     }
    
//     this->m_regularTrail->m_fMaxSeg = 50.0;
//     CCLayer* parentLayer = this->m_parentLayer;
//     parentLayer->addChild(this->m_regularTrail, -2);

//     ShipStreak shipFireID = static_cast<ShipStreak>(GM->m_playerShipFire.value());
//     this->m_shipStreakType = shipFireID;
//     if (int(shipFireID) < 7 && int(shipFireID) > 1) {
//         streakFade = 0.0;
//         streakStroke = 0.0;
//         if (shipFireID == ShipStreak::ShipFire2) {
//             streakFade = 0.0636;
//             streakStroke = 22.0;
//         }
//         else if (shipFireID == ShipStreak::ShipFire3) {
//             streakFade = 0.1278;
//             streakStroke = 28.6;
//         }
//         else if (shipFireID == ShipStreak::ShipFire4) {
//             streakFade = 0.105;
//             streakStroke = 28.6;
//         }
//         else if (shipFireID == ShipStreak::ShipFire5) {
//             streakFade = 0.09;
//             streakStroke = 18.7;
//         }
//         else if (shipFireID == ShipStreak::ShipFire6) {
//             streakFade = 0.096;
//             streakStroke = 27.0;
//         }

//         streakTexture = FUN_140386060((int)shipFireID, 0).c_str();

//         CCTextureCache* textureCache = CCTextureCache::sharedTextureCache();
//         CCTexture2D* texture2D = textureCache->addImage(streakTexture, false);
//         CCMotionStreak* shipFireMoStr = CCMotionStreak::create(streakFade, 1.0, streakStroke, ccc3(255, 255, 255), texture2D);
//         this->m_shipStreak = shipFireMoStr;

//         parentLayer = this->m_parentLayer;
//         parentLayer->addChild(this->m_shipStreak, -3);
//         this->m_shipStreak->m_fMaxSeg = 50.0;
//         this->m_shipStreak->m_bDontOpacityFade = true;

//         this->m_shipStreak->setBlendFunc({GL_SRC_ALPHA, GL_ONE});
//     }
//     else {
//         this->m_shipStreakType = ShipStreak::ShipFire1;
//     }

//     this->m_regularTrail->setBlendFunc({GL_SRC_ALPHA, GL_ONE});

//     HardStreak* waveStreak = HardStreak::create();
//     this->m_waveTrail = waveStreak;
//     parentLayer = this->m_parentLayer;
//     parentLayer->addChild(waveStreak, -3);
    
//     if ((GM->m_playerColor.value() == 15) && (this->m_switchWaveTrailColor == false)) { // black color
//         this->m_waveTrail->m_isSolid = true;
//     } else {
//         this->m_waveTrail->setBlendFunc({GL_SRC_ALPHA, GL_ONE});
//     }

//     this->m_regularTrail->stopStroke();
//     if (this->m_fadeOutStreak != false) {
//         this->m_fadeOutStreak = false;
//         if (this->m_playEffects == false) {
//             streakFade = 0.6;
//         }
//         else {
//             streakFade = 0.2;
//         }
//         this->fadeOutStreak2(streakFade);
//     }
// }

// std::string FUN_140386060(int shipFire, float delta) {
//     int spritesCount;
//     float timeStep;
//     if (shipFire == 4) {
//         timeStep = 5.0/12;
//     } else if (shipFire == 5) {
//         timeStep = 0.05;
//     } else if (shipFire == 6) {
//         timeStep = 5.0/12;
//     } else {
//         timeStep = 3.0/96;
//     }

//     if (shipFire == 2) {
//         spritesCount = 9;
//     } else if (shipFire == 3) {
//         spritesCount = 10;
//     } else {
//         if (shipFire == 4) spritesCount = 6;
//         if (shipFire == 5) spritesCount = 16;
//         if (shipFire == 6) spritesCount = 5;
//         spritesCount = 0;
//     }

//     int step = (int)floorf(delta / timeStep);
//     int spriteStep = step % spritesCount + 1;

//     return fmt::format("shipfire%02d_%03d.png", shipFire, spriteStep);
// }