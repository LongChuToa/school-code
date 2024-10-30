#include "bellman.h"
#include "tsm.h"

int main() {
	//Declare variable
	int graph[20][20] = { {} };
	int n;
	char start , goal ;

	//Running BF()
	cout << "Nhap so dinh: ";
	cin >> n;
	int value_arr[20] = {};
	int prev_arr[20] = {};
	cout << "Nhap ma tran:\n";
	for (int i = 0; i < n; i++) {
		value_arr[i] = -1;
		prev_arr[i] = -1;
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	cout << "Nhap dinh bat dau: "; cin >> start;
	for (int i = 0; i < n; i++) {
		BF(graph, n, start, value_arr, prev_arr);
		cout << "Step " << i + 1 << " :\n";
		cout << "Value array: ";
		for (int j = 0; j < n; j++) {
			cout << value_arr[j] << " ";
		}
		cout << endl;
		cout << "Prev array: ";
		for (int j = 0; j < n; j++) {
			cout << prev_arr[j] << " ";
		}
		cout << endl;
	}

	//Run BF_Path()
	cout << "Nhap so dinh: ";
	cin >> n;
	cout << "Nhap dinh bat dau: ";
	cin >> start;
	cout << "Nhap dinh ket thuc: ";
	cin >> goal;
	cout << "Nhap ma tran:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	cout << BF_Path(graph, n, start, goal) << endl;

	//Run TSP
	cout << "Nhap so dinh: ";
	cin >> n;
	cout << "Nhap dinh bat dau: ";
	cin >> start;
	cout << "Nhap ma tran:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	string output = Traveling(graph, n, start);
	cout << output;

	return 0;
}