#ifndef TSTART_ENTITY_CREATOR_H
#define TSTART_ENTITY_CREATOR_H

#include <EntityPart/TForestChimeras.h>

class TBuildings;
class TMap;

extern SMapPoint s_xDefaultCoordinateCreatedBuildings;

class TStartEntityCreator {
	public:
	TStartEntityCreator()=default;
	virtual ~TStartEntityCreator() = default;

	public:
	std::shared_ptr<TUnit> CreateUnitFromBuilding(NEntityType type, NOwner owner, SMapPoint location);
	std::shared_ptr<IEntity> CreateBuildingsByPrototype(const std::pair<NEntityType, NOwner>& prototypes, std::shared_ptr<TMap> currentMap, SMapPoint location = s_xDefaultCoordinateCreatedBuildings);

	public:
	std::vector<std::shared_ptr<TUnit>> CreateStartUnits(const std::vector<std::pair<NEntityType, NOwner>>& prototypes);
	std::vector<std::weak_ptr<IEntity>> ChoosePlayerUnitsFromAll(std::vector<std::shared_ptr<TUnit>>& playersEntities, NOwner owner);

	protected:
	std::shared_ptr<TUnit> CreateUnitByPrototype(NEntityType type, NOwner owner);

};

#endif //TSTART_ENTITY_CREATOR_H