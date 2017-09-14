#pragma once
#include "Engine.h"
#include "Platform_Windows.h"
#include "GraphicDevice.h"
#include "EventObserver.h"

class GameInstance : public EngineInstance
{
public:
	GameInstance();
	~GameInstance();
	
	virtual void Initialize() override;
	virtual int EngineLoop() override;

	virtual void Update(float flDeltaTime) override;
	virtual void Render() override;
	virtual void CreateInputMapping() override;

private:
	void CreateGameWindow();
	void SetupNetworkConnections();
private:
	std::unique_ptr<CWin32GameWindow> m_pGameWindow;
	std::unique_ptr<CGraphicsDevice> m_pGraphicsDevice;
};
REGISTER_ENGINE_CLASS(GameInstance)