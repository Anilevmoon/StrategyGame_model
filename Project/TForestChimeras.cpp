#include "TForestChimeras.h"

void TForestChimeras::SetEntityPrototype(NEntityType type) {
	if(type==NEntityType::ForestMavka) {
		m_vAttackMagicSkills ={{new TBuffs(NBuffType::Hill)}, {new TBuffs(NBuffType::Regeneration)}, {new TBuffs(NBuffType::DiamondArmor)}, {new TBuffs(NBuffType::PowerAttack)}};
	}
	if(type==NEntityType::Chugaister) {
		m_vAttackMagicSkills ={{new TBuffs(NBuffType::Poison)}, {new TBuffs(NBuffType::ShittyArmor)}, {new TBuffs(NBuffType::Weakness)}};
	}

	TMilitary::SetEntityPrototype(type);
}

TBuffs* TForestChimeras::MagicAffectAttack(int skillNumber) {
	return skillNumber>m_vAttackMagicSkills.size() ? nullptr : m_vAttackMagicSkills[skillNumber];
}
