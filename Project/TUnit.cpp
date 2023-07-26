#include "TUnit.h"

TUnit::TUnit() {
	m_pPrototype = std::make_shared<TUnitPrototype>();
}

void TUnit::DestroyEntity() {
	m_fDynamicHealth = 0;
}

void TUnit::SetEntityPrototype(NEntityType type) {
	m_pPrototype->SetPrototype(type);
	m_fDynamicHealth = m_pPrototype->m_fHealth;
}

NOwner& TUnit::Owner() { return m_xOwner; }
float TUnit::Health() { return 	m_fDynamicHealth; }
int TUnit::Rotation() {	return m_iRotaotion; }
float TUnit::Armor() { return m_fDynamicArmor; }
float TUnit::GetAttack() { return m_xDynamicAttack; }
void TUnit::ChangeOwner(NOwner own) { m_xOwner = own; }

void TUnit::ApplyDamage(float damage) { m_fDynamicHealth+=damage; }

void TUnit::SetCoordinates(SMapPoint coordinates) {	m_xLocation = coordinates; }

void TUnit::SetRotation(int rotation) { m_iRotaotion = rotation; }
