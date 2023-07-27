#include "TStartEntityCreator.h"

static SMapPoint s_defaultPlayerOnePosition ={1, 1, 1, 0};
static SMapPoint s_defaultPlayerTwoPosition ={10, 10, 1, 0};

std::vector<std::shared_ptr<TUnit>> TStartEntityCreator::CreateStartUnits(const std::vector<std::pair<NEntityType, NOwner>>& prototypes) {
	std::vector<std::shared_ptr<TUnit>> result;
	for(auto& [type, owner]:prototypes) result.push_back( CreateUnitByPrototype(type, owner) );
	return result;
}

std::vector<std::weak_ptr<IEntity>> TStartEntityCreator::ChoosePlayerUnitsFromAll(std::vector<std::shared_ptr<TUnit>>& playersEntities, NOwner owner) {
	std::vector<std::weak_ptr<IEntity>> ownersEntities;
	for(auto entity : playersEntities){ 
		if(entity->Owner()==owner) ownersEntities.push_back(entity); 
	}
	return ownersEntities;
}

std::shared_ptr<TUnit> TStartEntityCreator::CreateUnitByPrototype(NEntityType type, NOwner owner = NOwner::PC) {
	auto unitPtr = (type==NEntityType::ForestMavka || type==NEntityType::Chugaister) ? std::make_shared<TForestChimeras>() : std::make_shared<TMilitary>();

	unitPtr->SetEntityPrototype(type);
	unitPtr->ChangeOwner(owner);

	if(owner==NOwner::Player1) { unitPtr->m_xLocation = s_defaultPlayerOnePosition; }
	if(owner==NOwner::Player2) { unitPtr->m_xLocation = s_defaultPlayerTwoPosition; }

	return unitPtr;
}
