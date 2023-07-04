#pragma once
#include "TObject.h"
#include "SMapPoint.h"
#include "NOwner.h"

class IEntity :public TObject {
	public:

	virtual void DestroyEntity() = 0;

	SMapPoint m_location;
	static int ID;
	NOwner m_owner;
};

