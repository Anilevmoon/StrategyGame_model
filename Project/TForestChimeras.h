#ifndef TFOREST_CHIMERAS_H
#define TFOREST_CHIMERAS_H

#include "TMilitary.h"
class TForestChimeras : public TMilitary {
	public:
	TForestChimeras()= default;
	virtual ~TForestChimeras()=default;

	public:
	void SetEntityPrototype(NEntityType type) override;
	TBuffs* MagicAffectAttack(int skillNumber);

	public:
	std::vector<TBuffs*> m_vAttackMagicSkills;
};

#endif //TFOREST_CHIMERAS_H