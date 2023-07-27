#ifndef TBUFF_H
#define TBUFF_H

#include <memory>

#include <WorldComponents/TObject.h>
#include <Prototypes/TBuffPrototype.h>
#include <Enums/NMagicType.h>

class TBuffs :public TObject {
	public:
	TBuffs(NBuffType type);
	virtual ~TBuffs() = default;

	public:

	std::shared_ptr<TBuffPrototype> m_xPrototype;
};

#endif //TBUFF_H