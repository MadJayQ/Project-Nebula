#include "CollisionSubsystem.h"

#include "MovementComponent.h"
#include "PositionComponent.h"
#include "UnitMetrics.h"


b2Vec2 WFVectorToB2Vector(const CVector& in)
{
	return b2Vec2(in._x, in._y);
}
CCollisionSubsystem::CCollisionSubsystem()
{
	m_pCollisionWorld = std::make_unique<b2World>(b2Vec2(0.0f, 9.8));

}

CCollisionSubsystem::~CCollisionSubsystem()
{

}
void CCollisionSubsystem::Tick(float flDeltaTime)
{
	m_pCollisionWorld->Step(flDeltaTime, 24, 20);
}

void CCollisionSubsystem::RegisterEntity(CEntityBase* ent)
{
	IGameSubsystem::RegisterEntity(ent);
}

void CCollisionSubsystem::UnRegisterEntity(CEntityBase* ent)
{
	IGameSubsystem::UnRegisterEntity(ent);
}

