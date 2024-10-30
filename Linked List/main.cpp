#include "main.h"

int main() {
	Linked_List ll1 = Linked_List(10);
	Linked_List ll2 = Linked_List(5);
	for (int i = 0; i < 8; i++) {
		ll1.insert();

	}
	ll1.print();
	ll1.insert(8);
	ll1.search(3);
	ll1.insert(4);
	ll1.remove(5);
	ll1.insert(12);
	ll1.print();
	ll1.clear();
	ll1.print();
	
}