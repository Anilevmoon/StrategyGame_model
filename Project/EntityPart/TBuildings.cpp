#include "TBuildings.h"

static int i_DefaultAddedGoldFromBuiling = 30;

TBuildings::~TBuildings() {}
void TBuildings::SetCoordinates(SMapPoint coordinate) { m_xLocation = coordinate; }
void TBuildings::DestroyEntity() { m_pPrototype->m_fHealth = 0; }

void TBuildings::SetMap(std::shared_ptr<TMap> map) { p_CurrentMap = map; }
float TBuildings::Health() { return m_fDynamicHealth; }

void TBuildings::ApplyDamage(float damage) { m_fDynamicHealth -= damage; }
void TBuildings::AcquireUnit(NEntityType prototype) { p_CreatorPrototype->CreateUnit(prototype, m_xOwner, m_xLocation, p_CurrentMap); }

int TBuildings::AddGold() { return i_GoldFromBuilding+=i_DefaultAddedGoldFromBuiling; }

NOwner& TBuildings::Owner() { return m_xOwner; }
void TBuildings::ChangeOwner(NOwner own) { m_xOwner = own; }

void TBuildings::SetRotation(int rotation) { m_iRotaotion = rotation; }
int TBuildings::Rotation() { return m_iRotaotion; }

void TBuildings::SetEntityPrototype(NEntityType type) {
	m_pPrototype->SetBuildingsPrototype(type);
	m_fDynamicHealth = m_pPrototype->m_fHealth;
	if(type == NEntityType::CossacksHouse) p_CreatorPrototype = std::make_shared<TBuildUnitCreatorPrototype>();
}

TBuildings::TBuildings() {
	++ID;
	m_pPrototype=std::make_shared<TBuildingsPrototype>();
}

NBuildingState TBuildings::State() {
	if(m_fDynamicHealth / m_pPrototype->m_fHealth > 0.75 ) return NBuildingState::Full;
	else if(m_fDynamicHealth <= 0) {
		DestroyEntity();
		return NBuildingState::Destroyed;
	}
	else {
		return NBuildingState::Half;
	}
	
}