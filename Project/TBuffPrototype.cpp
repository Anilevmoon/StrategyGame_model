#include "TBuffPrototype.h"

TBuffPrototype::TBuffPrototype(NBuffType type) : m_xType(type){
	switch(m_xType)
	{
		case NNBuffType::Hill:
		m_fHealthBuff = 0.3f;
		m_iMoveNumbers = 0;
		break;

		case NNBuffType::Regeneration:
		m_fHealthBuff = 0.1f;
		m_iMoveNumbers = 4;
		break;

		case NNBuffType::DiamondArmor:
		m_fArmorBuff = 0.001f;
		m_iMoveNumbers = 2;
		break;

		case NNBuffType::PowerAttack:
		m_fAttackBuff = 0.50f;
		m_iMoveNumbers = 2;
		break;

		case NNBuffType::Poison:
		m_fHealthBuff = -0.08f;
		m_iMoveNumbers = 4;
		break;

		case NNBuffType::Weakness:
		m_fAttackBuff = -0.5f;
		m_iMoveNumbers = 2;
		break;

		case NNBuffType::ShittyArmor:
		m_fArmorBuff = 0.999f;
		m_iMoveNumbers = 2;
		break;

		default:
		break;
	}
}
