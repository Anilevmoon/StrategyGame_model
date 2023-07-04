#include "TXTest.h"
#include "TDebug.h"
#include "TMilitary.h"

using namespace NNBaffsType;

struct TTestBuff : crx::TDebug::TXTest {

	std::vector<float> TestBuffs(NMagicType typeOne, NMagicType typeSecond, NMagicType typeThird, int MovesAfterBaffs) {
		TMilitary* military = new TMilitary();
		military->SetUnitPrototype(NNUnitType::VillageWarior);

		military->TakeBuff(new TMagic(typeOne));
		military->TakeBuff(new TMagic(typeSecond));
		military->TakeBuff(new TMagic(typeThird));


		for(auto i = 0; i<MovesAfterBaffs; i++) {
			military->BuffsNextMove();
		}

		float armorRes = military->m_fActualArmor;
		std::vector<float> result = {military->getHealth(), military->getAttack(), round(armorRes*100)/100};
		return result;
	}

	AUTOTEST_BODY(TTestBuff) {
		{
			std::vector<float> answer = {68.f, 20.f, 0.80f};
			Assert(TestBuffs(Poison, Weakness, ShittyArmor, 6)==answer, "Poison, Weakness, ShittyArmor"/*test msg*/);
		}

		{
			std::vector<float> answer = {92.f, 10.f, 1.f};
			Assert(TestBuffs(Poison, Weakness, ShittyArmor, 0)==answer, "Poison, Weakness, ShittyArmor"/*test msg*/);
		}
	}

};
