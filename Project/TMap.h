#pragma once
#include "SMapElement.h"
#include "IEntity.h"

class TMap : public TObject {
	public:
	TMap()=default;
	virtual ~TMap()=default;

	public:
	void CreateMap(int xCor = 20, int yCor = 30, int zCor = 3, int wCor = 0);  //Creating 100x100x10 defMap
	void SpawnAllUnits();

	protected:
	void SpawnUnit(std::shared_ptr<IEntity>);

	public:
	std::vector<std::shared_ptr<SMapElement>> m_vMapElements;
	std::vector<std::shared_ptr<IEntity>> m_vUnits;

};




