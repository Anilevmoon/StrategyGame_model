#include <CRX/Base/TXTest.h>

#include <WorldComponents/TWorld.h>
#include <EntityPart/TBuildings.h>

struct TTestSpawnBuilding : crx::TDebug::TXTest {

	AUTOTEST_BODY(TTestSpawnBuilding) {

		{
			TWorld world1{};
			world1.m_pActiveMap->CreateMap();
			auto currentmap = world1.m_pActiveMap;
			auto prototypesStart = std::make_pair(NEntityType::Coliba, NOwner::PC);
			world1.m_pCreator->CreateBuildingsByPrototype(prototypesStart, currentmap);
			Assert(world1.m_pActiveMap->m_vBuildings.size() == 1, "Create One Building Without Coordinate By Creator");
		}

		{
			TWorld world1{};
			world1.m_pActiveMap->CreateMap();
			auto currentmap = world1.m_pActiveMap;
			auto prototypesStart = std::make_pair(NEntityType::Coliba, NOwner::PC);
			SMapPoint BuildingCoordinate{1,1,1,0};

			world1.m_pCreator->CreateBuildingsByPrototype(prototypesStart, currentmap, BuildingCoordinate);
			Assert(world1.m_pActiveMap->m_vBuildings.size() == 1, "Create One Building With Coordinate By Creator");
			world1.m_pActiveMap->SpawnAllEntity();
			int numberOfSpawnedUnits = 0;
			for(auto& mapElements : world1.m_pActiveMap->m_vMapElements) {
				numberOfSpawnedUnits += (int) mapElements->m_vObjects.size();
			}
			Assert(numberOfSpawnedUnits == 1, "Spawn One Building With Coordinate");
		}

		{
			TWorld world1{};
			world1.m_pActiveMap->CreateMap();
			auto currentmap = world1.m_pActiveMap;
			std::vector<SMapPoint> CoordinateContainer { {1, 1, 1, 0}, {0,0,0,0}, {1,2,2,0}, {2,1,2,0}, {2,2,2,0} };
			std::vector<std::pair<NEntityType, NOwner>> prototypesStart; 
			prototypesStart.push_back(std::make_pair(NEntityType::Coliba, NOwner::Player1));
			prototypesStart.push_back(std::make_pair(NEntityType::Mazanka, NOwner::PC));
			prototypesStart.push_back(std::make_pair(NEntityType::CossacksHouse, NOwner::PC));
			prototypesStart.push_back(std::make_pair(NEntityType::CossacksHouse, NOwner::PC));
			prototypesStart.push_back(std::make_pair(NEntityType::Coliba, NOwner::Player2));

			int i = 0;
			for(; i < CoordinateContainer.size();++i) {				
				world1.m_pActiveMap->SpawnEntity(world1.m_pCreator->CreateBuildingsByPrototype(prototypesStart[i], currentmap, CoordinateContainer[i]));
			}

			int numberOfSpawnedUnits = 0;
			for(auto& mapElements : world1.m_pActiveMap->m_vMapElements) {
				numberOfSpawnedUnits += (int) mapElements->m_vObjects.size();
			}
			Assert(numberOfSpawnedUnits == 5, "Spawn Five Buildings With Coordinate");
		}

		{
			TWorld world1{};
			world1.m_pActiveMap->CreateMap();
			auto currentmap = world1.m_pActiveMap;
			std::vector<SMapPoint> CoordinateContainer { {1, 1, 1, 0}, {0,0,0,0}, {1,2,2,0} };
			std::vector<std::pair<NEntityType, NOwner>> prototypesStart;
			prototypesStart.push_back(std::make_pair(NEntityType::Coliba, NOwner::Player1));
			prototypesStart.push_back(std::make_pair(NEntityType::Mazanka, NOwner::PC));
			prototypesStart.push_back(std::make_pair(NEntityType::CossacksHouse, NOwner::PC));
			prototypesStart.push_back(std::make_pair(NEntityType::CossacksHouse, NOwner::PC));
			prototypesStart.push_back(std::make_pair(NEntityType::Coliba, NOwner::Player2));
			
			int i = 0;
			for(; i < CoordinateContainer.size();++i) {	world1.m_pActiveMap->SpawnEntity(world1.m_pCreator->CreateBuildingsByPrototype(prototypesStart[i], currentmap, CoordinateContainer[i])); }
			for(; i < prototypesStart.size();++i) world1.m_pCreator->CreateBuildingsByPrototype(prototypesStart[i], currentmap, CoordinateContainer[i]);


			int numberOfSpawnedUnits = 0;
			for(auto& mapElements : world1.m_pActiveMap->m_vMapElements) {
				numberOfSpawnedUnits += (int) mapElements->m_vObjects.size();
			}

			Assert( numberOfSpawnedUnits == 3 && world1.m_pActiveMap->m_vBuildings.size() == 5, "Create Five Buildings and Spawn only Three Buildings ");
		}
				
	}
};