#pragma once

#include "EntityComponent.h"
#include "Vector.h"

class CPositionComponent : public IEntityComponent
{
public:
	CPositionComponent();
	~CPositionComponent();

	CVector& GetPositon()
	{
		return m_vecPosition;
	}

	CVector& GetOldPosition()
	{
		return m_vecOldPosition;
	}

	void SetPosition(CVector pos) { m_vecPosition = pos; }
	void SetOldPosition(CVector pos) { m_vecOldPosition = pos; }

private:
	CVector m_vecPosition;
	CVector m_vecOldPosition;
};
