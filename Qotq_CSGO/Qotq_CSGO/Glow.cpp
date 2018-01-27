#include "Glow.h"

void CGlow::Start() {
	CGlowObjectManager* GlowObjectManager = g_pGlowObjectManager;
	CGlowObjectManager::GlowObjectDefinition_t* glowEntity;
	auto local = g_pEntityList->GetClientEntity(g_pEngine->GetLocalPlayer());

	for (int i = 0; i < GlowObjectManager->size; i++)
	{
		glowEntity = &GlowObjectManager->m_GlowObjectDefinitions[i];
		C_BaseEntity* Entity = glowEntity->getEntity();
		if (!Entity) continue;
		ClientClass* EntityClass = (ClientClass*)Entity->GetClientClass();
		if (EntityClass->m_ClassID == ClassId_CCSPlayer) {
			Color cglow;
			cglow = Entity->Team() == local->Team() ? Color(0, 255, 0, 255) : Color(255, 0, 0, 255);
			glowEntity->set(cglow);
		}
	}
}