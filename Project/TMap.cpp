#include "TMap.h"

void TMap::CreateMap(int xCor, int yCor, int zCor, int wCor) {
	for(auto i = 0; i<yCor; ++i) {
		for(int it = 0; it<xCor; it++) {
			for(int itr = 0; itr<zCor; itr++) {
				auto element = std::make_shared<SMapElement>();
				element->x = it;
				element->y = i;
				element->z = itr;
				m_vMapElements.push_back(element);
			}
		}
	}
}

void TMap::SpawnAllUnits() {
	for(auto &currentUnit:m_vUnits) SpawnUnit(currentUnit);
}

void TMap::SpawnUnit(std::shared_ptr<IEntity> unit) {
	auto counter = 0;
	std::shared_ptr<SMapElement> mapElement = m_vMapElements[counter];

	while(unit->m_location.x!=m_vMapElements[counter]->x||unit->m_location.y!=m_vMapElements[counter]->y \
		  ||unit->m_location.z!=m_vMapElements[counter]->z||unit->m_location.w!=m_vMapElements[counter]->w) {

		counter++;
	}
	m_vMapElements[counter]->m_vObjects.push_back(unit);

}

