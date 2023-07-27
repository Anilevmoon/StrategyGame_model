#ifndef TLIGHTSTATICRANDOM_H_
#define TLIGHTSTATICRANDOM_H_


#include <CRX/Base/TStaticRandom.h>

class TLightStaticRandom : public crx::TStaticRandom {
	public:
	TLightStaticRandom() = default;
	virtual ~TLightStaticRandom() = default;

	protected:
	virtual uint32_t DoRand() override;
};

#endif /* TLIGHTSTATICRANDOM_H_ */
