#include "TMap.h"

void TMap::CreateMap(int width, int lenght, int height, int layer) {
	m_iWidth = width;
	m_iLenght = lenght;
	m_iHeight = height;
	m_iLayer = layer;

	m_xMaxCoordinate = SMapPoint(m_iWidth, m_iLenght, m_iHeight, m_iLayer);
	for(auto i = 0; i<lenght; ++i) {
		for(int it = 0; it<width; it++) {
			for(int itr = 0; itr<height; itr++) {
				auto element = std::make_shared<SMapElement>();
				element->SetLocation(it, i, itr);
				m_vMapElements.push_back(element);
			}
		}
	}
	SetUpGird();
}

void TMap::SpawnAllEntity() { for(auto& currentUnit:m_vUnits) Summon(currentUnit); }

std::shared_ptr<SMapElement> TMap::FindLocationOnMap(SMapPoint loc) {
	for(auto& element:m_vMapElements) { if(element->Location()==loc) return element; }
	return nullptr;
}

void TMap::SetUpGird() {
	for(auto i = 0; i<m_iLenght; ++i) {
		std::vector<int> v2;
		for(int it = 0; it<m_iWidth; ++it) { v2.push_back(1); }
		m_vvGrid.push_back(v2);
	}
}

void TMap::RefreshGridFor(NOwner owner) {
	for(auto& build:m_vBuildings) {
		if(owner!=build->Owner()) {
			m_vvGrid[build->m_xLocation.x][build->m_xLocation.x] = 0;
		}
	}
}

bool TMap::IsCanAttack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> target) {
	auto distance = DistanceBetweenPoints(attacker->m_xLocation, target->m_xLocation);
	if(distance<attacker->m_pPrototype->m_iAttackRange&&attacker->Owner()!=target->Owner()) return true;
	return false;
}

bool TMap::IsCanMoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation) {
	auto distance = DistanceBetweenPoints(unit->m_xLocation, aimedLocation->Location());
	return (distance<unit->m_pPrototype->m_iSpeed&&aimedLocation->Location()<m_xMaxCoordinate&&aimedLocation!=nullptr ? true : false);
}

void TMap::Attack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> target) {
	target->ApplyDamage(attacker->GetAttack());
}

void TMap::MoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation) {
	RefreshGridFor(unit->Owner());
	auto unitPath = m_oPathFinder->FindPathTo(m_vvGrid, unit->m_xLocation, aimedLocation->Location());
	for(auto& step:unitPath) {
		Remove(unit);
		unit->SetCoordinates(step);
			//Here some function with animation etc...
		SpawnEntity(unit);
	}
}


void TMap::Summon(std::shared_ptr<IEntity> entity, SMapPoint point, int rotation) {
	if(point.x>-1) entity->SetCoordinates(point);	//later can be replaced with nullptr
	if(rotation!=-1) entity->SetRotation(rotation);
	SpawnEntity(entity);
}

void TMap::Remove(std::shared_ptr<IEntity> entity) {
	auto& objectsInMapElement = FindLocationOnMap(entity->m_xLocation)->m_vObjects;
	auto isEqual = [&entity](std::shared_ptr<IEntity> a) { return a==entity; };
	objectsInMapElement.erase(std::remove_if(objectsInMapElement.begin(), objectsInMapElement.end(), isEqual), objectsInMapElement.end());
	return;
}

void TMap::SpawnEntity(std::shared_ptr<IEntity> entity) {
	auto counter = 0;
	while(entity->m_xLocation!=m_vMapElements[counter]->Location()) { counter++; }
	m_vMapElements[counter]->m_vObjects.push_back(entity);
}

int TMap::DistanceBetweenPoints(SMapPoint first, SMapPoint second) {
	auto subtraction = first-second;
	return (int)sqrt((pow(subtraction.x, 2))+(pow(subtraction.y, 2))+(pow(subtraction.z, 2))+(pow(subtraction.w, 2)));
}

