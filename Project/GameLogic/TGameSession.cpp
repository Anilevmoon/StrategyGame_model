#include <GameLogic/TGameSession.h>
#include <WorldComponents/TWorld.h>

TGameSession::TGameSession(std::shared_ptr</*TWorldPrototype*/ TWorld> world, std::shared_ptr</*TMapPrototype*/ TMap> map) {
	p_CurrentWorld = world;
	p_CurrentMap = map;
}
