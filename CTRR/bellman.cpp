#include "bellman.h"

void BF(int graph[][20], int num_vertices, char start_vertex, int(&value_arr)[20], int(&prev_arr)[20])
{
	int s = start_vertex - 65;
	int next_value[20] = {};
	for (int i = 0; i < num_vertices; i++) {
		next_value[i] = 0;
	}
	if (value_arr[s] == -1) {
		value_arr[s] = 0;
	}
	for (int i = 0; i < num_vertices; i++) {
		if (value_arr[i] != -1) {
			for (int j = 0; j < num_vertices; j++) {
				if (graph[i][j] == 0) continue;
				if (value_arr[i] + graph[i][j] < value_arr[j] || value_arr[j] == -1) {
					if ((next_value[j] == 0) || (value_arr[i] + graph[i][j] < next_value[j])) {
						next_value[j] = value_arr[i] + graph[i][j];
						prev_arr[j] = i;
					}
				}
			}
		}
	}
	for (int i = 0; i < num_vertices; i++) {
		if (next_value[i] != 0) value_arr[i] = next_value[i];
		next_value[i] = 0;
	}
}

string BF_Path(int graph[][20], int num_vertices, char start, char goal)
{
	string result = "";
	int s = start - 65, g = goal - 65;
	int moving = g;
	if (s == g) {
		result += start;
		return result;
	}
	int value_arr[20] = {};
	int prev_arr[20] = {};
	int next_value[20] = {};
	for (int i = 0; i < num_vertices; i++) {
		value_arr[i] = -1;
		prev_arr[i] = -1;
		next_value[i] = 0;
	}
	if (value_arr[s] == -1) {
		value_arr[s] = 0;
	}
	for (int n = 0; n < num_vertices - 1; n++) {
		for (int i = 0; i < num_vertices; i++) {
			if (value_arr[i] != -1) {
				for (int j = 0; j < num_vertices; j++) {
					if (graph[i][j] == 0) continue;
					if (value_arr[i] + graph[i][j] < value_arr[j] || value_arr[j] == -1) {
						if ((next_value[j] == 0) || (value_arr[i] + graph[i][j] < next_value[j])) {
							next_value[j] = value_arr[i] + graph[i][j];
							prev_arr[j] = i;
						}
					}
				}
			}
		}
		for (int i = 0; i < num_vertices; i++) {
			if (next_value[i] != 0) value_arr[i] = next_value[i];
			next_value[i] = 0;
		}
	}
	while (moving != -1) {
		string str;
		str = char(moving + 65);
		result = str + " " + result;
		moving = prev_arr[moving];
	}

	return result;
}