#include "TMap.h"

void TMap::CreateMap(/*int width = s_iWidth, int lenght = s_iLenght, int height = s_iHeight, int layer = s_iLayer*/NMapType maptype) {

	m_xPrototype = std::make_shared<TMapPrototype>(maptype);


	m_iWidth = m_xPrototype->m_iWidth;
	m_iLenght = m_xPrototype->m_iLenght;
	m_iHeight = m_xPrototype->m_iHeight;
	m_iLayer = m_xPrototype->m_iLayer;

	m_xMaxCoordinate = SMapPoint(m_iWidth, m_iLenght, m_iHeight, m_iLayer);
	for(auto i = 0; i < m_iWidth; ++i) {
		for(int it = 0; it < m_iLenght; it++) {
			for(int itr = 0; itr < m_iHeight; itr++) {
				auto element = std::make_shared<SMapElement>();
				element->SetLocation(it, i, itr);
				m_vMapElements.push_back(element);
			}
		}
	}
	m_vvGrid = TAlgorithms::SGridUtility::CreateGrid(m_iWidth, m_iLenght, 1);
}

void TMap::SpawnAllEntity() {
	for(auto& currentUnit : m_vUnits) SpawnEntity(currentUnit);
	for(auto CurrentBuild : m_vBuildings) SpawnEntity(CurrentBuild);
}

std::shared_ptr<SMapElement> TMap::FindLocationOnMap(SMapPoint loc) {
	for(auto& element : m_vMapElements) { if(element->Location() == loc) return element; }
	return nullptr;
}

void TMap::RefreshGridForOwner(NOwner owner) {
	for(auto& build : m_vBuildings) {
		if(owner != build->Owner()) {
			m_vvGrid[build->m_xLocation.x][build->m_xLocation.x] = 0;
		}
	}
}

bool TMap::IsCanAttack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> target) {
	auto distance = DistanceBetweenPoints(attacker->m_xLocation, target->m_xLocation);
	if(distance < attacker->m_pPrototype->m_iAttackRange && attacker->Owner() != target->Owner()) return true;
	return false;
}

bool TMap::IsCanMoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation) {
	auto distance = DistanceBetweenPoints(unit->m_xLocation, aimedLocation->Location());
	return (distance < unit->m_pPrototype->m_iSpeed && aimedLocation->Location() < m_xMaxCoordinate && aimedLocation != nullptr ? true : false);
}

void TMap::Attack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> target) {
	target->ApplyDamage(attacker->GetAttack());
}

void TMap::MoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation) {
	Remove(unit);
	unit->SetCoordinates(aimedLocation->Location());
	SpawnEntity(unit);

	//This function changes grip according to owner BUT we need it here for tests and one-PC-game
	//If there is a multiplayer it would be called with Player.m_xType;
	RefreshGridForOwner(unit->Owner());

	auto unitPath = m_oPathFinder->FindPathTo(m_vvGrid, unit->m_xLocation, aimedLocation->Location());
	for(auto& step : unitPath) {
		Remove(unit);
		unit->SetCoordinates(step);
		//Here some function with animation etc...
		SpawnEntity(unit);
	}
}


void TMap::Summon(std::shared_ptr<IEntity> entity, SMapPoint point, int rotation) {
	if(point.x > -1) entity->SetCoordinates(point);	//later can be replaced with nullptr
	if(rotation != -1) entity->SetRotation(rotation);
	SpawnEntity(entity);
}

void TMap::Remove(std::shared_ptr<IEntity> entity) {
	auto& objectsInMapElement = FindLocationOnMap(entity->m_xLocation)->m_vObjects;
	auto isEqual = [&entity](std::shared_ptr<IEntity> a) { return a == entity; };
	objectsInMapElement.erase(std::remove_if(objectsInMapElement.begin(), objectsInMapElement.end(), isEqual), objectsInMapElement.end());
	return;
}

void TMap::SpawnEntity(std::shared_ptr<IEntity> entity) {
	auto counter = 0;
	while(entity->m_xLocation != m_vMapElements[counter]->Location()) { counter++; }
	m_vMapElements[counter]->m_vObjects.push_back(entity);
}

void TMap::SetPrototype(std::shared_ptr<TMapPrototype> prot) { m_xPrototype = prot; }

int TMap::DistanceBetweenPoints(SMapPoint first, SMapPoint second) {
	auto subtraction = first - second;
	return (int) sqrt((pow(subtraction.x, 2)) + (pow(subtraction.y, 2)) + (pow(subtraction.z, 2)) + (pow(subtraction.w, 2)));
}

