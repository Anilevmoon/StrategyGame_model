#ifndef TBUILD_UNIT_CREATOR_PROTOTYPE_H
#define TBUILD_UNIT_CREATOR_PROTOTYPE_H

#include <WorldComponents/TObject.h>
#include <Enums/NOwner.h>
#include<MapParts/TMap.h>
#include <WorldComponents/TStartEntityCreator.h>

class TBuildUnitCreatorPrototype : public TObject {
	public:
	TBuildUnitCreatorPrototype();
	void CreateUnit(NEntityType prototype, NOwner owner, SMapPoint location, std::weak_ptr<TMap> MapForCreateUnitByBuilding);
	
	public:
	std::vector<SMapPoint> Neighbours(SMapPoint cell);
	bool IsContain(const std::vector<std::shared_ptr<SMapElement>>& MapPoints, SMapPoint NeighbourCell);

	public:
	std::unique_ptr<TStartEntityCreator> p_FabricToCreateUnit = nullptr; 
	inline static std::vector<SMapPoint> s_vNeighbourOffsets = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
};

#endif // TBUILD_UNIT_CREATOR_PROTOTYPE_H



