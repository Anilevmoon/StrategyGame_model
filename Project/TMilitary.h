#pragma once
#include "TUnit.h"
#include "TMagic.h"

class TMilitary :public TUnit {
	public:
	TMilitary() = default;
	virtual ~TMilitary()=default;

	public:
	void DestroyEntity() override;

	public:
	void SetUnitPrototype(NNUnitType type) override;
	void TakeBuff(TMagic* buff);

	protected:
	void UseBuff(TMagic* buff);
	void ConfirmBaffToVector(TMagic* buff);

	public:
	void RecalculateStats();
	void BuffsNextMove();

	//Model+Prot
	public:
	float getAttack();
	int m_Level = 0;
	float m_ActualAttack = 0.f;

	//TModel* m_model;	

	std::vector<TMagic*> m_vBuffs;

};