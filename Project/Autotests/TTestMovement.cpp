#include <CRX/Base/TXTest.h>

#include <WorldComponents/TWorld.h>
#include <EntityPart/TMilitary.h>

inline static SMapPoint DefaultUnitLocation ={1, 1, 0, 0};

struct TTestMovement : crx::TDebug::TXTest {

	static const TWorld& AllCreation(SMapPoint Location) {
		std::vector<std::pair<NEntityType, NOwner>> prototypesStart;

		prototypesStart.push_back(std::make_pair(NEntityType::Kozak, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NEntityType::Kozak, NOwner::Player2));
		prototypesStart.push_back(std::make_pair(NEntityType::VillageWarior, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NEntityType::VillageWarior, NOwner::Player2));

		TWorld* world = new TWorld;
		world->m_pActiveMap->CreateMap();
		world->m_pActiveMap->m_vUnits = world->m_pCreator->CreateStartUnits(prototypesStart);

		world->m_pActiveMap->m_vUnits[0]->SetCoordinates(Location);
		world->m_pActiveMap->m_vUnits[1]->SetCoordinates(Location);
		world->m_pActiveMap->m_vUnits[2]->SetCoordinates(Location);
		world->m_pActiveMap->m_vUnits[3]->SetCoordinates(Location);
		world->m_pActiveMap->SpawnAllEntity();
		return *world;
	}

	static int TestMovementAbillity(SMapPoint point) {
		int areAble = 0;
		auto& world = AllCreation(DefaultUnitLocation);

		for(auto& unit:world.m_pActiveMap->m_vUnits) {
			if(world.m_pActiveMap->IsCanMoveTo(unit, world.m_pActiveMap->FindLocationOnMap(point))) {
				areAble++;
			}
		}
		return areAble;
	}

	static int TestMove(SMapPoint point) {
		auto& world = AllCreation(DefaultUnitLocation);
		std::shared_ptr<SMapElement> aimedElement = world.m_pActiveMap->FindLocationOnMap(point);

		for(auto& unit:world.m_pActiveMap->m_vUnits) {
			if(world.m_pActiveMap->IsCanMoveTo(unit, aimedElement)) {
				world.m_pActiveMap->MoveTo(unit, aimedElement);
			} 
		}
		return (int)aimedElement->m_vObjects.size();
		//world.m_pActiveMap->FindLocationOnMap(DefaultUnitLocation)->m_vObjects.size();	//Default point where entities were before moving
	}

	AUTOTEST_BODY(TTestMovement) {
		{
			Assert(TestMovementAbillity({0, 0})==4, "4 are able to move");
			Assert(TestMovementAbillity({6, 0})==2, "2 are able to move");
			Assert(TestMovementAbillity({6, 5})==0, "0 are able to move");
		}

		{
			Assert(TestMove({0, 0})==4, "4 Moved to destination point");
			Assert(TestMove({6, 0})==2, "2 Moved to destination point");
			Assert(TestMove({6, 5})==0, "0 Moved to destination point");
		}
	}

};
