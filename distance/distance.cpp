#include <stdio.h>
#include <iostream>
using namespace std;

float distance(float x, float y)
{
	float dist[2][2];
	dist[1][0] = x;
	dist[1][1] = y;
	float the_distance, total_distance = 0;
	//if(time == 0){
	//{
	//	the_distance = 0;
	//	total_distance += the_distance;
	//	dist[0][0] = dist[1][0];
	//	dist[0][1] = dist[1][1];
	//}
	//else
	//{
	the_distance = sqrt(pow(dist[1][0] - dist[0][0], 2) + pow(dist[1][1] - dist[0][1], 2));
	total_distance += the_distance;
	dist[0][0] = dist[1][0];
	dist[0][1] = dist[1][1];
	//}
	cout << " total_distance = " << total_distance;
	return total_distance;

}
int main()
{

	distance(2, 3);

}