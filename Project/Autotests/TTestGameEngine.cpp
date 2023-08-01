#include <CRX/Base/TXTest.h>
#include <GameLogic/TGameEngine.h>
#include <GameLogic/TGameSession.h>
#include <WorldComponents/TWorld.h>


struct TTestGameEngine:crx::TDebug::TXTest {

	AUTOTEST_BODY(TTestGameEngine) {

		auto worldFirst = std::make_shared<TWorld>();
		worldFirst->m_pActiveMap->CreateMap();

		auto worldSecond = std::make_shared<TWorld>();
		worldSecond->m_pActiveMap->CreateMap();

		auto worldThird = std::make_shared<TWorld>();
		worldThird->m_pActiveMap->CreateMap();
		
		TGameEngine engine{};


		auto firstSES = std::make_shared<TGameSession>(worldFirst, worldFirst->m_pActiveMap);
		auto secondSES = std::make_shared<TGameSession>(worldSecond, worldSecond->m_pActiveMap);
		auto thirdSES = std::make_shared<TGameSession>(worldThird, worldThird->m_pActiveMap);

		engine.AddGameSession("First Map", firstSES);
		engine.AddGameSession("Second Map", secondSES);
		engine.AddGameSession("Third Map", thirdSES);

		Assert(engine.m_pSesions.size() == 3, "Add 3 GameSessions");
		Assert(engine.p_CurrentSession == nullptr, "No Set Current Session");
		
		engine.SetCurrentSession("Second Map");
		Assert(engine.p_CurrentSession == secondSES, "Set Second Session For Current");
	}
};