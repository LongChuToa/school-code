#ifndef MAIN
#define MAIN

#include <iostream>
#include <string>
using namespace std;

class Info {
public:
	int id;
	string data = "";

	Info(int id): id(id) {
		cout << "Write a data for a node: ";
		cin >> this->data;
	}

	void print_info() const {
		cout << "ID: " << id << "  Data: " << data << endl;
	}
};

class Node {
public:
	Info* info;
	Node* tail;

	Node(int id) {
		this->info = new Info(id);
		tail = nullptr;
	}

	~Node()
	{
		delete info;
		info = nullptr;
	}
};

class Linked_List {
private:
	Node* head;
	int size, max_size = -1, cur_id = 0;
public:
	//Construct a empty linkedlist
	Linked_List() : size(0) {
		head = nullptr;
		cout << "A new empty linked list has been created.\n";
	}

	//Construct a n-size linkedlist
	Linked_List(int size) : size(0), max_size(size) {
		head = nullptr;
		cout << "A new linked list with max size = " << max_size << " has been created.\n";
	}

	bool IsEmpty() const {
		return (size < max_size) || (max_size == -1);
	}

	bool IsFull() const {
		return size == max_size;
	}

	//Clear a list
	void clear() {
		for (int i = size; i > 0; i--) {
			Node* temp_node = traverse(i);
			delete temp_node;
			temp_node = nullptr;
		}
		delete head;
		head = nullptr;
		size = 0;
		cout << "The list is clear.\n";
	}


	//Traverse a list
	Node* traverse(int id) {
		Node* returnNode = head;
		for (int i = 0; i < id; i++) {
			returnNode = returnNode->tail;
		}
		return returnNode;
	}

	//Insert a node a normal way
	void insert() {
		if (!IsFull() || IsEmpty()) {
			Node* temp_head = new Node(size);
			if (head == nullptr) {
				head = temp_head;
			}
			else {
				Node* temp_tail = traverse(size - 1);
				temp_tail->tail = temp_head;
			}
			size++;
			cur_id++;
			return;
		}
		cout << "The list is full.\n";
	}

	//Insert a node from nowhere to a position
	void insert(int id) {
		if ((id < 1) || (id >= size)) {
			cout << "Insert has error.\n";
			return;
		}
		if (!IsFull() || IsEmpty()) {
			Node* temp_head = new Node(cur_id);
			Node* temp_tail = traverse(id - 1);
			temp_head->tail = temp_tail->tail;
			temp_tail->tail = temp_head;
			size++;
			cur_id++;
		}
	}

	//Remove node from anywhere (with an position)
	void remove(int id) {
		if ((id < 1) || (id >= size)) {
			cout << "Remove has error.\n";
			return;
		}
		Node* temp_del = traverse(id);
		Node* temp_node = traverse(id - 1);
		Node* temp_tail = temp_del->tail;
		temp_node->tail = temp_tail;
		temp_del->tail = nullptr;
		delete temp_del;
		temp_del = nullptr;
		size--;
		return;
	}

	//Search node (with an position)
	void search(int id) {
		if ((id < 1) || (id >= size)) {
			cout << "Search has error.\n";
			return;
		}
		Node* temp_node = traverse(id);
		temp_node->info->print_info();
	}

	//Print node
	void print() {
		if (size == 0) {
			cout << "List is empty.\n";
			return;
		}
		else {
			Node* temp_node = head;
			for (int i = 0; i < size; i++) {
				temp_node->info->print_info();
				temp_node = temp_node->tail;
			}
		}
	}

	~Linked_List()
	{
		for (int i = size; i > 0; i--) {
			Node* temp_node = traverse(i);
			delete temp_node;
			temp_node = nullptr;
		}
		cout << "Destroy the list. Done!!!\n";
	}
};



#endif MAIN