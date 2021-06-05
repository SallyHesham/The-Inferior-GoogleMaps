#include "math.h"
#include "head.h"
int distanceMarkIII(int x, int y) {
	if (firstPoint == 0) {
		PX = x;
		PY = y;
		firstPoint = 1;
		totalDist = 0;
	}
	else {
		//double xdif = x-PX;
		//double ydif = y-PY;
		//dist = (xdif*xdif + ydif*ydif);
		dist = sqrt(pow((x - PX), 2) + pow((y - PY), 2));
		totalDist += dist;
		PX = x;
		PY = y;
	}
	return totalDist;
}
