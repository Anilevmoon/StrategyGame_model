#include "TUnit.h"

TUnit::TUnit(NOwner owner) {
	m_pPrototype = new TMilitaryPrototype();
	if(owner==NOwner::PC) {
		m_location.x = 0;
		m_location.y = 0;
		m_location.z = 0;
		m_location.w = 0;
	}
}

void TUnit::DestroyEntity() {
	m_fActualHealth = 0;
}

void TUnit::SetUnitPrototype(NNUnitType type) {
	m_pPrototype->SetPrototype(type);
	m_fActualHealth = m_pPrototype->m_Health;
}

float TUnit::getHealth() {
	return 	m_fActualHealth;

}
