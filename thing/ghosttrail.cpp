// #include <Geode/Geode.hpp>
// using namespace geode::prelude;

// void  PlayerObject::toggleGhostEffect(GhostType type) {
//     byte bVar2;
//     longlong *plVar3;
//     undefined2 *puVar4;
//     undefined8 uVar6;
//     char cStackX_11;
    
//     if (this->m_ghostType == type) {
//         return;
//     }
//     this->m_ghostType = type;

//     GhostTrailEffect* ghostTrail = this->m_ghostTrail;
//     if (ghostTrail != nullptr) {
//         void* ghostTrailDelegate = ghostTrail->m_delegate;
//         if (ghostTrailDelegate != nullptr) {
//             // (**(code **)*ghostTrailDelegate)(ghostTrail); // jesus fucking christ
//         }

//         ghostTrail->unscheduleAllSelectors();
//         ghostTrail->stopAllActions();
//         ghostTrail->removeMeAndCleanup();
//         this->m_ghostTrail = nullptr;
//     }

//     if (this->m_ghostType != GhostType::Enabled) {
//         return;
//     }

//     // what even
//     puVar4 = (undefined2 *) (**(code **)((this->m_iconSprite)->CCRGBAProtocol + 8))();
//     if ((((char)*puVar4 == '\0') && (cStackX_11 = (char)((ushort)*puVar4 >> 8), cStackX_11 == '\0')) && (*(char *)(puVar4 + 1) == '\0')) {

//         ghostTrail = GhostTrailEffect::create();
//         this->m_ghostTrail = ghostTrail;
//         ghostTrail->m_playerObject = this;

//         this->m_ghostTrail->m_playerScale = this->m_vehicleSize;
//         this->m_ghostTrail->m_opacity = 200.0;

//         ghostTrail->m_color.r = 0;
//         ghostTrail->m_color.g = 0;
//         ghostTrail->m_color.b = 0;
//         ghostTrail->m_iconSprite = this->m_iconSprite;
//         ghostTrail->m_snapshotInterval = 0.05;
//         ghostTrail->m_fadeInterval = 0.4;
//         ghostTrail->m_ghostScale = 0.6;
//         ghostTrail->m_scaleTwice = false;

//         ghostTrail->schedule(schedule_selector(GhostTrailEffect::trailSnapshot), 0.05);
//         if (DAT_1406c2ed8 != (longlong *)0x0) goto LAB_14039f0b7;
//         uVar6 = FUN_1404d0770(0x668);
//         DAT_1406c2ed8 = (longlong *)FUN_14017ab00(uVar6);
//     }
//     else {
//         ghostTrail = GhostTrailEffect::create();
//         this->m_ghostTrail = ghostTrail;
//         ghostTrail->m_playerObject = this;

//         ghostTrail->m_blendFunc.src = 770;
//         ghostTrail->m_blendFunc.dst = 1;
//         this->m_ghostTrail->m_playerScale = this->m_vehicleSize;
//         this->m_ghostTrail->m_opacity = 200.0;

//         ghostTrail->m_color.r = this->m_playerColor1.r;
//         ghostTrail->m_color.g = this->m_playerColor1.g;
//         ghostTrail->m_color.b = this->m_playerColor1.b;
//         ghostTrail->m_iconSprite = this->m_iconSprite;
//         ghostTrail->m_snapshotInterval = 0.05;
//         ghostTrail->m_fadeInterval = 0.4;
//         ghostTrail->m_ghostScale = 0.6;
//         ghostTrail->m_scaleTwice = false;

//         ghostTrail->schedule(schedule_selector(GhostTrailEffect::trailSnapshot), 0.05);

//         if (DAT_1406c2ed8 != (longlong *)0x0) goto LAB_14039f0b7;
//         uVar6 = FUN_1404d0770(0x668);
//         DAT_1406c2ed8 = (longlong *)FUN_14017ab00(uVar6);
//     }
//     (**(code **)(*DAT_1406c2ed8 + 0x48))(DAT_1406c2ed8);

// LAB_14039f0b7:
//     plVar3 = DAT_1406c2ed8;
//     this->m_ghostTrail->m_objectLayer =
//         *(CCLayer **)(DAT_1406c2ed8[0x41] + 0xfe8);
//     (**(code **)(**(longlong **)(plVar3[0x41] + 0xfe8) + 0x1c0))
//                 (*(longlong **)(plVar3[0x41] + 0xfe8),(this->PlayerObject_data).m_ghostTrail);
// }    