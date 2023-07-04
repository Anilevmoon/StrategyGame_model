#pragma once
#include "TMap.h"
#include "TPlayer.h"
#include "TStartEntityCreator.h"

class TWorld : public TObject {
	public:
	TWorld(/*TPlayer* player1, std::vector<TMap*> maps, std::vector<IEntity*> AllEntities*/); //
	virtual ~TWorld()=default;

	public:
	void InsertEntitiesOnMap();
	std::vector<std::weak_ptr<IEntity>> ExtractPlayerUnits();

	public:
	TPlayer* m_pPlayer1;	//Плеери з шаблонами щоб розподіляти юніти між ними
	TPlayer* m_pPlayer2;
	TPlayer* m_pComputer;
	TStartEntityCreator* m_creator;

	public:
	TMap* m_pActiveMap = nullptr;		//SharedPointer					//створити шаблони карт
	std::vector<TMap*> m_vMaps;				//Чому массив і як тоді контролювати і де створювати юнітів якщо вони лежать у мапі?

};

