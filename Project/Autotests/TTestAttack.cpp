#include <CRX/Base/TXTest.h>

#include <WorldComponents/TWorld.h>
#include <EntityPart/TMilitary.h>

struct TTestAttack : crx::TDebug::TXTest {

	static const TWorld& AllCreation() {
		std::vector<std::pair<NEntityType, NOwner>> prototypesStart;

		prototypesStart.push_back(std::make_pair(NEntityType::Rogatchyky, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NEntityType::Rogatchyky, NOwner::Player2));
		prototypesStart.push_back(std::make_pair(NEntityType::VillageWarior, NOwner::Player1));
		prototypesStart.push_back(std::make_pair(NEntityType::VillageWarior, NOwner::Player2));
		prototypesStart.push_back(std::make_pair(NEntityType::Rogatchyky, NOwner::PC)); // Control

		TWorld* world = new TWorld;
		world->m_pActiveMap->CreateMap();
		world->m_pActiveMap->m_vUnits = world->m_pCreator->CreateStartUnits(prototypesStart);

		world->m_pActiveMap->m_vUnits[0]->SetCoordinates({0, 0});
		world->m_pActiveMap->m_vUnits[1]->SetCoordinates({2, 3});
		world->m_pActiveMap->m_vUnits[2]->SetCoordinates({6, 0});
		world->m_pActiveMap->m_vUnits[3]->SetCoordinates({1, 3});
		world->m_pActiveMap->m_vUnits[4]->SetCoordinates({2, 7});

		world->m_pActiveMap->SpawnAllEntity();

		world->m_pPlayer1->Entities() = world->m_pCreator->ChoosePlayerUnitsFromAll(world->m_pActiveMap->m_vUnits, world->m_pPlayer1->Type());
		world->m_pPlayer2->Entities() = world->m_pCreator->ChoosePlayerUnitsFromAll(world->m_pActiveMap->m_vUnits, world->m_pPlayer2->Type());

		world->m_pPlayer1->SeparateUnitsAndBuildings();
		world->m_pPlayer2->SeparateUnitsAndBuildings();

		return *world;
	}

	static int TestAttackAbillity(std::shared_ptr<IEntity> target, TWorld& world) {
		int areAbleToAttack = 0;

		for(auto& unit:world.m_pActiveMap->m_vUnits) {
			if(world.m_pActiveMap->IsCanAttack(unit, target)) {
				areAbleToAttack++;
			}
		}
		return areAbleToAttack;
	}

	static int TestAttack(std::shared_ptr<IEntity> target, TWorld& world) {

		for(auto& unit:world.m_pActiveMap->m_vUnits) {
			if(world.m_pActiveMap->IsCanAttack(unit, target)) {
				world.m_pActiveMap->Attack(unit, target);
			}
		}

		return target->Health();
	}

	AUTOTEST_BODY(TTestAttack) {
		auto world = AllCreation();

		{
			Assert(TestAttackAbillity(world.m_pPlayer2->Entities()[0].lock(), world)==2, "target{2, 3}, 2 able to attack");
			Assert(TestAttackAbillity(world.m_pPlayer1->Entities()[1].lock(), world)==1, "target{6, 0}, 1 able to attack");
			Assert(TestAttackAbillity(world.m_pPlayer2->Entities()[1].lock(), world)==2, "target{1, 3}, 2 able to attack");
			Assert(TestAttackAbillity(world.m_pPlayer1->Entities()[0].lock(), world)==1, "target{0, 0}, 1 able to attack");

		}

		{
			Assert(TestAttack(world.m_pPlayer1->Units()[0].lock(), world)==80, "target{0, 0}, 1 attack");
			Assert(TestAttack(world.m_pPlayer1->Units()[1].lock(), world)==80, "target{6, 0}, 1 attack");
			Assert(TestAttack(world.m_pPlayer2->Units()[0].lock(), world)==60, "target{2, 3}, 2 attack");
			Assert(TestAttack(world.m_pPlayer2->Units()[1].lock(), world)==60, "target{1, 3}, 2 attack");
		}
	}
};
