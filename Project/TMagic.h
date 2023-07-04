#pragma once
#include "TObject.h"
#include "NNMajicType.h"

class TMagic :public TObject {
	public:
	TMagic(NNBaffsType::NMagicType type);

	public:
	NNBaffsType::NMagicType m_type;
	float m_healthBuff = 0.f;
	float m_AttackBuff = 0.f;
	float m_ArmorBuff = 0.f;
	int m_MoveNumbers = 0;
	// Створення об'єків магічних аттак

};

