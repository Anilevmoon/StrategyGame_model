#include "TMap.h"

void TMap::CreateMap(int width, int lenght, int height, int layer) {
	for(auto i = 0; i<lenght; ++i) {
		for(int it = 0; it<width; it++) {
			for(int itr = 0; itr<height; itr++) {

				auto element = std::make_shared<SMapElement>();
				element->SetLocation(it, i, itr);
				m_vMapElements.push_back(element);

			}
		}
	}
}

void TMap::SpawnAllEntity() {
	for(auto currentUnit:m_vUnits) Summon(currentUnit);
}

std::shared_ptr<SMapElement> TMap::FindLocationOnMap(SMapPoint loc) {
	for(auto element:m_vMapElements) { if(element->Location()==loc) return element; }
	return nullptr;
}

bool TMap::IsCanAttack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> victim) { 
	auto distance = DistanceBetweenPoints(attacker->m_xLocation, victim->m_xLocation);
	if(distance<attacker->m_pPrototype->m_iAttackRange) { return true; }
	return false;
}

bool TMap::IsCanMoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation) { 
	auto distance = DistanceBetweenPoints(unit->m_xLocation, aimedLocation->Location());
	if(distance<unit->m_pPrototype->m_iSpeed) { return true; }
	return false;
}

void TMap::Attack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> victim) {
	victim->ApplyDamage( attacker->GetAttack() );
}

void TMap::MoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation) {
	unit->SetCoordinates(aimedLocation->Location());
}


void TMap::Summon(std::shared_ptr<IEntity> entity, SMapPoint point, int rotation) {
	if(point!=-1) entity->SetCoordinates(point);
	if(rotation!=-1) entity->SetRotation(rotation); 
	SpawnEntity(entity);
}

void TMap::RemoveFromMap(std::shared_ptr<IEntity> entity) {
	auto& objectsInMapElement = FindLocationOnMap(entity->m_xLocation)->m_vObjects;
	auto isEqual = [&entity](std::shared_ptr<IEntity> a) { return a == entity; };

	objectsInMapElement.erase(std::remove_if(objectsInMapElement.begin(), objectsInMapElement.end(), isEqual), objectsInMapElement.end());
	return;
}

void TMap::SpawnEntity(std::shared_ptr<IEntity> entity) {
	auto counter = 0; 
	while(entity->m_xLocation!=m_vMapElements[counter]->Location()) { counter++; }
	m_vMapElements[counter]->m_vObjects.push_back(entity);
}

int TMap::DistanceBetweenPoints(SMapPoint first,SMapPoint second) {
	auto subtraction = first-second;
	return (int)sqrt((pow(subtraction.x, 2))+(pow(subtraction.y, 2))+(pow(subtraction.z, 2))+(pow(subtraction.w, 2)));
}

