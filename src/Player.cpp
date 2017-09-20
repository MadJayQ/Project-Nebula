#include "Player.h"

#include "RenderSubsystem.h"
#include "PhysicsSubsystem.h"
#include "InputSubsystem.h"
#include "GameWorld.h"

CPlayer::CPlayer(ui32 ui32EntityID, CGameWorld* pGameWorld) 
	: CEntityBase(ui32EntityID, pGameWorld)
{
	m_pRenderComponent = AddComponent<C2DRenderComponent>();
	m_pPositionComponent = AddComponent<CPositionComponent>();
	m_pPhysicsComponent = AddComponent<CPhysicsComponent>();
	m_pInputComponent = AddComponent<CInputControllerComponent>();

	pGameWorld->RegisterEntityToSubsystems<CRenderSubsystem, CInputSubsystem, CPhysicsSubsystem>(this);
	
	m_pRenderComponent->SetSprite(
		new CSprite(
			"..\\assets\\player.png",
			SPRITE_FILE_TYPE_PNG
		)
	);


	m_pPhysicsComponent->m_BodyDef.type = b2_dynamicBody;
	m_pPhysicsComponent->m_BodyDef.fixedRotation = true;
	m_pPhysicsComponent->m_BodyDef.gravityScale = 0.0f;
	m_pPhysicsComponent->m_BodyDef.angularVelocity = 0.f;
	auto pCollisionWorld = pGameWorld->GetSubsystem<CPhysicsSubsystem>()->GetCollisionWorld();
	m_pPhysicsComponent->m_pBody = pCollisionWorld->CreateBody(
		&m_pPhysicsComponent->m_BodyDef
	);

	
	b2PolygonShape shape;
	shape.SetAsBox(1.f, 2.f);

	b2FixtureDef fixtureDef;
	fixtureDef.friction = 0.f;
	fixtureDef.shape = &shape;
	m_pPhysicsComponent->m_pFixture = m_pPhysicsComponent->m_pBody->CreateFixture(&fixtureDef);
	
	m_bInterpolate = true;
}

CPlayer::~CPlayer()
{
}
