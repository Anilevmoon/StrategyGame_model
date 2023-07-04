#pragma once
#include "IEntity.h"



class TPlayer : public TObject {
	public:
	TPlayer() {}
	virtual ~TPlayer()=default;

	public:
	NOwner m_xType = NOwner::PC;
	std::vector<std::weak_ptr<IEntity>> m_vPlayerObjects;

	//Have vector with weak_pointers on its units, wich are stored in TMap and created by TEnitityCreator
	//TEnitityCreator should give TPlayer pointers on its objects
};

