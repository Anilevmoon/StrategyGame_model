#ifndef TMILITARY_H
#define TMILITARY_H


#include "TUnit.h"
#include <WorldComponents/TBuff.h>

class TMilitary :public TUnit {
	public:
	TMilitary() = default;
	virtual ~TMilitary()=default;

	public:
	void DestroyEntity() override;

	public:
	void SetEntityPrototype(NEntityType type) override;
	void TakeBuff(std::shared_ptr<TBuffs> buff);

	protected:
	void UseBuff(std::shared_ptr<TBuffs> buff);
	void ConfirmBaffToVector(std::shared_ptr<TBuffs> buff);

	public:
	void RecalculateStats();
	void BuffsNextMove();
 
	public:
	int m_iLevel = 0;
	std::vector<std::shared_ptr<TBuffs>> m_vBuffs;

};

#endif //TMILITARY_H