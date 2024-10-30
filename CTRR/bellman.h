#ifndef _BELLMAN_
#define _BELLMAN_

#include <string.h>
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void BF(int graph[][20], int num_vertices, char start_vertex, int(&value_arr)[20], int(&prev_arr)[20]);

string BF_Path(int graph[][20], int num_vertices, char start, char goal);

#endif