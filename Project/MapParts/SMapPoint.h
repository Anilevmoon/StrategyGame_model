#ifndef SMAP_POINT_H
#define SMAP_POINT_H

#include <memory>

#include <WorldComponents/TObject.h>

struct SMapPoint {
	public:
	SMapPoint(int xCoord=0, int yCoord = 0, int zCoord=0, int wCoord = 0);

	void operator= (const SMapPoint& a);
	SMapPoint operator+(const SMapPoint& p) const;

	const int& operator[](unsigned idx) const;
	int& operator[](unsigned idx);

	public:
	int x = 0;
	int y = 0;
	int z = 0;
	int w = 0;
};
//SMapPoint operator+(const SMapPoint& p) { return SMapPoint(x+p.x, y+p.y); }

SMapPoint operator-(const SMapPoint& a, const SMapPoint& b);
bool operator== (const SMapPoint& a, const SMapPoint& b);
bool operator< (const SMapPoint& a, const SMapPoint& b);
bool operator!= (const SMapPoint& a, const SMapPoint& b);
//SMapPoint operator+(const SMapPoint& a, const SMapPoint& b);

#endif //SMAP_POINT_H
