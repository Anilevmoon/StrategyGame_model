#ifndef TMILITARY_H
#define TMILITARY_H


#include "TUnit.h"
#include <WorldWideComp/TBuff.h>

class TMilitary :public TUnit {
	public:
	TMilitary() = default;
	virtual ~TMilitary()=default;

	public:
	void DestroyEntity() override;

	public:
	void SetEntityPrototype(NEntityType type) override;
	void TakeBuff(TBuffs* buff);

	protected:
	void UseBuff(TBuffs* buff);
	void ConfirmBaffToVector(TBuffs* buff);

	public:
	void RecalculateStats();
	void BuffsNextMove();
 
	public:
	int m_iLevel = 0;
	std::vector<TBuffs*> m_vBuffs;

};

#endif //TMILITARY_H