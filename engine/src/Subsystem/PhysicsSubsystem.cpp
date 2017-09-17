#include "PhysicsSubsystem.h"


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
