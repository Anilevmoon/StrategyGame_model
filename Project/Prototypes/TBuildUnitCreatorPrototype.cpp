#include "TBuildUnitCreatorPrototype.h"

TBuildUnitCreatorPrototype::TBuildUnitCreatorPrototype() { p_FabricToCreateUnit = std::make_unique<TStartEntityCreator>(); }

void TBuildUnitCreatorPrototype::CreateUnit(NEntityType prototype, NOwner owner, SMapPoint location, std::weak_ptr<TMap> mapForCreateUnitByBuilding) {
    auto flagForSpawn = false;
    std::vector<std::pair<NEntityType, NOwner>> tempConteiner {{prototype, owner}};
    std::shared_ptr<TUnit> newUnit;
    auto map = mapForCreateUnitByBuilding.lock();
    auto possiblePositionContainer = Neighbours(location);

for(int i = 0;i < possiblePositionContainer.size();++i) {
    if(IsContain(map->m_vMapElements, possiblePositionContainer[i])) {
        newUnit = p_FabricToCreateUnit->CreateUnitFromBuilding(prototype, owner, possiblePositionContainer[i]);
        map->SpawnEntity(newUnit);
        map->m_vUnits.push_back(newUnit);
        flagForSpawn = true;
        break;
    }
}
    if(!flagForSpawn) {
        newUnit = p_FabricToCreateUnit->CreateUnitFromBuilding(prototype, owner, {-1,-1,-1,-1});
        map->m_vUnits.push_back(newUnit);
    }
}

std::vector<SMapPoint> TBuildUnitCreatorPrototype::Neighbours(SMapPoint cell) {
    std::vector<SMapPoint> CellWithOffsets;
    for(int i = 0;i < s_vNeighbourOffsets.size();++i) {
        SMapPoint CellWithOffset;
        CellWithOffset = cell + s_vNeighbourOffsets[i];
        CellWithOffsets.push_back(CellWithOffset);
    }
    return CellWithOffsets;
}

bool TBuildUnitCreatorPrototype::IsContain(const std::vector<std::shared_ptr<SMapElement>>& MapElements, SMapPoint NeighbourCell) {
    auto filter = [NeighbourCell](auto element) {
        return NeighbourCell==element->Location();
    };
    return std::find_if(MapElements.begin(), MapElements.end(), filter) != MapElements.end();
}