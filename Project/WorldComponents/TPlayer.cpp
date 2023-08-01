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



void TPlayer::RefreshStats() { for(auto& unit : m_vPlayerUnits) { std::dynamic_pointer_cast<TMilitary>(unit.lock())->RecalculateStats(); } }
void TPlayer::CalculateBuildingGold() { for(auto& build : m_vPlayerBuildings) {	i_Gold += build.lock()->AddGold(); } }

int TPlayer::Gold() { return i_Gold; }

std::vector<std::weak_ptr<IEntity>>& TPlayer::Entities() { return m_vPlayerObjects; }

std::vector<std::weak_ptr<TUnit>>& TPlayer::Units() { return m_vPlayerUnits; }

std::vector<std::weak_ptr<TBuildings>>& TPlayer::Buildings() { return m_vPlayerBuildings; }

const NOwner& TPlayer::Type() {	return m_xPlayerPrototype.m_xPlayerType; }
