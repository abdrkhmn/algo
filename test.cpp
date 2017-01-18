#include "heap.cpp"
#include <iostream>
using namespace std;

Heap<int>* h;

int main(){
	h = new Heap<int>(100);

	h->add(1);
	h->add(2);
	h->add(3);
	h->add(4);
	h->add(5);

	
	while(h->size() > 1){
		cout << h->pop() << endl;
	}	
	return 0;
}