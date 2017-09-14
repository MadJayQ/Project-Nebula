#include "GameInstance.h"
#define GAME_INSTANCE
#include "Engine.h"
#include "Windows_EntryPoint.cpp"

namespace Global
{
	constexpr const char* g_szBuildDate = __DATE__;
	constexpr const char* g_szBuildTime = __TIME__;
	constexpr const char* g_szVersion = "Windows Development Build v.0.0.0";
	constexpr const char* g_szClassName = "CLASS_Project Nebula";

	namespace Platform
	{
		MSG g_lastMessage = MSG{ 0 };
	}
}

void GameInstance::CreateGameWindow()
{
	/*
		Allocate memory for name buffer and then free afterwards
	*/
	char* szNameBuffer = (char*)(malloc(256));
	sprintf_s(
		szNameBuffer, 
		256,
		"Project: Nebula - %s Build Date: %s @ %s EST",
		Global::g_szVersion, 
		Global::g_szBuildDate, 
		Global::g_szBuildTime
	);
	m_pGameWindow = std::make_unique<CWin32GameWindow>(g_hInstance, szNameBuffer, Global::g_szClassName);
	m_pOSMessageHandler = m_pGameWindow.get();

	free(szNameBuffer);
}
void GameInstance::SetupNetworkConnections()
{

}

GameInstance::GameInstance() : EngineInstance()
{

}

GameInstance::~GameInstance()
{
	EngineInstance::~EngineInstance();
	m_pGameWindow.reset();
	m_pGameWindow.release();
}

void GameInstance::Initialize()
{
	EngineInstance::Initialize();
	//Load scripts and resources
	CreateGameWindow();
	SetupNetworkConnections();
}

int GameInstance::EngineLoop()
{
	return EngineInstance::EngineLoop();
}

void GameInstance::Update(float flDeltaTime)
{
}

void GameInstance::Render()
{
}

void GameInstance::CreateInputMapping()
{
}