#include <WorldComponents/TStartEntityCreator.h>
#include <EntityPart/TBuildings.h>
#include <MapParts/TMap.h>

static SMapPoint s_defaultPlayerOnePosition ={1, 1, 1, 0};
static SMapPoint s_defaultPlayerTwoPosition ={10, 10, 1, 0};

SMapPoint s_xDefaultCoordinateCreatedBuildings = {-1, -1, -1, -1};

std::vector<std::shared_ptr<TUnit>> TStartEntityCreator::CreateStartUnits(const std::vector<std::pair<NEntityType, NOwner>>& prototypes) {
    std::vector<std::shared_ptr<TUnit>> result;
    for(auto& [type, owner] : prototypes) result.push_back(CreateUnitByPrototype(type, owner));
    return result;
}

std::vector<std::weak_ptr<IEntity>> TStartEntityCreator::ChoosePlayerUnitsFromAll(std::vector<std::shared_ptr<TUnit>>& playersEntities, NOwner owner) {
    std::vector<std::weak_ptr<IEntity>> ownersEntities;
    for(auto entity : playersEntities) {
        if(entity->Owner() == owner) ownersEntities.push_back(entity);
    }
    return ownersEntities;
}

std::shared_ptr<TUnit> TStartEntityCreator::CreateUnitByPrototype(NEntityType type, NOwner owner = NOwner::PC) {
    auto unitPtr = (type == NEntityType::ForestMavka || type == NEntityType::Chugaister) ? std::make_shared<TForestChimeras>() : std::make_shared<TMilitary>();

    unitPtr->SetEntityPrototype(type);
    unitPtr->ChangeOwner(owner);

    if(owner == NOwner::Player1) { unitPtr->m_xLocation = s_defaultPlayerOnePosition; }
    if(owner == NOwner::Player2) { unitPtr->m_xLocation = s_defaultPlayerTwoPosition; }

    return unitPtr;
}

std::shared_ptr<TUnit> TStartEntityCreator::CreateUnitFromBuilding(NEntityType type, NOwner owner, SMapPoint location) {
	std::vector<std::shared_ptr<TUnit>> result;
	auto unitPtr = (type == NEntityType::ForestMavka || type == NEntityType::Chugaister) ? std::make_shared<TForestChimeras>() : std::make_shared<TMilitary>();
	unitPtr->SetEntityPrototype(type);
	unitPtr->ChangeOwner(owner);
	unitPtr->m_xLocation = location;
	return unitPtr;
}
     
std::shared_ptr<IEntity> TStartEntityCreator::CreateBuildingsByPrototype(const std::pair<NEntityType, NOwner>& prototypes, std::shared_ptr<TMap> currentMap, SMapPoint location) {	
	
	auto Build = std::make_shared<TBuildings>();
	Build->SetEntityPrototype(prototypes.first);
	Build->SetCoordinates(location);
	Build->ChangeOwner(prototypes.second);
	currentMap->m_vBuildings.push_back(Build);
	return Build;
}