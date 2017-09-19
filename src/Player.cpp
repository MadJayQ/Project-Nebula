#include "Player.h"

#include "RenderSubsystem.h"
#include "PhysicsSubsystem.h"
#include "GameWorld.h"

CPlayer::CPlayer(ui32 ui32EntityID, CGameWorld* pGameWorld) 
	: CEntityBase(ui32EntityID, pGameWorld)
{
	m_pRenderComponent = AddComponent<C2DRenderComponent>();
	m_pPositionComponent = AddComponent<CPositionComponent>();

	pGameWorld->RegisterEntityToSubsystems<CRenderSubsystem, CPhysicsSubsystem>(this);
	
	m_pRenderComponent->SetSprite(
		new CSprite(
			"..\\assets\\player.png",
			SPRITE_FILE_TYPE_PNG
		)
	);
	m_bInterpolate = true;
}

CPlayer::~CPlayer()
{
}
