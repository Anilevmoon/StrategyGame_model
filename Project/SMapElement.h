#pragma once
#include "SMapPoint.h"


struct SMapElement : public SMapPoint {
	public:
	SMapElement()=default;
	virtual ~SMapElement()=default;

	public:
	//Coordinates from Entity(SMapPoint) should be translated to SMapElement
	std::vector<std::shared_ptr<TObject>> m_vObjects;
};