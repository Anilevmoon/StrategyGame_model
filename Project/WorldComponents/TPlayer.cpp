#include "TPlayer.h"

std::vector<std::weak_ptr<IEntity>>& TPlayer::Entities() { return m_vPlayerObjects; }

const NOwner& TPlayer::Type() {	return m_xPlayerType; }
