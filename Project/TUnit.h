#pragma once
#include "IEntity.h"
#include "TMilitaryPrototype.h"

enum class  NNUnitType;

class TUnit : public IEntity {
	public:
	TUnit(NOwner owner = NOwner::PC);
	virtual ~TUnit()=default;

	public:
	void DestroyEntity() override;

	public:
	virtual void SetUnitPrototype(NNUnitType type);
	float getHealth();

	public:
	float m_fActualHealth = 0.f;
	float m_fActualArmor = 0.5f;
	TMilitaryPrototype* m_pPrototype = nullptr;
};

