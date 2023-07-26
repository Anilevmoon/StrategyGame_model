#include <CRX/Base/TXTest.h>

#include <WorldWideComp/TWorld.h>
#include <EntityPart/TMilitary.h>

struct TTestMap : crx::TDebug::TXTest {

	int TestMap(const std::vector<std::pair<NEntityType, NOwner>>& protoStart) {
		TWorld world1{};

		world1.m_pActiveMap->CreateMap();


		world1.m_pActiveMap->m_vUnits = world1.m_pCreator->CreateStartUnits(protoStart);
		world1.m_pActiveMap->SpawnAllEntity();

		world1.m_pActiveMap->RemoveFromMap(world1.m_pActiveMap->m_vUnits[0]);

		int numberOfSpawnedUnits = 0;
		for(auto& mapElements:world1.m_pActiveMap->m_vMapElements) {
			numberOfSpawnedUnits += (int)mapElements->m_vObjects.size();
		}

		return numberOfSpawnedUnits;
	}

	AUTOTEST_BODY(TTestMap) {

		std::vector<std::pair<NEntityType, NOwner>> prototypesStart;

		prototypesStart.push_back(std::make_pair(NEntityType::VillageWarior, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NEntityType::VillageWarior, NOwner::Player1));


		{
			Assert(TestMap(prototypesStart)==1, "One created and one deleated Unit on map"/*test msg*/);
		}

		prototypesStart.push_back(std::make_pair(NEntityType::ForestMavka, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NEntityType::Kozak, NOwner::Player2));
		

		{
			Assert(TestMap(prototypesStart)==3, "Three Units created and one deleated on Map"/*test msg*/);
		}
	}

};
