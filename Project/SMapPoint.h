#pragma once
#include <vector>
#include <memory>
#include "TObject.h"
struct SMapPoint {
	public:
	SMapPoint() {};
	SMapPoint(int xCoord, int yCoord, int zCoord, int wCoord = 0) {
		x=xCoord;
		y=yCoord;
		z=zCoord;
		w=wCoord;
	};
	virtual ~SMapPoint()=default;

	public:
	int x = 0;
	int y = 0;
	int z = 0;
	int w = 0;
};

