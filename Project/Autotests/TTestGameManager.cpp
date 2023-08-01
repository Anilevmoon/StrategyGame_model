#include <CRX/Base/TXTest.h>
#include <GameLogic/TGameTimeManager.h>
#include <WorldComponents/TWorld.h>

struct TTestGameManager :crx::TDebug::TXTest {

	AUTOTEST_BODY(TTestGameManager) {

		TWorld world{};
		world.m_pActiveMap->CreateMap();

		TPlayer player2{};
		TPlayer player1{};
		TGameTimeManager game{};


		game.FinishTurn.Bind(player1, &game.Turn);
		Assert(game.TurnNumber() == 0, "Without Turn");

		game.FinishTurn(player2);		
		Assert(game.TurnNumber() == 1, "First Turn");

		game.FinishTurn(player1);
		Assert(game.TurnNumber() == 2, "Second Turn");
	}
};
