#pragma once
#include "Entity.h"

#include "2DRenderComponent.h"
#include "PositionComponent.h"
#include "PhysicsComponent.h"

class CPlayer : public CEntityBase
{
public:
	CPlayer(ui32 ui32EntityID, CGameWorld* pGameWorld);
	~CPlayer();

protected:
	C2DRenderComponent* m_pRenderComponent;
	CPositionComponent* m_pPositionComponent;
	CPhysicsComponent* m_pPhysicsComponent;

};