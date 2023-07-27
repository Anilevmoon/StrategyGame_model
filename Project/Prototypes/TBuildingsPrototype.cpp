#include "TBuildingsPrototype.h"
void TBuildingsPrototype::SetBuildingsPrototype(NEntityType type) {  

	switch(type)
	{
	case NEntityType::CossacksHouse:
		m_vBuildPoints.resize(1);
		m_fHealth=1000;
		break;
	case NEntityType::Coliba:
		m_vBuildPoints.resize(4);
		m_fHealth=800;
		break;
	case NEntityType::Mazanka:
		m_fHealth = 400;
		m_vBuildPoints.resize(2);
		break;
	default:
		break;
	}
}

void TBuildingsPrototype::SetCoordinates(std::vector<SMapPoint> cache) {
	for(int i = 0; i<cache.size(); ++i) { m_vBuildPoints[i] = std::make_shared<SMapPoint>(cache[i]); }
}
