#pragma once
#include "TMagic.h"

class TModel : public TObject {
	public:
	TModel();
	virtual ~TModel()=default;
	int	CalculateModel();
	void AddBuff();

	float m_Health;
	float m_Attack;
	int m_AttackRange;
	int m_Speed;
	int m_level;

	std::vector<TMagic*> m_vBuffs;

};

// std::vector<SomeModules*> Moduls;	  //Module Calculating
//Level UP -> Skill UP