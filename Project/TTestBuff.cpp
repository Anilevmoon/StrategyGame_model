#include <CRX/Base/TXTest.h>

#include <EntityPart/TMilitary.h>

struct TTestBuff : crx::TDebug::TXTest {

	std::vector<float> TestBuffs(NBuffType typeOne, NBuffType typeSecond, NBuffType typeThird, int MovesAfterBaffs) {
		TMilitary* military = new TMilitary();
		military->SetEntityPrototype(NEntityType::VillageWarior);

		military->TakeBuff(new TBuffs(typeOne));
		military->TakeBuff(new TBuffs(typeSecond));
		military->TakeBuff(new TBuffs(typeThird));


		for(auto i = 0; i<MovesAfterBaffs; i++) {
			military->BuffsNextMove();
		}

		float armorRes = military->Armor();
		std::vector<float> result = {military->Health(), military->GetAttack(), round(armorRes*100)/100};
		return result;
	}

	AUTOTEST_BODY(TTestBuff) {
		{
			std::vector<float> answer = {68.f, 20.f, 0.80f};
			Assert(TestBuffs(NBuffType::Poison, NBuffType::Weakness, NBuffType::ShittyArmor, 6)==answer, "Poison, Weakness, ShittyArmor"/*test msg*/);
		}

		{
			std::vector<float> answer = {92.f, 10.f, 1.f};
			Assert(TestBuffs(NBuffType::Poison, NBuffType::Weakness, NBuffType::ShittyArmor, 0)==answer, "Poison, Weakness, ShittyArmor"/*test msg*/);
		}
	}

};
