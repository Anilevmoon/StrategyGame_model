#include <CRX/Base/TDebug.h>
#include <CRX/Base/TXTest.h>

#include <EntityPart/TBuildings.h>
#include <WorldComponents/TWorld.h>

static bool IsEqual(SMapPoint cache, SMapPoint cache2) {
	if(cache == cache2) return true;
	return false;
}


struct TTestCreateUnitFromBuilding :crx::TDebug::TXTest {

	AUTOTEST_BODY(TTestCreateUnitFromBuilding) {
		
		TWorld world1{};
		world1.m_pActiveMap->CreateMap();
		auto build = std::make_shared<TBuildings>();
		build->SetEntityPrototype(NEntityType::CossacksHouse);
			 
		build->SetMap(world1.m_pActiveMap);

		build->SetCoordinates({1,0,1,0});
		//world1.m_pActiveMap->SpawnEntity(build);
		build->AcquireUnit(NEntityType::Kozak);
		
		int numberOfSpawnedUnits = 0;
		for(auto& mapElements : world1.m_pActiveMap->m_vMapElements) {
			numberOfSpawnedUnits += (int) mapElements->m_vObjects.size();
		}
		Assert(numberOfSpawnedUnits == 1, "Create 1 Unit From Building");
		build->AcquireUnit(NEntityType::Chugaister);
		numberOfSpawnedUnits = 0;
		for(auto& mapElements : world1.m_pActiveMap->m_vMapElements) {
			numberOfSpawnedUnits += (int) mapElements->m_vObjects.size();
		}
		Assert(numberOfSpawnedUnits == 2, "Create 2 Unit From Building");
	}
};
