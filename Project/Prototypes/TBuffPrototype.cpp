#include <CRX/Reflection/TReflectionImplDefs.h>
#include "TBuffPrototype.h"



BEGIN_REFLECTION_TABLE(TBuffPrototype, TObject)

ADD_PROPERTY(HealthBuff, m_fHealthBuff);
ADD_PROPERTY(ArmorBuff, m_fArmorBuff);
ADD_PROPERTY(AttackBuff, m_fAttackBuff);
ADD_PROPERTY(MoveNumbers, m_iMoveNumbers);
ADD_PROPERTY(Type, m_xType);

END_REFLECTION_TABLE();


TBuffPrototype::TBuffPrototype(NBuffType type) : m_xType(type){
	switch(m_xType)	{
		case NBuffType::Hill:
		m_fHealthBuff = 0.3f;
		m_iMoveNumbers = 0;
		break;

		case NBuffType::Regeneration:
		m_fHealthBuff = 0.1f;
		m_iMoveNumbers = 4;
		break;

		case NBuffType::DiamondArmor:
		m_fArmorBuff = 0.001f;
		m_iMoveNumbers = 2;
		break;

		case NBuffType::PowerAttack:
		m_fAttackBuff = 0.50f;
		m_iMoveNumbers = 2;
		break;

		case NBuffType::Poison:
		m_fHealthBuff = -0.08f;
		m_iMoveNumbers = 4;
		break;

		case NBuffType::Weakness:
		m_fAttackBuff = -0.5f;
		m_iMoveNumbers = 2;
		break;

		case NBuffType::ShittyArmor:
		m_fArmorBuff = 0.999f;
		m_iMoveNumbers = 2;
		break;

		default:
		break;
	}
}
