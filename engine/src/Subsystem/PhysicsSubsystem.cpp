#include "PhysicsSubsystem.h"

#include "PositionComponent.h"
#include "PhysicsComponent.h"
#include "InputControllerComponent.h"

b2Vec2 WFVectorToB2Vector(const CVector& in)
{
	return b2Vec2(in._x, in._y);
}

CPhysicsSubsystem::CPhysicsSubsystem()
{
	m_pCollisionWorld = std::make_unique<b2World>(
		b2Vec2(
			0.0f,
			9.8f
		)
	);
}

CPhysicsSubsystem::~CPhysicsSubsystem()
{

}

void CPhysicsSubsystem::Tick(float flDeltaTime)
{
	for (auto& ent : m_registeredEntities)
	{
		CPositionComponent* pPositionComponent = ent->GetComponent<CPositionComponent>();
		CPhysicsComponent* pPhysicsComponent = ent->GetComponent<CPhysicsComponent>();

		if (!pPositionComponent || !pPhysicsComponent)
		{
			//Why tf is this entity attached to this subsystem???
			continue;
		}
		if (CInputControllerComponent* pInputComponent = ent->GetComponent<CInputControllerComponent>())
		{
			float flSpeedMod = pPhysicsComponent->GetMaxSpeed();
			CVector vecInput = pInputComponent->ConsumeInputVector();
			pPhysicsComponent->SetVelocity(
				vecInput * flSpeedMod
			);
		}
	}
	m_pCollisionWorld->Step(
		flDeltaTime,
		24,
		20
	);
}

void CPhysicsSubsystem::RegisterEntity(CEntityBase* ent)
{
	IGameSubsystem::RegisterEntity(ent);
}

void CPhysicsSubsystem::UnRegisterEntity(CEntityBase* ent)
{
	IGameSubsystem::UnRegisterEntity(ent);
}
