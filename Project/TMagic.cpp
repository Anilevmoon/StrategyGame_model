#include "TMagic.h"

TMagic::TMagic(NNBaffsType::NMagicType type) : m_type(type) {
	switch(m_type)
	{
		case NNBaffsType::Hill:
		m_healthBuff = 0.3f;
		m_MoveNumbers = 0;
		break;

		case NNBaffsType::Regeneration:
		m_healthBuff = 0.1f;
		m_MoveNumbers = 4;
		break;

		case NNBaffsType::DiamondArmor:
		m_ArmorBuff = 0.001f;
		m_MoveNumbers = 2;
		break;

		case NNBaffsType::PowerAttack:
		m_AttackBuff = 5.0f;
		m_MoveNumbers = 2;
		break;

		case NNBaffsType::Poison:
		m_healthBuff = -0.08f;
		m_MoveNumbers = 4;
		break;

		case NNBaffsType::Weakness:
		m_AttackBuff = -0.5f;
		m_MoveNumbers = 2;
		break;

		case NNBaffsType::ShittyArmor:
		m_ArmorBuff = 0.999f;
		m_MoveNumbers = 2;
		break;

		default:
		break;
	}
}
