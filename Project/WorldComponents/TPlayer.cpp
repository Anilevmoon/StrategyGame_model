#include "TPlayer.h"


void TPlayer::SeparateUnitsAndBuildings() {
	for(auto member:m_vPlayerObjects) {
		if(member.lock()->m_xMemberType==NEntityType::Coliba||member.lock()->m_xMemberType==NEntityType::CossacksHouse||member.lock()->m_xMemberType==NEntityType::Mazanka) {
			m_vPlayerBuildings.push_back(std::dynamic_pointer_cast<TBuildings>(member.lock()));
		} else {
			m_vPlayerUnits.push_back(std::dynamic_pointer_cast<TUnit>(member.lock()));
		}
	}
}

std::vector<std::weak_ptr<IEntity>>& TPlayer::Entities() { return m_vPlayerObjects; }

std::vector<std::weak_ptr<TUnit>>& TPlayer::Units() { return m_vPlayerUnits; }

std::vector<std::weak_ptr<TBuildings>>& TPlayer::Buildings() { return m_vPlayerBuildings; }

const NOwner& TPlayer::Type() {	return m_xPlayerType; }
