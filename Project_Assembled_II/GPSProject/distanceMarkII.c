#include "math.h"
#include "head.h"


float distanceMarkII(float x, float y) {
	if (firstPoint == 0) {
		PX = x;
		PY = y;
		firstPoint = 1;
		totalDist = 0;
	}
	else {
		float xdif = x-PX;
		float ydif = y-PY;
		dist = (xdif*xdif + ydif*ydif);
		//dist = sqrt(pow((x - PX), 2) + pow((y - PY), 2));
		totalDist += dist;
		PX = x;
		PY = y;
	}
	return totalDist;
}
