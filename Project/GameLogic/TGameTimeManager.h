#ifndef TGAME_TIME_MANAGER
#define TGAME_TIME_MANAGER

#include <Enums/NGameState.h>
#include <WorldComponents/TPlayer.h>
#include <MapParts/TMap.h>
#include <Algorithm/TSmartFunction.h>

class TGameTimeManager : public TObject {
	public:
	TGameTimeManager()=default;
	~TGameTimeManager()=default;
	
	public:
	int TurnNumber();
	static void Turn();

	public:
	NGameState GameState();
	void SetGameState(NGameState state);

	public:
	TPlayer FinishTurnImplementation(TPlayer player); 
	void AddPlayers(TPlayer player);
	
	public:
	void SetMap(std::shared_ptr<TMap> map);

	public:
	TSmartFunction<TPlayer(TPlayer)> FinishTurn{this, &TGameTimeManager::FinishTurnImplementation};

	//public: 
	//void GoldAfterTurn();
	//void ResfreshEntityStatsForCurrentPlayer();
	//void TakingGoldFromPlayerBuildings();

	public:
	TPlayer x_CurrentPlayer;
	NGameState x_GameState;

	public:
	std::weak_ptr<TMap> p_CurrentMap;
	inline static int i_TurnNumber = 0;

	public:
	std::vector<TPlayer> v_Players;

};

#endif // TGAME_TIME_MANAGER