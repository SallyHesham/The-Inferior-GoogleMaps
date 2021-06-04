#include <stdio.h>
#include <math.h>
#include "head.h"

static double PX = 0;
static double PY = 0;
static int firstPoint = 0;
static double totalDist = 0;
static double dist = 0;

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
