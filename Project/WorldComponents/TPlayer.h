#ifndef TPLAYER_H
#define TPLAYER_H

#include <EntityPart/TBuildings.h>
#include <Prototypes/TPlayerPrototype.h>
#include <EntityPart/TUnit.h>


class TPlayer : public TObject {
	public:
	TPlayer(NOwner type = NOwner::PC) : m_xPlayerPrototype(TPlayerPrototype(type)) {}
	virtual ~TPlayer()=default;

	public:
	void SeparateUnitsAndBuildings();

	public:
	void RefreshStats();
	void CalculateBuildingGold();
	int Gold();


	public:
	std::vector<std::weak_ptr<IEntity>>& Entities();
	std::vector<std::weak_ptr<TUnit>>& Units();
	std::vector<std::weak_ptr<TBuildings>>& Buildings();

	public:
	const NOwner& Type();
	TPlayerPrototype m_xPlayerPrototype;

	protected:
//	NOwner m_xPlayerType;
	int i_Gold = 0;
	std::vector<std::weak_ptr<IEntity>> m_vPlayerObjects ={};
	std::vector<std::weak_ptr<TUnit>> m_vPlayerUnits ={};
	std::vector<std::weak_ptr<TBuildings>>m_vPlayerBuildings ={};

	//Have vector with weak_pointers on its units, wich are stored in TMap and created by TEnitityCreator
	//TEnitityCreator should give TPlayer pointers on its objects
};

#endif //TPLAYER_H