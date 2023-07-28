#include "TBuildingsPrototype.h"
void TBuildingsPrototype::SetBuildingsPrototype(NEntityType type) {  
	m_xType = type;

	switch(type) {
	case NEntityType::CossacksHouse:
		m_fHealth=1000;
		break;
	case NEntityType::Coliba:
		m_fHealth=800;
		
		break;
	case NEntityType::Mazanka:
		m_fHealth = 400;

		break;
	default:
		break;
	}
}



