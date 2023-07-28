#ifndef TMAP_H
#define TMAP_H

#include "SMapElement.h"
#include <EntityPart/TUnit.h>
#include <Prototypes/TMapPrototype.h>
#include <Algorithm/TPathFinder.h>

static int s_iWidth = 20;
static int s_iLenght = 30;
static int s_iHeight = 3;
static int s_iLayer = 0;

class TMap : public TObject {
	public:
	TMap()=default;
	virtual ~TMap()=default;

	public:
	void CreateMap(int width = s_iWidth, int lenght = s_iLenght, int height = s_iHeight, int layer = s_iLayer);  //Creating 100x100x10 defMap
	void SpawnAllEntity();
	std::shared_ptr<SMapElement> FindLocationOnMap(SMapPoint loc);
	void RefreshGridForOwner(NOwner owner);

	//Need to be tested |--->
	public:
	bool IsCanAttack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> target);
	bool IsCanMoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation);

	public:
	void Attack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> target);
	void MoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation);
	//<---|
	public:
	void Summon(std::shared_ptr<IEntity>, SMapPoint point = TAlgorithms::SGridUtility::InvalidPoint, int rotation = -1);
	void Remove(std::shared_ptr<IEntity>);
	void SpawnEntity(std::shared_ptr<IEntity> entity);

	protected:
	int DistanceBetweenPoints(SMapPoint, SMapPoint);

	public:
	std::vector<std::shared_ptr<SMapElement>> m_vMapElements;
	std::vector<std::vector<int>> m_vvGrid;
	std::vector<std::shared_ptr<TUnit>> m_vUnits;
	std::vector<std::shared_ptr<IEntity>> m_vBuildings;
	std::shared_ptr<TPathFinder> m_oPathFinder = std::make_shared<TPathFinder>();

	public:
	std::shared_ptr<TMapPrototype> m_xPrototype;

	protected:
	int m_iWidth =  s_iWidth;
	int m_iLenght = s_iLenght;
	int m_iHeight = s_iHeight;
	int m_iLayer = s_iLayer;

	protected:
	SMapPoint m_xMaxCoordinate;
};

#endif //TMAP_H