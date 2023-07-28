#include <CRX/Base/TDebug.h>
#include <CRX/Base/TXTest.h>

#include <WorldComponents/TWorld.h>
#include <EntityPart/TForestChimeras.h>

struct TTestForestChimeras : crx::TDebug::TXTest {


	std::shared_ptr<TMilitary> TestForestChimeras(int MavkaSkill, int ChugaisterSkill) {
		std::vector<std::pair<NEntityType, NOwner>> gameUnits;

		gameUnits.emplace_back(NEntityType::VillageWarior, NOwner::Player1);
		gameUnits.emplace_back(NEntityType::ForestMavka, NOwner::Player1);

		gameUnits.emplace_back(NEntityType::Chugaister, NOwner::Player2);
		gameUnits.emplace_back(NEntityType::Kozak, NOwner::Player2);

		TWorld world1{};

		world1.m_pActiveMap->CreateMap();
		world1.m_pActiveMap->m_vUnits = world1.m_pCreator->CreateStartUnits(gameUnits);
		world1.m_pActiveMap->SpawnAllEntity();


		std::shared_ptr<TForestChimeras> forestMavkaPtr = nullptr;
		std::shared_ptr<TForestChimeras> forestChugaisterPtr = nullptr;
		std::shared_ptr<TMilitary> testUnitPtr = nullptr;


		for(auto unit:world1.m_pActiveMap->m_vUnits) {

			auto unitPtr = std::dynamic_pointer_cast<TUnit>(unit);
			if(unitPtr->m_pPrototype->m_xType==NEntityType::ForestMavka) {
				forestMavkaPtr = std::dynamic_pointer_cast<TForestChimeras>(unitPtr);
			}

			if(unitPtr->m_pPrototype->m_xType==NEntityType::Chugaister) {
				forestChugaisterPtr = std::dynamic_pointer_cast<TForestChimeras>(unitPtr);
			}

			if(testUnitPtr==nullptr&&unitPtr->m_pPrototype->m_xType!=NEntityType::ForestMavka&&unitPtr->m_pPrototype->m_xType!=NEntityType::Chugaister) {
				testUnitPtr = std::dynamic_pointer_cast<TMilitary>(unitPtr);
			}
		}

		testUnitPtr->TakeBuff(forestMavkaPtr->MagicAffectAttack(MavkaSkill));
		testUnitPtr->TakeBuff(forestChugaisterPtr->MagicAffectAttack(ChugaisterSkill));

		return testUnitPtr;
	}

	AUTOTEST_BODY(TTestForestChimeras) {

		{
			Assert(TestForestChimeras(0, 0)->Health()==92.0f, " Poison By Chugaister");
			Assert(TestForestChimeras(1, 2)->GetAttack()==10.0f, "Weakness by Chugaister");
			Assert(TestForestChimeras(3, 1)->GetAttack()==30.0f, "PowerAttack by Mavka");
			Assert(TestForestChimeras(0, 1)->Armor()>0.90f, "Shitty Armor Chugaister");
		}
	}

};
