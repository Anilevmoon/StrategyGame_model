#pragma once
#include "TMilitary.h"

class TStartEntityCreator {
	public:
	TStartEntityCreator()=default;


	std::vector<std::shared_ptr<IEntity>> CreateStartUnits(const std::vector<std::pair<NNUnitType, NOwner>>& prototypes/*Принимает критерии создания чтото по типу FILE* чи const char*,
	які мають в собі перелік прототипів і з цієї інфи створює юнітів*/);

	/*maybe it should take information with wich Entities to create from gmeProces*///Give to TMap

	std::vector<std::weak_ptr<IEntity>> ChoosePlayerUnitsFromAll(std::vector<std::shared_ptr<IEntity>>);
	/*Should give player Vector with weak_pointers on his units selected from "m_vAllEntities"*/

	protected:
	std::shared_ptr<IEntity> CreateUnitByPrototype(NNUnitType type, NOwner owner);
};

