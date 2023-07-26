#ifndef TMAP_PROTOTYPE_H
#define TMAP_PROTOTYPE_H

#include <Prototypes/TUnitPrototype.h>

class TMapPrototype : public TObject {
	public:
	TMapPrototype()=default;
	virtual ~TMapPrototype()=default;

	public:
	std::vector<std::shared_ptr<TUnitPrototype>> m_vUnitPrototypesToMapContainer;
};

#endif //TMAP_PROTOTYPE_H