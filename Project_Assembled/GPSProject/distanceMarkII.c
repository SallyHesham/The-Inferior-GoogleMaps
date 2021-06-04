#include <stdio.h>
#include <math.h>
#include "head.h"

double PX = 0;
double PY = 0;
int firstPoint = 0;
double totalDist = 0;
double dist = 0;

double distanceMarkII(double x, double y) {
	if (firstPoint == 0) {
		PX = x;
		PY = y;
		firstPoint = 1;
	}
	else {
		
		dist = sqrt(pow((x - PX), 2) + pow((y - PY), 2));
		totalDist += dist;
		PX = x;
		PY = y;
	}
	return totalDist;
}
