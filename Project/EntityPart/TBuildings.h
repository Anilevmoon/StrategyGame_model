#ifndef TBUILDINGS_H
#define TBUILDINGS_H

#include <Prototypes/TBuildingsPrototype.h>
#include <Prototypes/TBuildUnitCreatorPrototype.h>
#include <Enums/NBuildingState.h>
#include <Enums/NOwner.h>
#include <MapParts/TMap.h>

class TBuildings :public IEntity {
	public:
	TBuildings();
	~TBuildings();

	public:
	void SetCoordinates(SMapPoint) override;
	virtual void SetEntityPrototype(NEntityType type) override;
	void SetRotation(int rotation) override;

	public:
	NOwner& Owner() override;
	void ChangeOwner(NOwner own) override;
	
	public:
	int Rotation() override;
	void DestroyEntity();

	public:
	void ApplyDamage(float damage) override;
	void SetMap(std::shared_ptr<TMap> map);

	public:
	NBuildingState State(); 
	float Health();

	public:
	void AcquireUnit(NEntityType prototype);
	
	public:
	std::shared_ptr<TBuildingsPrototype> m_pPrototype = nullptr; 
	std::shared_ptr<TBuildUnitCreatorPrototype> p_CreatorPrototype = nullptr; 
	std::weak_ptr<TMap> p_CurrentMap;
	int ID = 1;
	
};

#endif