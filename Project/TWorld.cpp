#include "TWorld.h"

TWorld::TWorld(){
	m_pActiveMap = 	std::make_shared<TMap>();
	m_pCreator = std::make_shared<TStartEntityCreator>();
	m_pPlayer1 = std::make_shared<TPlayer>(NOwner::Player1);
	m_pPlayer2 = std::make_shared<TPlayer>(NOwner::Player2);
	m_pComputer = std::make_shared<TPlayer>(NOwner::PC);
}