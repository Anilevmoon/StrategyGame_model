#include "TMilitary.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace NNBaffsType;

void TMilitary::DestroyEntity() {
	m_fActualHealth = 0.f;
}

float TMilitary::getAttack() {
	return m_ActualAttack;
}

void TMilitary::SetUnitPrototype(NNUnitType type) {
	m_pPrototype->SetPrototype(type);
	m_ActualAttack = m_pPrototype->m_Attack;
	m_fActualHealth = m_pPrototype->m_Health;
}

void TMilitary::UseBuff(TMagic* buff) {

	m_fActualHealth = m_fActualHealth+(int)(buff->m_healthBuff*m_pPrototype->m_Health);

	m_ActualAttack = m_ActualAttack+(int)(buff->m_AttackBuff*m_pPrototype->m_Attack);

	if(buff->m_type==NMagicType::DiamondArmor || buff->m_type==NMagicType::ShittyArmor) { m_fActualArmor = buff->m_ArmorBuff; }


	if(m_fActualHealth>m_pPrototype->m_Health) { m_fActualHealth = m_pPrototype->m_Health; }
	if(m_fActualHealth<0) { m_fActualHealth = 0; }												//ДЕСЬ ТУТ ВІДБУВАЄТЬСЯ СМЕРТЬ
}

void TMilitary::ConfirmBaffToVector(TMagic* buff) {
	if(buff->m_MoveNumbers>0) m_vBuffs.push_back(buff);
}

void TMilitary::TakeBuff(TMagic* buff) {
	UseBuff(buff);
	ConfirmBaffToVector(buff);
}

void TMilitary::RecalculateStats() {

	m_pPrototype->m_Attack = m_pPrototype->m_Attack+(m_pPrototype->m_Attack*m_Level*0.1f);
	m_ActualAttack = m_pPrototype->m_Attack;

	m_pPrototype->m_Armor = m_pPrototype->m_Armor+(m_pPrototype->m_Armor*m_Level*0.1f);
	m_fActualArmor = m_pPrototype->m_Armor;


	//лямбду в переменную
	auto boolExpressFunc = [](const auto& buff) { return buff->m_MoveNumbers<=0; };

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
		buffer->m_MoveNumbers--;
	}
	RecalculateStats();
}


