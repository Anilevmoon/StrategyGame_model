#include "TBuff.h"

TBuffs::TBuffs(NBuffType type) {
	m_xPrototype = std::make_shared<TBuffPrototype>(type);
}