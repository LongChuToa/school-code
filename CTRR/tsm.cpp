#include "tsm.h"



TSP::TSP(int graph[][20], int num_vertices, char start_vertex) {
	this->num_vertices = num_vertices;
	s = start_vertex - 65;
	for (int i = 0; i < num_vertices; i++) {
		pass[i] = 0;
		for (int j = 0; j < num_vertices; j++) {
			if ((i != j) && (graph[i][j] != 0)) {
				if ((graph[i][j] < min) || (min == -1)) {
					min = graph[i][j];
				}
			}
		}
	}
	pass[s] = 1;
	way[0] = s;
}

void TSP::run(int graph[][20], int num) {

	//Branch&Bound loop
	if (num != num_vertices -1) {
		for (int i = 0; i < num_vertices; i++) {
			//If the vertex is not passing by and not have weight
			if ((pass[i] != 1) && (graph[way[num]][i] != 0)) {
				way[num + 1] = i;
				pass[i] = 1;
				weight += graph[way[num]][way[num + 1]];
				if ((max_weight == -1) || (weight + (num_vertices - num + 1) * min < max_weight)) {
					//Repeat till num == num_veritices + 1
					run(graph, num + 1);
				}
				pass[i] = 0;
				//Reduce weight to compare if there are a path that better
				weight -= graph[way[num]][way[num + 1]];
			}
		}
	}
	else {
		//After num == num_vertices, we declare max_weight for compare and best way
		if (graph[way[num]][s] != 0) {
			if ((weight + graph[way[num]][s] < max_weight) || (max_weight == -1)) {
				max_weight = weight + graph[way[num]][s];
				for (int i = 0; i < num_vertices; i++) {
					best_way[i] = way[i];
				}
			}
		}
		return;
	}
}

string TSP::return_result() {
	for (int i = 0; i < num_vertices; i++) {
		string str;
		str = char(best_way[i] + 65);
		result += str + " ";
	}
	string str;
	str = char(s + 65);
	result = result + str;
	return result;
}

string Traveling(int graph[][20], int num_vertices, char start)
{
	TSP* salesman = new TSP(graph, num_vertices, start);
	salesman->run(graph, 0);
	return salesman->return_result();
}