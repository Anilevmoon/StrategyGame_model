#include <CRX/Reflection/TReflectionImplDefs.h>
#include "TUnitPrototype.h"

BEGIN_REFLECTION_TABLE(TUnitPrototype, TObject)
ADD_PROPERTY(Health, m_fHealth);
ADD_PROPERTY(Attack, m_fAttack);
ADD_PROPERTY(Speed, m_iSpeed);
ADD_PROPERTY(Armor, m_fArmor);
ADD_PROPERTY(AttackRange, m_iAttackRange);
ADD_PROPERTY(Type, m_xType);

END_REFLECTION_TABLE();

void TUnitPrototype::SetPrototype(NEntityType type) {
	m_xType = type;

	switch(m_xType) {
		case NEntityType::VillageWarior:
		m_fHealth = 100.f;
		m_fAttack = 20.f;
		m_iSpeed = 3;
		m_fArmor = 0.80f;
		m_iAttackRange = 2;
		break;

		case NEntityType::Kozak:
		m_fHealth = 100.f;
		m_fAttack = 30.f;
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
		m_iAttackRange = 6;
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
