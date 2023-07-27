#include "TUnitPrototype.h"

void TUnitPrototype::SetPrototype(NEntityType type) {
	m_xType = type;

	switch(m_xType)
	{
		case NEntityType::VillageWarior:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 3;
		m_fArmor = 0.80f;
		m_iAttackRange = 1;
		break;

		case NEntityType::Kozak:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 6;
		m_fArmor = 0.80f;
		m_iAttackRange = 1;
		break;

		case NEntityType::PigRider:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 3;
		m_fArmor = 0.80f;
		m_iAttackRange = 1;
		break;

		case NEntityType::Tarain:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 3;
		m_fArmor = 0.80f;
		m_iAttackRange = 1;
		break;

		case NEntityType::Rogatchyky:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 3;
		m_fArmor = 0.80f;
		m_iAttackRange = 1;
		break;

		case NEntityType::SichShoters:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 3;
		m_fArmor = 0.80f;
		m_iAttackRange = 1;
		break;

		case NEntityType::Catapulta:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 3;
		m_fArmor = 0.80f;
		m_iAttackRange = 1;
		break;

		case NEntityType::ForestMavka:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 3;
		m_fArmor = 0.80f;
		m_iAttackRange = 1;
		break;

		case NEntityType::Chugaister:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 3;
		m_fArmor = 0.80f;
		m_iAttackRange = 1;
		break;

		default:
		break;
	}
	return;
}
