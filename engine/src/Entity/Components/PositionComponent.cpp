#include "PositionComponent.h"

CPositionComponent::CPositionComponent()
{
	m_vecPosition = CVector(0.f, 0.f);
	m_vecOldPosition = CVector(0.f, 0.f);
}

CPositionComponent::~CPositionComponent()
{
}
