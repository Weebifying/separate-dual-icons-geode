// #include <Geode/Geode.hpp>
// using namespace geode::prelude;

// void PlayerObject::updatePlayerGlow() {
//     bool maybeIsVehicleGlowing = this->m_maybeIsVehicleGlowing;
//     CCSprite* iconGlow = this->m_iconGlow;

//     float iconScaleX = this->m_iconSprite->getScaleX();
//     iconGlow->setScaleX(iconScaleX);
//     float iconScaleY = this->m_iconSprite->getScaleY();
//     iconGlow->setScaleY(iconScaleY);
//     CCPoint iconPos = this->m_iconSprite->getPosition();
//     iconGlow->setPosition(iconPos);

//     bool isVehicleVisible;
//     bool vehicleShouldGlow;
//     bool shouldRobotOrSpiderGlow;

//     if ((maybeIsVehicleGlowing == false) && (maybeIsVehicleGlowing = false, this->m_hasGlow == false)) {
//         iconGlow->setVisible(false);
//     } else {
//         shouldRobotOrSpiderGlow = true;
//         maybeIsVehicleGlowing = true;
//         if ((this->m_isRobot == true) || (this->m_isSpider == true)) {
//             shouldRobotOrSpiderGlow = maybeIsVehicleGlowing;
//         }
//         iconGlow->setVisible(true);
//         isVehicleVisible = this->m_vehicleSprite->isVisible();
//         if (isVehicleVisible == false) {
//             vehicleShouldGlow = false;
//         }
//         vehicleShouldGlow = true;
//     }

//     CCSprite* vehicleGlow = this->m_vehicleGlow;
//     vehicleGlow->setVisible(vehicleShouldGlow);
//     CCPoint vehiclePos = this->m_vehicleSprite->getPosition();
//     this->m_vehicleGlow->setPosition(iconPos);

//     bool isRobotVisible;
//     bool isSpiderVisible;
//     bool idk;

//     if (shouldRobotOrSpiderGlow) {
//         isRobotVisible = this->m_robotSprite->isVisible();
//         if (isRobotVisible == false) {
//             vehicleGlow = this->m_robotSprite->m_glowSprite;
//         }
//         vehicleGlow = this->m_robotSprite->m_glowSprite;
//         vehicleGlow->setVisible(true);
//         if (isVehicleVisible == true) {
//             idk = true;
//             vehicleGlow = this->m_spiderSprite->m_glowSprite;
//         }
//     } else {
//         vehicleGlow->setVisible(false);
//         if (shouldRobotOrSpiderGlow) {
//             isVehicleVisible = this->m_spiderSprite->isVisible();
//         }
//     }
//     idk = false;

//     vehicleGlow->setVisible(idk);
// }

