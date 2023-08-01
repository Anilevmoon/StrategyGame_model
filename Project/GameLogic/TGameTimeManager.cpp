#include <GameLogic/TGameTimeManager.h>

TPlayer TGameTimeManager::FinishTurnImplementation(TPlayer player) {

	auto tempOwner = player.Type();	
	for(int i = 0; i < v_Players.size(); ++i) {
		if(v_Players[i].Type() == tempOwner) { return (i == 0) ? v_Players[++i] : v_Players[--i];	}
	}

	return player;	
}

void TGameTimeManager::AddPlayers(TPlayer player) { v_Players.push_back(player); }
void TGameTimeManager::SetMap(std::shared_ptr<TMap> map) { p_CurrentMap = map; }


int TGameTimeManager::TurnNumber() { return i_TurnNumber; }
void TGameTimeManager::Turn() { ++i_TurnNumber; }

NGameState TGameTimeManager::GameState() { return x_GameState; }
void TGameTimeManager::SetGameState(NGameState state) { x_GameState = state; }

//void TGameTimeManager::GoldAfterTurn() { x_CurrentPlayer.i_Gold += 300; }
//void TGameTimeManager::ResfreshEntityStatsForCurrentPlayer() { x_CurrentPlayer.RefreshStats(); }
//void TGameTimeManager::TakingGoldFromPlayerBuildings() { x_CurrentPlayer.CalculateBuildingGold(); }
