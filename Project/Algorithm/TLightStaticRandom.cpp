#include "TLightStaticRandom.h"


uint32_t TLightStaticRandom::DoRand() {
	 uint32_t hi, lo, x;
	 if(Seed==0) Seed = 123459876;
	 hi = Seed / 127773;
	 lo = Seed % 127773;
	 x = 16807 * lo - 2836 * hi;
	 if(x < 0) x += 0x7fffffff;
	 return ((Seed = x) % (RandMax() + 1));
}
