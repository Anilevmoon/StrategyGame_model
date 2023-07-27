#include <CRX/Base/TXTest.h>

#include <WorldComponents/TWorld.h>
#include <EntityPart/TMilitary.h>

struct TTestOwner : crx::TDebug::TXTest {

	int TestOwner(const std::vector<std::pair<NEntityType, NOwner>>& protoStart, NOwner playerOwner) {
		TWorld world1{};
		world1.m_pActiveMap->CreateMap();
		world1.m_pActiveMap->m_vUnits = world1.m_pCreator->CreateStartUnits(protoStart);

		world1.m_pActiveMap->m_vUnits[0]->ChangeOwner(NOwner::Player2);	//Every time we change first unit to Owner::Player2

		if(playerOwner==world1.m_pPlayer1->Type()) {
			return (int)world1.m_pCreator->ChoosePlayerUnitsFromAll(world1.m_pActiveMap->m_vUnits, NOwner::Player1).size();

		} else if(playerOwner==world1.m_pPlayer2->Type()) {
			return (int)world1.m_pCreator->ChoosePlayerUnitsFromAll(world1.m_pActiveMap->m_vUnits, NOwner::Player2).size();

		} else if(playerOwner==world1.m_pComputer->Type()) {
			return (int)world1.m_pCreator->ChoosePlayerUnitsFromAll(world1.m_pActiveMap->m_vUnits, NOwner::PC).size();
		}

		return -1;
	}

	AUTOTEST_BODY(TTestOwner) {

		std::vector<std::pair<NEntityType, NOwner>> prototypesStart;

		prototypesStart.push_back(std::make_pair(NEntityType::VillageWarior, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NEntityType::VillageWarior, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NEntityType::VillageWarior, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NEntityType::Kozak, NOwner::Player2));
		prototypesStart.push_back(std::make_pair(NEntityType::Kozak, NOwner::Player2));


		{
			Assert(TestOwner(prototypesStart, NOwner::Player1)==2, "Player1 Owner test (UNITS ONLY)"/*test msg*/);
		}

		prototypesStart.push_back(std::make_pair(NEntityType::ForestMavka, NOwner::Player2));
		prototypesStart.push_back(std::make_pair(NEntityType::Kozak, NOwner::Player2));
		prototypesStart.push_back(std::make_pair(NEntityType::Kozak, NOwner::Player2));


		{
			Assert(TestOwner(prototypesStart, NOwner::Player2)==6, "Player2 Owner test (UNITS ONLY)"/*test msg*/);
		}


		prototypesStart.push_back(std::make_pair(NEntityType::ForestMavka, NOwner::PC));
		prototypesStart.push_back(std::make_pair(NEntityType::Kozak, NOwner::PC));
		prototypesStart.push_back(std::make_pair(NEntityType::Kozak, NOwner::PC));


		{
			Assert(TestOwner(prototypesStart, NOwner::PC)==3, "PC Owner test (UNITS ONLY)"/*test msg*/);
		}
	}

};
