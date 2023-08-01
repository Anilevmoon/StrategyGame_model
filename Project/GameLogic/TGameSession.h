#ifndef TGAME_SESSION_H
#define TGAME_SESSION_H

#include <WorldComponents/TObject.h>

//class TWorldPrototype;
//class TMapPrototype;

class TWorld;
class TMap;

class TGameSession : public TObject {
	public:
	TGameSession()=default;
	TGameSession(std::shared_ptr</*TWorldPrototype*/ TWorld> world, std::shared_ptr</*TMapPrototype*/ TMap> map);
	~TGameSession()=default;

	public:
	std::shared_ptr<TWorld> p_CurrentWorld;
	std::shared_ptr<TMap> p_CurrentMap;
	/*std::shared_ptr<TWorldPrototype> p_CurrentWorld;
	std::shared_ptr<TMapPrototype> p_CurrentMap;*/
	

	
	//void AddGameSession( std::shared_ptr<TWorldPrototype> world, std::shared_ptr<TMapPrototype> map);
};



#endif // TGAME_SESSION_H



