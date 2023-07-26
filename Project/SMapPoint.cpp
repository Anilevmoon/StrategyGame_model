#include "SMapPoint.h"

bool operator==(const SMapPoint& a, const SMapPoint& b) { return (a.w==b.w&&a.x==b.x&&a.y==b.y&&a.z==b.z); }

bool operator!=(const SMapPoint& a, const SMapPoint& b) { return !(a==b); }

SMapPoint operator-(const SMapPoint& a, const SMapPoint& b) { return SMapPoint(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w); }

void SMapPoint::operator=(const SMapPoint& a) {
	x = a.x;
	y = a.y;
	z = a.z;
	w = a.w;
}
