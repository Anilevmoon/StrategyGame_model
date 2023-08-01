#ifndef TWORLD_PROTOTYPE_H
#define TWORLD_PROTOTYPE_H

#include <WorldComponents/TObject.h>
#include <WorldComponents/TPlayer.h>

class TWorldPrototype : public TObject {
	public:
	TWorldPrototype();
	virtual ~TWorldPrototype()=default;
	DECL_REFLECTION_TABLE();

	std::vector<std::shared_ptr<TPlayerPrototype>> m_vPlayers; //Have Some quations
	std::vector<std::shared_ptr<TMapPrototype>> m_vMapsProto;

};

#endif  //TWORLD_PROTOTYPE_H