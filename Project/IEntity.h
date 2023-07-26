#ifndef IENTITY_H
#define IENTITY_H

#include <WorldWideComp/TObject.h>
#include <MapParts/SMapElement.h>
#include <Enums/NOwner.h>
#include <Enums/NEntityType.h>

class IEntity :public TObject {
	public:
	virtual void DestroyEntity()=0;

	virtual void SetCoordinates(SMapPoint)=0;
	public:
	virtual void ApplyDamage(float damage) = 0;
	virtual void SetEntityPrototype(NEntityType type)=0;
	virtual void ChangeOwner(NOwner own) = 0;
	virtual void SetRotation(int rotation) = 0;


	public:
	virtual NOwner& Owner() = 0;
	virtual float Health() = 0;
	virtual int Rotation() = 0;

	public:
	SMapPoint m_xLocation;
	static int s_iID;

	protected:
	int m_iRotaotion = 0;
	float m_fDynamicHealth = 0.f;
	NOwner m_xOwner;
};

#endif // IENTITY_H