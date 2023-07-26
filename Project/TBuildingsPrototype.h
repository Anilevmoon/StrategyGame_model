#ifndef TBUILDINGS_PROTOTYPE_H
#define TBUILDINGS_PROTOTYPE_H

#include <WorldWideComp/TObject.h>
#include <MapParts/TMap.h>
#include <Prototypes/TBuffPrototype.h>

class TBuildingsPrototype :public TObject {
	public:
	TBuildingsPrototype()=default;

	void SetBuildingsPrototype(NEntityType type);

	public:
	float m_fHealth = 0.f;
	std::vector<std::shared_ptr<SMapPoint>> m_vBuildPoints;
	void SetCoordinates(std::vector<SMapPoint> cache);

	public:
	std::vector<std::shared_ptr<TBuffPrototype>> m_vBuffPrototypesContainer;
};

#endif // TBUILDINGS_PROTOTYPE_H