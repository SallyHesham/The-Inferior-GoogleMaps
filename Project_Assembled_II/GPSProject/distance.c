#include "head.h"
#include <stdio.h>
#include <math.h>

double distanceNew(double lat,double lon)
{
	double dist[2][2];
	int R = 6371 * 1000; //Radius of Earth in meter
	double PI = 3.141592653589793;
	double lat_rad = lat * PI / 180;
	double lon_rad = lon * PI / 180;
	dist[1][0] = lat_rad;
	dist[1][1] = lon_rad;
	//dist[0][0] = 38.898556 * PI / 180; to test.
	//dist[0][1] = -77.037852 * PI / 180; to test.
	double difference_lat = (dist[1][0] - dist[0][0]);
	double difference_lon = (dist[1][1] - dist[0][1]);
	double lat1 = dist[0][0];
	double lon1 = dist[0][1];
	double lat2 = dist[1][0];
	double lon2 = dist[1][1];
	double a = sin(difference_lat / 2) * sin(difference_lat / 2) + cos(lat1) * cos(lat2) *
		sin(difference_lon / 2) * sin(difference_lon / 2);
	double c = 2 * asin(sqrt(a));
	double distance = R * c;
	double total_distance = 0;
	//if(time == 0){
	//{
	//	distance = 0;
	//	total_distance += the_distance;
	//	dist[0][0] = dist[1][0];
	//	dist[0][1] = dist[1][1];
	//}
	//else
	//{
	total_distance += distance;
	dist[0][0] = dist[1][0];
	dist[0][1] = dist[1][1];
	//}
	
	return total_distance;

}
