#ifndef TPLAYER_PROTOTYPE_H
#define TPLAYER_PROTOTYPE_H

#include <WorldComponents/TObject.h>
#include <Enums/NOwner.h>


class TPlayerPrototype : public TObject{
	public:
	TPlayerPrototype(NOwner type = NOwner::PC) : m_xPlayerType(type){};
	virtual ~TPlayerPrototype()=default;
	DECL_REFLECTION_TABLE();

	NOwner m_xPlayerType;
};

#endif //TPLAYER_PROTOTYPE_H