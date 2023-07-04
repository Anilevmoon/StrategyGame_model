#include "TWorld.h"

TWorld::TWorld(){
	m_pActiveMap = new TMap;
	m_creator = new TStartEntityCreator;

}

void TWorld::InsertEntitiesOnMap() {
																			//Тут чи спавнити на мапі			
}

std::vector<std::weak_ptr<IEntity>> TWorld::ExtractPlayerUnits() {
																				//витягувати тут чи на мапі
	return std::vector<std::weak_ptr<IEntity>>();
}
