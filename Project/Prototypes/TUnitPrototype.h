#ifndef TUNIT_PROTOTYPE_H
#define TUNIT_PROTOTYPE_H

#include <Enums/NEntityType.h>  
#include <Enums/NOwner.h>
#include <Prototypes/TBuffPrototype.h>

class TUnitPrototype :public TObject {
	public:
	TUnitPrototype()=default;
	virtual ~TUnitPrototype() = default;

	public:
	void SetPrototype(NEntityType type);

	public:
	NEntityType m_xType;
	float m_fHealth = 0.f;
	float m_fAttack = 0.f;
	int m_iAttackRange = 0;
	int m_iSpeed = 0;
	float m_fArmor = 0.f;

	public:
	std::vector<std::shared_ptr<TBuffPrototype>> m_vBuffPrototypesContainer;
};

#endif //TUNIT_PROTOTYPE_H