#include "PhysicsComponent.h"

CPhysicsComponent::CPhysicsComponent()
{

}

CPhysicsComponent::~CPhysicsComponent()
{

}

void CPhysicsComponent::SetVelocity(CVector velocity)
{
	//Check velocity length against m_flMaxSpeed
	m_vecVelocity = velocity;
	if (m_pBody)
	{
		m_pBody->SetLinearVelocity(
			b2Vec2(
				velocity._x,
				velocity._y
			)
		);
	}
}
