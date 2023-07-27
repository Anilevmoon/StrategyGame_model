#include "SMapElement.h"

const SMapPoint& SMapElement::Location() {
	return m_xLocation;
}

void SMapElement::SetLocation(std::shared_ptr<SMapPoint> a) {
	m_xLocation = *a;
}

void SMapElement::SetLocation(int xInput, int yInput, int zInput, int wInput) {
	m_xLocation = SMapPoint{xInput, yInput, zInput, wInput};
}
