#ifndef TWORLD_H
#define TWORLD_H


#include <MapParts/TMap.h>
#include "TPlayer.h"
#include "TStartEntityCreator.h"
#include <Prototypes/TWorldPrototype.h>

class TWorld : public TObject {
	public:
	TWorld(/*TPlayer* player1, std::vector<TMap*> maps, std::vector<IEntity*> AllEntities*/); //
	virtual ~TWorld()=default;

	public:
	std::shared_ptr<TPlayer> m_pPlayer1;	//Плеери з шаблонами щоб розподіляти юніти між ними
	std::shared_ptr<TPlayer> m_pPlayer2;
	std::shared_ptr<TPlayer> m_pComputer;
	std::shared_ptr<TStartEntityCreator> m_pCreator;

	public:
	std::shared_ptr<TWorldPrototype> m_xPrototype;

	public:
	std::shared_ptr<TMap> m_pActiveMap = nullptr;			//створити шаблони карт
	std::vector<std::shared_ptr<TMap>> m_vMaps;				//Чому массив і як тоді контролювати і де створювати юнітів якщо вони лежать у мапі?

};

#endif //TWORLD_H