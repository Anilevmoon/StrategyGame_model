#include "TMilitary.h"
#include <algorithm>
#include <vector>
#include <iostream>

void TMilitary::DestroyEntity() { m_fDynamicHealth = 0.f; }

void TMilitary::SetEntityPrototype(NEntityType type) {
	m_pPrototype->SetPrototype(type);
	m_xDynamicAttack = m_pPrototype->m_fAttack;
	m_fDynamicHealth = m_pPrototype->m_fHealth;
}

void TMilitary::UseBuff(std::shared_ptr<TBuffs> buff) {

	m_fDynamicHealth = m_fDynamicHealth+(int)(buff->m_xPrototype->m_fHealthBuff*m_pPrototype->m_fHealth);
	m_xDynamicAttack = m_xDynamicAttack+(int)(buff->m_xPrototype->m_fAttackBuff*m_pPrototype->m_fAttack);

	if(buff->m_xPrototype->m_xType==NBuffType::DiamondArmor||buff->m_xPrototype->m_xType==NBuffType::ShittyArmor) { m_fDynamicArmor = buff->m_xPrototype->m_fArmorBuff; }


	if(m_fDynamicHealth>m_pPrototype->m_fHealth) { m_fDynamicHealth = m_pPrototype->m_fHealth; }
	if(m_fDynamicHealth<0) { m_fDynamicHealth = 0; }
}

void TMilitary::ConfirmBaffToVector(std::shared_ptr<TBuffs> buff) {	if(buff->m_xPrototype->m_iMoveNumbers>0) m_vBuffs.push_back(buff); }

void TMilitary::TakeBuff(std::shared_ptr<TBuffs> buff) {
	UseBuff(buff);
	ConfirmBaffToVector(buff);
}

void TMilitary::RecalculateStats() {

	m_pPrototype->m_fAttack = m_pPrototype->m_fAttack+(m_pPrototype->m_fAttack*m_iLevel*0.1f);
	m_xDynamicAttack = m_pPrototype->m_fAttack;

	m_pPrototype->m_fArmor = m_pPrototype->m_fArmor+(m_pPrototype->m_fArmor*m_iLevel*0.1f);
	m_fDynamicArmor = m_pPrototype->m_fArmor;


	auto boolExpressFunc = [](const auto& buff) { return buff->m_xPrototype->m_iMoveNumbers<=0; };

	m_vBuffs.erase(std::remove_if(m_vBuffs.begin(), m_vBuffs.end(), boolExpressFunc), m_vBuffs.end());


	auto iter = m_vBuffs.begin();

	while(iter!=m_vBuffs.end()) {

		auto valueIter = *iter;
		UseBuff(valueIter);
		iter++;
	}

}

void TMilitary::BuffsNextMove() {
	for(auto buffer:m_vBuffs) {
		buffer->m_xPrototype->m_iMoveNumbers--;
	}
	RecalculateStats();
}


