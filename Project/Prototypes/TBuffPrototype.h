#ifndef TBUFF_PROTOTYPE_H
#define TBUFF_PROTOTYPE_H

#include <WorldComponents/TObject.h>
#include <Enums/NMagicType.h>

class TBuffPrototype : public TObject {
	public:
	TBuffPrototype(NBuffType type = (NBuffType)0 );
	virtual ~TBuffPrototype()=default;
	DECL_REFLECTION_TABLE();

	public:
	NBuffType m_xType;
	float m_fHealthBuff = 0.f;
	float m_fAttackBuff = 0.f;
	float m_fArmorBuff = 0.f;
	int m_iMoveNumbers = 0;
};

#endif //TBUFF_PROTOTYPE_H