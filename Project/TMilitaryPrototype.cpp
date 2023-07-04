#include "TMilitaryPrototype.h"

void TMilitaryPrototype::SetPrototype(NNUnitType type) {
	switch(type)
	{
		case NNUnitType::VillageWarior:
		m_Health = 100.f;
		m_Attack = 20.f;
		m_Speed = 3;
		m_Armor = 0.80f;
		m_AttackRange = 1;
		break;

		case NNUnitType::Kozak:
		m_Health = 100.f;
		m_Attack = 20.f;
		m_Speed = 3;
		m_Armor = 0.80f;
		m_AttackRange = 1;
		break;

		case NNUnitType::PigRider:
		m_Health = 100.f;
		m_Attack = 20.f;
		m_Speed = 3;
		m_Armor = 0.80f;
		m_AttackRange = 1;
		break;

		case NNUnitType::Tarain:
		m_Health = 100.f;
		m_Attack = 20.f;
		m_Speed = 3;
		m_Armor = 0.80f;
		m_AttackRange = 1;
		break;

		case NNUnitType::Rogatchyky:
		m_Health = 100.f;
		m_Attack = 20.f;
		m_Speed = 3;
		m_Armor = 0.80f;
		m_AttackRange = 1;
		break;

		case NNUnitType::SichShoters:
		m_Health = 100.f;
		m_Attack = 20.f;
		m_Speed = 3;
		m_Armor = 0.80f;
		m_AttackRange = 1;
		break;

		case NNUnitType::Catapulta:
		m_Health = 100.f;
		m_Attack = 20.f;
		m_Speed = 3;
		m_Armor = 0.80f;
		m_AttackRange = 1;
		break;

		case NNUnitType::ForestMavka:
		m_Health = 100.f;
		m_Attack = 20.f;
		m_Speed = 3;
		m_Armor = 0.80f;
		m_AttackRange = 1;
		break;

		case NNUnitType::Chugaister:
		m_Health = 100.f;
		m_Attack = 20.f;
		m_Speed = 3;
		m_Armor = 0.80f;
		m_AttackRange = 1;
		break;

		default:
		break;
	}
	return;
}
