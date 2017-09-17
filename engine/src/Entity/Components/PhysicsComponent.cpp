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
}
