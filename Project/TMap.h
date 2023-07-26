#ifndef TMAP_H
#define TMAP_H

#include "SMapElement.h"
#include <EntityPart/TUnit.h>
#include <Prototypes/TMapPrototype.h>


class TMap : public TObject {
	public:
	TMap()=default;
	virtual ~TMap()=default;

	public:
	void CreateMap(int width = 20, int lenght = 30, int height = 3, int layer = 0);  //Creating 100x100x10 defMap
	void SpawnAllEntity();
	std::shared_ptr<SMapElement> FindLocationOnMap(SMapPoint loc);

	//Need to be tested |--->
	public:
	bool IsCanAttack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> victim);
	bool IsCanMoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation);

	public:
	void Attack(std::shared_ptr<TUnit> attacker, std::shared_ptr<IEntity> victim);
	void MoveTo(std::shared_ptr<TUnit> unit, std::shared_ptr<SMapElement> aimedLocation); 
	//<---|
	public:
	void Summon(std::shared_ptr<IEntity>, SMapPoint point = -1, int rotation = -1);
	void RemoveFromMap(std::shared_ptr<IEntity>);

	protected:
	void SpawnEntity(std::shared_ptr<IEntity> entity);
	int DistanceBetweenPoints(SMapPoint, SMapPoint);

	public:
	std::vector<std::shared_ptr<SMapElement>> m_vMapElements;
	std::vector<std::shared_ptr<TUnit>> m_vUnits;
	std::vector<std::shared_ptr<IEntity>> Buildings;

	public:
	std::shared_ptr<TMapPrototype> m_xPrototype;
};

#endif //TMAP_H