#include "SMapPoint.h"

bool operator==(const SMapPoint& a, const SMapPoint& b) { return (a.w==b.w&&a.x==b.x&&a.y==b.y&&a.z==b.z); }

bool operator!=(const SMapPoint& a, const SMapPoint& b) { return !(a==b); }

SMapPoint operator-(const SMapPoint& a, const SMapPoint& b) { return SMapPoint(a.x-b.x, a.y-b.y, a.z-b.z, a.w-b.w); }

bool operator<(const SMapPoint& a, const SMapPoint& b) { return (a.w<b.w||a.x<b.x||a.y<b.y||a.z<b.z); }

void SMapPoint::operator=(const SMapPoint& a) {
	x = a.x;
	y = a.y;
	z = a.z;
	w = a.w;
}

SMapPoint SMapPoint::operator+(const SMapPoint& p) const { return SMapPoint(x+p.x, y+p.y, z+p.z, w+p.w); }

const int& SMapPoint::operator[](unsigned idx) const { return ((int*)this)[idx]; }
int& SMapPoint::operator[](unsigned idx) { return ((int*)this)[idx]; }
