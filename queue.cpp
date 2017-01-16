

#ifndef QUEUE_DEF
#define QUEUE_DEF

#include <cstdlib>

template<class T>
struct Node{
	Node* next;
	T value;

	Node(T v){
		value = v;
		next = NULL;
	}
};

template<class T>
class Queue{
private:
	Node<T>* first = NULL;
	Node<T>* last = NULL;
	size_t asize = 0;
public:
	T pop(){
		Node<T> *ret = first;
		first = first->next;
		asize--;
		return ret->value;
	}

	T front(){
		return first->value;
	}

	void add(T elem){
		if(first == NULL){
			first = new Node<T>(elem);
			last = first;
			return;
		}
		asize++;
		
		last->next = new Node<T>(elem);
		last = last->next;
	}

	size_t size(){
		return asize;
	};
};



#endif