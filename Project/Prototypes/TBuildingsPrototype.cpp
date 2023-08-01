#include "TBuildingsPrototype.h"
#include <CRX/Reflection/TReflectionImplDefs.h>

BEGIN_REFLECTION_TABLE(TBuildingsPrototype, TObject)
ADD_PROPERTY(Health, m_fHealth);
ADD_PROPERTY(Type, m_xType);
END_REFLECTION_TABLE();


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



