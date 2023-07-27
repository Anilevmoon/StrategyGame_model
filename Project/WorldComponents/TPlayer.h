#ifndef TPLAYER_H
#define TPLAYER_H


#include  <EntityPart/IEntity.h>



class TPlayer : public TObject {
	public:
	TPlayer(NOwner type) : m_xPlayerType(type){}
	virtual ~TPlayer()=default;

	public:
	std::vector<std::weak_ptr<IEntity>>& Entities();
	const NOwner &Type();

	protected:
	NOwner m_xPlayerType;
	std::vector<std::weak_ptr<IEntity>> m_vPlayerObjects;

	//Have vector with weak_pointers on its units, wich are stored in TMap and created by TEnitityCreator
	//TEnitityCreator should give TPlayer pointers on its objects
};

#endif //TPLAYER_H