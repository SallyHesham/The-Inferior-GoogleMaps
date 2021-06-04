#include <stdio.h>
#include <math.h>
#include "head.h"

static float PX = 0;
static float PY = 0;
static int firstPoint = 0;
static float totalDist = 0;

float distanceMarkII(float x, float y){
	if (firstPoint == 0){
		PX = x;
		PY = y;
		firstPoint = 1;
	}else{
		float dist = sqrt(pow(x-PX,2) + pow(y-PY,2));
		totalDist += dist;
		PX = x;
		PY = y;
	}
	return totalDist;
}
