#include "TWorldPrototype.h"
#include <CRX/Reflection/TReflectionImplDefs.h>

BEGIN_REFLECTION_TABLE(TWorldPrototype, TObject)
ADD_PROPERTY(Players, m_vPlayers);
ADD_PROPERTY(Maps, m_vMapsProto);

END_REFLECTION_TABLE();

TWorldPrototype::TWorldPrototype() {
	m_vPlayers.push_back(std::make_shared<TPlayerPrototype>()); //I Dont know is it true and how to take UnitPrototypes from Handbook here
	//m_vMapsProto.push_back(std::make_shared<TMapPrototype>());
}
