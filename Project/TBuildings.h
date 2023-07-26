#ifndef TBUILDINGS_H
#define TBUILDINGS_H

#include "IEntity.h"
#include <Prototypes/TBuildingsPrototype.h>

class TBuildings :public IEntity {
	public:
	TBuildings();
	void SetCoordinates(SMapPoint) override;
	virtual void SetEntityPrototype(NEntityType type) override;
	void SetRotation(int rotation) override;

	public:
	NOwner& Owner() override;
	void ChangeOwner(NOwner own) override;
	int Rotation() override;
	void DestroyEntity();
	void ApplyDamage(float damage) override;



	virtual ~TBuildings() {}

	float Health();

	public:
	std::shared_ptr<TBuildingsPrototype> m_pPrototype = nullptr;
	int ID = 1;
};

#endif