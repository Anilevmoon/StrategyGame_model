#include "TStartEntityCreator.h"

//std::vector<std::shared_ptr<IEntity>>::CreateStartUnits() {
//	std::vector<IEntity*>m_vAllEntities;
//
//	m_vAllEntities.push_back(new TUnit);
//
//	return m_vAllEntities;  
//}

std::vector<std::shared_ptr<IEntity>> TStartEntityCreator::CreateStartUnits(const std::vector<std::pair<NNUnitType, NOwner>>& prototypes) {
	std::vector<std::shared_ptr<IEntity>> result;
	for(auto& [type, owner]:prototypes) result.push_back( CreateUnitByPrototype(type, owner) );
	return result;
}

std::shared_ptr<IEntity> TStartEntityCreator::CreateUnitByPrototype(NNUnitType type, NOwner owner) {

	auto unitPtr = std::shared_ptr<TMilitary>(new TMilitary());

	unitPtr->SetUnitPrototype(type);
	unitPtr->m_owner=owner;
	if(owner==NOwner::Player1) {
															//Some default position depends on owner
		unitPtr->m_location.x = 3;
		unitPtr->m_location.y = 3;
		unitPtr->m_location.z = 1;
	} else if(owner==NOwner::Player2) {

		unitPtr->m_location.x = 4;
		unitPtr->m_location.y = 10;
		unitPtr->m_location.z = 1;
	}

	return unitPtr;
}
