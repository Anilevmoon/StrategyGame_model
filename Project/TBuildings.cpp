#include "TBuildings.h"

void TBuildings::SetEntityPrototype(NEntityType type) {
	m_pPrototype->SetBuildingsPrototype(type);
}

void TBuildings::SetRotation(int rotation) { m_iRotaotion = rotation; }

void TBuildings::DestroyEntity() {
	m_pPrototype->m_fHealth=0;
	m_pPrototype->m_vBuildPoints.clear();
}

void TBuildings::ApplyDamage(float damage) { m_fDynamicHealth+=damage; }

float TBuildings::Health() { return m_fDynamicHealth; }
int TBuildings::Rotation() { return m_iRotaotion; }


TBuildings::TBuildings() {
	++ID;
	m_pPrototype=std::make_shared<TBuildingsPrototype>();
}

void TBuildings::SetCoordinates(SMapPoint coordinates) { m_xLocation = coordinates; }

NOwner& TBuildings::Owner() { return m_xOwner; }

void TBuildings::ChangeOwner(NOwner own) {
	m_xOwner = own;
}