#ifndef SMAP_ELEMENT_H
#define SMAP_ELEMENT_H

#include <vector>
#include "SMapPoint.h"

class IEntity;
struct SMapElement {
	public:
	SMapElement()=default;
	virtual ~SMapElement()=default;

	public:
	const SMapPoint& Location();
	void SetLocation(std::shared_ptr<SMapPoint> a);
	void SetLocation(int xInput, int yInput, int zInput, int wInput = 0);

	public:
	//Coordinates from Entity(SMapPoint) should be translated to SMapElement
	std::vector<std::shared_ptr<IEntity>> m_vObjects;

	protected:
	SMapPoint m_xLocation;
};

#endif //SMAP_ELEMENT_H