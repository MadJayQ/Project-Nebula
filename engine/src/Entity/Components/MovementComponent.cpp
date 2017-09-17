#include "MovementComponent.h"

CMovementComponent::CMovementComponent()
{
	m_bAccelerates = false;
	m_vecVelocity = CVector(0.f, 0.f);
}

CMovementComponent::~CMovementComponent()
{

}

void CMovementComponent::ApplyMovement(CPositionComponent* pPositionComponent, float flDeltaTime, bool bAccelerates)
{
	if (bAccelerates || m_bAccelerates)
	{
		m_vecVelocity += m_vecAcceleration;
	}

	CVector& position = pPositionComponent->GetPositon();
	position._x += m_vecVelocity._x * flDeltaTime;
	position._y += m_vecVelocity._y * flDeltaTime;
}

void CMovementComponent::SetAcceleration(CVector vecAcceleration)
{
	m_vecAcceleration = vecAcceleration;
}

void CMovementComponent::SetVelocity(CVector vecVelocity)
{
	m_vecVelocity = vecVelocity;
}
