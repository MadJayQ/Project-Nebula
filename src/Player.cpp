#include "Player.h"

CPlayer::CPlayer(ui32 ui32EntityID, CGameWorld* pGameWorld) 
	: CEntityBase(ui32EntityID, pGameWorld)
{
	m_pRenderComponent = AddComponent<C2DRenderComponent>();
	m_pPositionComponent = AddComponent<CPositionComponent>();

	m_bInterpolate = true;
}

CPlayer::~CPlayer()
{
}
