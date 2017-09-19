#pragma once
#include <memory>

#include "Timer.h"
#include "OSMessageHandler.h"
#include "GlobalVars.h"
#define ENGINE_API __stdcall
#define REGISTER_ENGINE_CLASS(classType) std::unique_ptr<classType> pEnginePtr = std::unique_ptr<classType>(new classType());

#include "GameWorld.h"

class EngineInstance
{
public:
	explicit EngineInstance();
	~EngineInstance();

	virtual void Initialize();
	virtual int EngineLoop();

	virtual void Update(float flDeltaTime) = 0;
	virtual void Render();

	virtual void CreateInputMapping() = 0; //Change this to have engine default input mappings??
protected:
	bool m_bLooping = false;
	IOSMessageHandler* m_pOSMessageHandler;
	CGameWorld*	m_pGameWorld;
};
