#pragma once
#include "TObject.h"
#include "NTUnitTypes.h"  
#include "NOwner.h"

class TMilitaryPrototype :public TObject {
	public:
	TMilitaryPrototype() : m_Health(0) {}
	virtual ~TMilitaryPrototype() = default;
	void SetPrototype(NNUnitType type);

	float m_Health;
	float m_Attack = 0.f;
	int m_AttackRange = 0;
	int m_Speed = 0;
	float m_Armor = 0.f;

	//Ask where to take
};