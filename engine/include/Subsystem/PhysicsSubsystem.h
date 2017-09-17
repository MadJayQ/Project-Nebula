#pragma once
#include "GameSubsystem.h"
#include "CollisionComponent.h"
#include "Box2D.h"

class CPhysicsSubsystem : public IGameSubsystem
{
public:
	CPhysicsSubsystem();
	~CPhysicsSubsystem();

	virtual void Tick(float flDeltaTime) override;
	virtual void RegisterEntity(CEntityBase* ent) override;
	virtual void UnRegisterEntity(CEntityBase* ent) override;

	b2World* GetCollisionWorld() const { return m_pCollisionWorld.get(); }
private:
	std::unique_ptr<b2World> m_pCollisionWorld;
};