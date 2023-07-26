#ifndef SMAP_POINT_H
#define SMAP_POINT_H

#include <vector>
#include <memory>

struct SMapPoint {
	public:
	SMapPoint(int xCoord=0, int yCoord = 0, int zCoord=0, int wCoord = 0) {
		x=xCoord;
		y=yCoord;
		z=zCoord;
		w=wCoord;
	};
	virtual ~SMapPoint()=default;

	void operator= (const SMapPoint& a);
	

	public:
	int x;
	int y;
	int z;
	int w;
};

SMapPoint operator-(const SMapPoint& a, const SMapPoint& b);
bool operator== (const SMapPoint& a, const SMapPoint& b);
bool operator!= (const SMapPoint& a, const SMapPoint& b);

#endif //SMAP_POINT_H
