#pragma once

#include "EntityComponent.h"
#include "Sprite.h"
#include "UnitMetrics.h"
#include "Box2D.h"

#include <memory>

enum ECollisionType
{
	COLLISION_TYPE_SOLID,
	COLLISION_TYPE_TRIGGER,
	COLLISION_TYPE_PICKUP,
	COLLISION_TYPE_ENTITY
};

class CPhysicsComponent : public IEntityComponent
{
public:
	CPhysicsComponent();
	~CPhysicsComponent();

	void SetVelocity(CVector velocity);
	void SetAcceleration(CVector vecAcceleration) { m_vecAcceleration = vecAcceleration; }

	void SetAccelerates(bool bAccelerates) { m_bAccelerates = bAccelerates; }
	bool Accelerates() const { return m_bAccelerates; }

	void SetMaxSpeed(float flMaxSpeed) { m_flMaxSpeed = flMaxSpeed; }
	float GetMaxSpeed() const { return m_flMaxSpeed; }

	float GetCurrentSpeed() const { return m_flSpeed; }

	CVector GetVelocity() const { return m_vecVelocity; }
	CVector GetAcceleration() const { return m_vecAcceleration; }

	void SetCollisionType(ECollisionType type) { m_collisionType = type; }
	ECollisionType GetCollisionType() const { return m_collisionType; }


public:
	std::unique_ptr<b2BodyDef> m_pBodyDef;
	std::unique_ptr<b2FixtureDef> m_pFixture;

private:
	float m_flSpeed;
	float m_flMaxSpeed;

	CVector m_vecVelocity;
	CVector m_vecAcceleration;

	bool m_bAccelerates;

	ECollisionType m_collisionType;
};