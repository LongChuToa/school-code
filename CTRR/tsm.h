#ifndef _TSM_
#define _TSM_

#include <string.h>
#include <iostream>
#include <math.h>
#include <string>	

using namespace std;

class TSP {
private:
	int way[20] = {}, best_way[20] = {};
	int pass[20] = {};
	int weight = 0, max_weight = -1, min = -1;
	int s, num_vertices;
	string result = "";
public:
	TSP(int graph[][20], int num_vertices, char start_vertex);
	void run(int graph[][20], int num);
	string return_result();
};

string Traveling(int graph[][20], int num_vertices, char start);

#endif