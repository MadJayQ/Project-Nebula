#include "Engine.h"
#include "Timer.h"
#include "GlobalVars.h"

float flTimeAccumulator = 0.f;
float flLastTime = 0.0f;

std::unique_ptr<CGlobalVars> g_pGlobalVars;
std::unique_ptr<CTimer> g_pTimer;

CGlobalVars* GetGlobalVars()
{
	return g_pGlobalVars.get();
}

EngineInstance::EngineInstance()
{
}

EngineInstance::~EngineInstance()
{

}

void EngineInstance::Initialize()
{
	g_pGlobalVars = std::make_unique<CGlobalVars>();
	g_pGlobalVars->ui32Tickrate = 60;
	g_pGlobalVars->flTickInterval = 1.f / static_cast<float>(g_pGlobalVars->ui32Tickrate);
	g_pTimer = std::make_unique<CTimer>();
	g_pTimer->StartTimer();
	m_bLooping = true;
}

int EngineInstance::EngineLoop()
{
	while (m_bLooping)
	{
		if (!m_pOSMessageHandler->ProcessOSMessageLoop())
		{
			m_bLooping = false;
			break;
		}
		float flCurrentTime = g_pTimer->TimeConversion<Microseconds, Milliseconds>(g_pTimer->GetCurrentTimeStamp());
		float flTimeDelta = flCurrentTime - flLastTime;
		flTimeAccumulator += flTimeDelta;
		float flTargetTime = g_pGlobalVars->flTickInterval * 1000.f;
		while (flTimeAccumulator >= flTargetTime)
		{
			g_pGlobalVars->ui32TickCount++;
			flTimeAccumulator -= flTargetTime;
			Update(g_pGlobalVars->flTickInterval);
		}

		g_pGlobalVars->flInterpolation = flTimeAccumulator / flTargetTime;
		g_pGlobalVars->flCurrentTime = flCurrentTime;
		Render();

	}
	//Perform cleanup
	return 0;
}
