#include "TXTest.h"
#include "TDebug.h"

#include "TWorld.h"
#include "TMilitary.h"

using namespace NNBaffsType;

struct TTestMap : crx::TDebug::TXTest {

	int TestMap(const std::vector<std::pair<NNUnitType, NOwner>>& protoStart) {
		TWorld world1{};

		world1.m_pActiveMap->CreateMap();


		world1.m_pActiveMap->m_vUnits = world1.m_creator->CreateStartUnits(protoStart);
		world1.m_pActiveMap->SpawnAllUnits();

		int numberOfSpawnedUnits = 0;
		for(auto& mapElements:world1.m_pActiveMap->m_vMapElements) {
			numberOfSpawnedUnits += (int)mapElements->m_vObjects.size();
		}

		return numberOfSpawnedUnits;
	}

	AUTOTEST_BODY(TTestMap) {

		std::vector<std::pair<NNUnitType, NOwner>> prototypesStart;

		prototypesStart.push_back(std::make_pair(NNUnitType::VillageWarior, NOwner::Player1));

		{
			Assert(TestMap(prototypesStart)==1, "One created Unit on map"/*test msg*/);
		}

		prototypesStart.push_back(std::make_pair(NNUnitType::ForestMavka, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NNUnitType::Kozak, NOwner::Player2));

		{
			Assert(TestMap(prototypesStart)==3, "Three Units created on Map"/*test msg*/);
		}
	}

};
